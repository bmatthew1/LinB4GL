//---------------------------------------------------------------------------


#pragma hdrstop

#include "PluginDLL.h"
#include "streaming.h"
#include <windows.h>

using namespace std;

//---------------------------------------------------------------------------

#pragma package(smart_init)

////////////////////////////////////////////////////////////////////////////////
//  Helper functions
bool LoadFileDetails(HINSTANCE dll, PluginDLLFile &details) {
    assert(dll != NULL);

    // Find query function
    DLL_Basic4GL_QueryFunction query = (DLL_Basic4GL_QueryFunction) GetProcAddress(dll, "Basic4GL_Query");
    if (query == NULL)
        return false;

    // Query the DLL for details
    char detailStr[256];
    memset(detailStr, 0, 256);
    details.version.major = 0;
    details.version.minor = 0;
    int version = query(detailStr, &details.version.major, &details.version.minor);
    details.description = detailStr;

    // Note: Calling code must calculate details.filename and details.loaded itself
    return version == BASIC4GL_DLL_VERSION;
}

vmBasicValType ValTypeFromDLLTypeCode(DLL_Basic4GL_TypeCode typeCode) {
    switch (typeCode) {
        case DLL_BASIC4GL_INT:      return VTP_INT;
        case DLL_BASIC4GL_FLOAT:    return VTP_REAL;
        case DLL_BASIC4GL_STRING:   return VTP_STRING;
        default:                    return VTP_UNDEFINED;
    }
}

////////////////////////////////////////////////////////////////////////////////
//  PluginDLLObjectStore
//
/// A resource store for plugin DLLs

class PluginDLLObjectStore : public IDLL_Basic4GL_ObjectStore {
private:
    vmStore<void*> store;
    IDLL_Basic4GL_ObjectStoreCallback *callback;

    void DeleteObject(int handle);
public:
    PluginDLLObjectStore(IDLL_Basic4GL_ObjectStoreCallback *_callback)
        :   store(NULL),
            callback(_callback) {;}

    // IDLL_Basic4GL_ObjectStore methods
    virtual int DLLFUNC Add(void *object);
    virtual void DLLFUNC Remove(int handle);
    virtual bool DLLFUNC HandleIsValid(int handle);
    virtual void *DLLFUNC Object(int handle);
    virtual void Clear();
};

////////////////////////////////////////////////////////////////////////////////
//  PluginDLL
PluginDLL::PluginDLL(PluginDLLManager &_manager, std::string path, std::string _filename, bool isStandaloneExe)
    : manager(_manager), currentStructure(NULL)
{
    // Save filename
    filename = LowerCase(_filename);

    // Set defaults
    handle          = NULL;
    plugin          = NULL;
    failed          = true;
    definingFunc    = false;

    // Load DLL
    handle = (int) LoadLibrary((path + filename).c_str());
    if (handle == NULL)
        return;

    // Query file details
    fileDetails.filename = filename;
    fileDetails.loaded = true;
    fileDetails.isExternal = true;
    if (!LoadFileDetails((HINSTANCE) handle, fileDetails))
        return;

    // Find Init function
    DLL_Basic4GL_InitFunction init = (DLL_Basic4GL_InitFunction) GetProcAddress((HINSTANCE) handle, "Basic4GL_Init");
    if (init == NULL)
        return;

    // Call init function to get plugin interface
    plugin = init();
    if (plugin == NULL)
        return;

    // Inform plugin it has been loaded. Let it register its functions.
    if (!plugin->Load(*this, isStandaloneExe))
        return;
    CompleteFunction();

    // DLL successfully initialised
    failed = false;
}

PluginDLL::PluginDLL(PluginDLLManager &_manager, std::string name, IDLL_Basic4GL_Plugin* _plugin, bool isStandaloneExe)
    : manager(_manager), currentStructure(NULL), plugin(_plugin)
{
    // Save name
    filename = name;

    // Set defaults
    handle          = NULL;
    failed          = true;
    definingFunc    = false;

    // Set default file details
    fileDetails.filename = filename;
    fileDetails.loaded = true;
    fileDetails.isExternal = false;
    fileDetails.description = "Built in library";
    fileDetails.version = PluginVersion();

    // Inform plugin it has been loaded. Let it register its functions.
    if (!plugin->Load(*this, isStandaloneExe))
        return;
    CompleteFunction();

    // DLL successfully initialised
    failed = false;
}

PluginDLL::~PluginDLL() {

    // Clear object stores
    ClearObjectStores();

    // Clear structures
    manager.StructureManager().RemoveOwnedStructures(this);

    // Unload plugin
    if (plugin != NULL)
        plugin->Unload();

    // Unload DLL
    if (handle != NULL)
        FreeLibrary((HINSTANCE) handle);

    // Delete object stores
    for (int i = 0; i < objectStores.size(); i++)
        delete objectStores[i];
}

std::string PluginDLL::Error() {

/*    if (!failed)
        return "";

    else*/ if (handle == NULL)
        return "Could not load plugin DLL: " + filename;

    else if (plugin == NULL)
        return "Could not initialise plugin: " + filename;

    else {

        // Query plugin for error text
        // We must allocate and pass our own buffer
        char buffer[1024];
        memset(buffer, 0, 1024);
        plugin->GetError(buffer);
        return (std::string) buffer;
    }
}

void PluginDLL::CompleteFunction() {
    if (!definingFunc)
        return;

    // Fix up return and parameter types
    if (currentSpec.m_isFunction)
        FixType(currentSpec.m_returnType);
    for (   vmValTypeList::iterator i = currentSpec.m_paramTypes.Params().begin();
            i != currentSpec.m_paramTypes.Params().end();
            i++)
        FixType(*i);

    // Finish off the current function

    // Store pointer and specification
    currentSpec.m_index = functions.size();
    functions.push_back(currentFunc);
    pluginFunctionSpecs.push_back(currentSpec);

    // Add name->index mapping
    functionLookup.insert(std::make_pair(currentName, currentSpec.m_index));

    definingFunc = false;
}

void PluginDLL::NewFunction(std::string name, DLL_Basic4GL_Function function) {

    // Complete any partially defined function
    CompleteFunction();

    // Save function info
    currentName = LowerCase(name);
    currentFunc = function;

    // Set function defaults
    currentSpec.m_paramTypes.Params().clear();
    currentSpec.m_brackets      = true;
    currentSpec.m_isFunction    = false;
    currentSpec.m_returnType    = VTP_INT;
    currentSpec.m_timeshare     = false;
    currentSpec.m_index         = 0;
    currentSpec.m_freeTempData  = false;

    definingFunc = true;
}

void DLLFUNC PluginDLL::RegisterVoidFunction(
    const char *name,
    DLL_Basic4GL_Function function) {

    // Create new void function
    NewFunction(name, function);
}

void DLLFUNC PluginDLL::RegisterFunction(
    const char *name,
    DLL_Basic4GL_Function function,
    DLL_Basic4GL_TypeCode typeCode) {

    // Create new function
    NewFunction(name, function);

    // Set return type
    currentSpec.m_isFunction = true;
    currentSpec.m_returnType = ValTypeFromDLLTypeCode(typeCode);
}

void DLLFUNC PluginDLL::RegisterArrayFunction(
    const char *name,
    DLL_Basic4GL_Function function,
    DLL_Basic4GL_TypeCode typeCode,
    int dimensions) {

    // Create new function
    NewFunction(name, function);

    // Set return type
    currentSpec.m_isFunction = true;
    currentSpec.m_returnType = vmValType(ValTypeFromDLLTypeCode(typeCode), dimensions, 1, true);
    currentSpec.m_freeTempData = true;
}

void DLLFUNC PluginDLL::ModNoBrackets() {
    // Note: Basic4GL parsing doesn't handle functions with no parameters properly.
    // Therefore we only set no-brackets if the function is void.
    if (!currentSpec.m_isFunction)
        currentSpec.m_brackets = false;
}

void DLLFUNC PluginDLL::ModTimeshare() {
    currentSpec.m_timeshare = true;
}

void DLLFUNC PluginDLL::AddParam(DLL_Basic4GL_TypeCode typeCode) {
    currentSpec.m_paramTypes << ValTypeFromDLLTypeCode(typeCode);
}

void DLLFUNC PluginDLL::AddArrayParam(
    DLL_Basic4GL_TypeCode typeCode,
    int dimensions) {
    currentSpec.m_paramTypes << vmValType(ValTypeFromDLLTypeCode(typeCode), dimensions, 1, true);
}

void DLLFUNC PluginDLL::AddStrucParam(int handle) {
    currentSpec.m_paramTypes << vmValType((vmBasicValType) handle);
}

void PluginDLL::FindFunctions(
    std::string& name,
    compExtFuncSpec *functions,
    int& count,
    int max,
    int pluginIndex) {

    // Find matching functions
    for (
        std::multimap<std::string,int>::const_iterator i = functionLookup.find(name);
        i != functionLookup.end() && i->first == name && count < max;
        i++) {

        // Append entry to array
        if (vmFunctionSpecs.size() > i->second) {
            compFuncSpec *spec              = &vmFunctionSpecs[i->second];
            functions[count].m_spec         = spec;
            functions[count].m_builtin      = false;
            functions[count].m_pluginIndex  = pluginIndex;
            count++;
        }
    }
}

void DLLFUNC PluginDLL::RegisterInterface(
    void *object,
    const char *name,
    int major,
    int minor) {
    manager.RegisterInterface(object, name, major, minor, this);
}

void *DLLFUNC PluginDLL::FetchInterface(
    const char *name,
    int major,
    int minor) {
    return manager.FetchInterface(name, major, minor, this);
}

void PluginDLL::AddReferencingDLL(PluginDLL *dll) {

    // (Ignore self-references)
    if (dll != this)
        referencingDLLs.insert(dll);
}

void PluginDLL::RemoveReferencingDLL(PluginDLL *dll) {
    referencingDLLs.erase(dll);
}

std::string PluginDLL::DescribeReferencingDLLs() const {

    // Build a comma separated list of plugin DLLs which reference this one
    std::string result = "";
    for (
        std::set<PluginDLL*>::const_iterator i = referencingDLLs.begin();
        i != referencingDLLs.end();
        i++) {
        if (i != referencingDLLs.begin())
            result += ", ";
        result += (*i)->fileDetails.filename;
    }
    return result;
}

std::string PluginDLL::FunctionName(int index) {
    for (
        std::multimap<std::string,int>::iterator i = functionLookup.begin();
        i != functionLookup.end();
        i++)
        if ((*i).second == index)
            return (*i).first;

    return "???";
}

void DLLFUNC PluginDLL::RegisterStringConstant(
    const char *name,
    const char *value) {
    constants[LowerCase((string) name)] = compConstant((string) "S" + value);
}
void DLLFUNC PluginDLL::RegisterIntConstant(
    const char *name,
    int value) {
    constants[LowerCase((string) name)] = compConstant(value);
}
void DLLFUNC PluginDLL::RegisterFloatConstant(
    const char *name,
    float value) {
    constants[LowerCase((string) name)] = compConstant(value);
}

IDLL_Basic4GL_ObjectStore *DLLFUNC PluginDLL::CreateObjectStore(IDLL_Basic4GL_ObjectStoreCallback *callback) {

    // Create object store
    IDLL_Basic4GL_ObjectStore *store = new PluginDLLObjectStore(callback);

    // Register it
    objectStores.push_back(store);

    return store;
}

bool PluginDLL::FindConstant(std::string name, compConstantMap::const_iterator& i) {
    i = constants.find(name);
    return i != constants.end();
}

void PluginDLL::ClearObjectStores() {
    for (int i = 0; i < objectStores.size(); i++)
        objectStores[i]->Clear();
}

int DLLFUNC PluginDLL::RegisterStructure(
        const char *name, int versionMajor, int versionMinor) {

    // Structure with same name must not already be registered
    if (manager.StructureManager().FindStructure(name) != 0)
        return 0;

    // Create new structure
    currentStructure = new PluginStructure(this, name, versionMajor, versionMinor);

    // Register and retrieve handle
    return manager.StructureManager().Add(currentStructure);
}

void DLLFUNC PluginDLL::AddStrucPadding(int numBytes) {
    if (currentStructure != NULL)
        currentStructure->AddField(
            PluginStructureField("", PluginDataType::Padding(numBytes)));
}

void DLLFUNC PluginDLL::AddStrucField(const char *name, int type) {
    if (currentStructure != NULL)
        currentStructure->AddField(
            PluginStructureField(name, PluginDataType::SimpleType(type)));
}

void DLLFUNC PluginDLL::AddStrucStringField(const char *name, int size) {
    if (currentStructure != NULL)
        currentStructure->AddField(
            PluginStructureField(name, PluginDataType::String(size)));
}

void DLLFUNC PluginDLL::ModStrucFieldArray(int dimensions, int dimension1Size, ...) {

    // Find last defined field
    if (currentStructure != NULL && currentStructure->FieldCount() > 0) {
        PluginStructureField& field = currentStructure->GetField(currentStructure->FieldCount() - 1);

        // Convert data type to array
        PluginDataType& dataType = field.dataType;
        dataType.arrayLevel = dimensions;

        // Set array dimension sizes
        int *dimensionSize = &dimension1Size;
        for (int i = dimensions - 1; i >= 0; i--) {
            dataType.arrayDims[i] = *dimensionSize;
            dimensionSize++;
        }
    }
}

void DLLFUNC PluginDLL::ModStrucFieldPointer(int level) {
    // Find last defined field
    if (currentStructure != NULL && currentStructure->FieldCount() > 0) {
        PluginStructureField& field = currentStructure->GetField(currentStructure->FieldCount() - 1);

        // Convert data type to pointer
        field.dataType.pointerLevel = level;
    }
}

int DLLFUNC PluginDLL::FetchStructure(
        const char *name,
        int versionMajor,
        int versionMinor) {
    return manager.FetchStructure(name, versionMajor, versionMinor, this);
}

void PluginDLL::CreateVMFunctionSpecs() {

    // Create virtual machine version of each function definition.
    // These are basically identical to the plugin version, except that
    // plugin structure indices in each data type are replaced with the
    // corresponding virtual machine structure index.
    vmFunctionSpecs.clear();
    for (   vector<compFuncSpec>::iterator i = pluginFunctionSpecs.begin();
            i != pluginFunctionSpecs.end();
            i++) {

        // Create function spec (convert return type)
        compFuncSpec& src = *i;
        compFuncSpec dst(src);
        if (dst.m_isFunction)
            dst.m_returnType = manager.StructureManager().GetVMType(dst.m_returnType);

        // Convert parameter types
        dst.m_paramTypes.Params().clear();
        for (   vmValTypeList::iterator j = src.m_paramTypes.Params().begin();
                j != src.m_paramTypes.Params().end();
                j++)
            dst.m_paramTypes << manager.StructureManager().GetVMType(*j);
        vmFunctionSpecs.push_back(dst);
    }
}

void DLLFUNC PluginDLL::RegisterStructureFunction(
		const char *name,
		DLL_Basic4GL_Function function,
		int structureTypeHandle) {

    // Create new function
    NewFunction(name, function);

    // Set return type
    currentSpec.m_isFunction = true;
    currentSpec.m_freeTempData = true;
    currentSpec.m_returnType = vmValType((vmBasicValType) structureTypeHandle);
}

void DLLFUNC PluginDLL::ModReturnArray(int dimensions) {
    currentSpec.m_returnType.m_arrayLevel = dimensions;
    currentSpec.m_freeTempData = true;
}

void DLLFUNC PluginDLL::ModReturnPointer(int level) {
    currentSpec.m_returnType.m_pointerLevel = level;
}

void DLLFUNC PluginDLL::ModParamArray(int dimensions) {
    // Find last added param
    if (currentSpec.m_paramTypes.Params().size() > 0) {
        vmValType& param = currentSpec.m_paramTypes.Params().back();

        // Convert into array
        param.m_arrayLevel = dimensions;
    }
}

void DLLFUNC PluginDLL::ModParamPointer(int level) {
    // Find last added param
    if (currentSpec.m_paramTypes.Params().size() > 0) {
        vmValType& param = currentSpec.m_paramTypes.Params().back();

        // Convert into pointer
        param.m_pointerLevel = level;
    }
}

void DLLFUNC PluginDLL::ModParamReference() {
    // Find last added param
    if (currentSpec.m_paramTypes.Params().size() > 0) {
        vmValType& param = currentSpec.m_paramTypes.Params().back();

        // Convert into by-reference param
        if (!param.m_byRef) {
            param.m_byRef = true;
            param.m_pointerLevel++;
        }
    }
}

void PluginDLL::FixType(vmValType& type) {

    // Fix up a function return type or parameter type.
    // Convert arrays and structures to by-reference.
    if (type.m_pointerLevel == 0 &&
            (type.m_basicType >= 0 || type.m_arrayLevel > 0)) {
        type.m_pointerLevel = 1;
        type.m_byRef = true;
    }
}

////////////////////////////////////////////////////////////////////////////////
//  PluginDLLManager

PluginDLLManager::PluginDLLManager(std::string _directory, bool _isStandaloneExe)
    : directory(_directory), isStandaloneExe(_isStandaloneExe) {

    // Postfix a closing slash if necessary
    if (directory != "" && directory[directory.length() - 1] != '\\')
        directory += '\\';
}

PluginDLLManager::~PluginDLLManager() {
    Clear();
}

DLLFileVector PluginDLLManager::DLLFiles() {
    DLLFileVector result;

    // Scan directory for files
    std::string searchPath = directory + "*.dll";
    WIN32_FIND_DATA seekData;
    HANDLE seekHandle = FindFirstFile(searchPath.c_str(), &seekData);
    if (seekHandle == INVALID_HANDLE_VALUE)
        return result;

    // Scan DLL files in directory and add to list
    bool foundFile = true;
    while (foundFile) {

        // Open the DLL and query it for details
        HINSTANCE dll = LoadLibrary((directory + seekData.cFileName).c_str());
        if (dll != NULL) {

            // Query details from DLL
            PluginDLLFile details;
            details.filename = seekData.cFileName;
            details.loaded = IsLoaded(details.filename);
            if (LoadFileDetails(dll, details)) {

                // Add DLL file entries
                result.push_back(details);
            }

            // Unload the DLL
            FreeLibrary(dll);
        }

        // Find next DLL in directory
        foundFile = FindNextFile(seekHandle, &seekData);
    }

    // File search finished
    FindClose(seekHandle);

    return result;
}

DLLVector::iterator PluginDLLManager::FindItor(std::string filename) {

    // Search loaded DLLs for given filename
    std::string lcase = LowerCase(filename);
    DLLVector::iterator i;
    for(
        i = dlls.begin();
        i != dlls.end() && (*i)->Filename() != lcase;
        i++)
        ;

    return i;
}

PluginDLL *PluginDLLManager::Find(std::string filename) {

    // Find itor
    DLLVector::iterator i = FindItor(filename);

    // Return DLL
    return i == dlls.end() ? NULL : *i;
}

bool PluginDLLManager::LoadDLL(std::string filename) {

    // Attempt to load DLL
    // First check that it's not already loaded
    if (IsLoaded(filename)) {
        error = "A plugin DLL by this name is already loaded";
        return false;
    }

    // Load DLL
    PluginDLL *dll = new PluginDLL(*this, directory, filename, isStandaloneExe);
    if (dll->Failed()) {
        error = dll->Error();
        delete dll;
        return false;
    }

    // Add to list
    dlls.push_back(dll);

    return true;
}

bool PluginDLLManager::LoadLocalLibrary(IDLL_Basic4GL_Plugin* library, string name) {

    // Create object to manage local library
    PluginDLL *dll = new PluginDLL(*this, name, library, isStandaloneExe);
    if (dll->Failed()) {
        error = dll->Error();
        delete dll;
        return false;
    }

    // Add to list
    dlls.push_back(dll);

    return true;
}

bool PluginDLLManager::UnloadDLL(std::string filename) {

    // Find DLL
    DLLVector::iterator i = FindItor(filename);
    if (i == dlls.end()) {
        error = "This plugin DLL is not loaded";
        return false;
    }

    // Check that DLL can be unloaded.
    // If the DLL owns objects that are currently used by other DLLs, then it
    // cannot be unloaded before the other DLLs have been.
    if ((*i)->IsReferenced()) {
        error = (std::string) "The following plugin DLL(s) must be unloaded first:\r\n" + (*i)->DescribeReferencingDLLs();
        return false;
    }

    // Inform other DLLs that this one is being unloaded
    for (DLLVector::iterator j = dlls.begin(); j != dlls.end(); j++)
        if ((*i) != (*j))
            (*j)->RemoveReferencingDLL(*i);

    // Unregister all interfaces owned by this DLL
    std::map<std::string,PluginDLLSharedInterface>::iterator k = sharedInterfaces.begin();
    while (k != sharedInterfaces.end()) {
        std::map<std::string,PluginDLLSharedInterface>::iterator current = k;
        k++;
        if (current->second.owner == *i)
            sharedInterfaces.erase(current);
    }

    // Unload it
    delete *i;

    // Remove it from our list
    dlls.erase(i);

    return true;
}

void PluginDLLManager::Clear() {

    // Note: This only removes the external DLLs. Internal libraries are kept

    // Copy the list and clear the original
    DLLVector dllVector = dlls;
    dlls.clear();

    // Iterate each DLL
    for(    DLLVector::iterator i = dllVector.begin();
            i != dllVector.end();
            i++) {

        // Unload external DLLs
        if ((*i)->FileDetails().isExternal)
            delete (*i);

        // Copy internal libraries back to the DLL list
        else
            dlls.push_back(*i);
    }
}

bool PluginDLLManager::IsPluginFunction(std::string& name) const {

    // Look for matching function name
    for (
        DLLVector::const_iterator i = dlls.begin();
        i != dlls.end();
        i++)
        if ((*i)->IsFunction(name))
            return true;

    // (None found)
    return false;
}

void PluginDLLManager::FindFunctions(
    std::string& name,
    compExtFuncSpec *functions,
    int& count,
    int max) {

    // Pass call through to all loaded plugin dlls.
    for (int i = 0; i < dlls.size(); i++)
        dlls[i]->FindFunctions(name, functions, count, max, i);
}

bool PluginDLLManager::ProgramStart() {
    for (int i = 0; i < dlls.size(); i++) {
        // Attempt to start plugin
        if (!dlls[i]->Plugin()->Start()) {
            // Plugin failed!

            // Get error
            error = (string)"Error initialising plugin " + dlls[i]->Filename() + ": " + dlls[i]->Error();

            // Stop all plugins that have just been started
            for (int j = i - 1; j >= 0; j--)
                dlls[j]->Plugin()->End();

            // Abort program
            return false;
        }
    }

    // All plugins started successfully
    error = "";
    return true;
}

void PluginDLLManager::ProgramEnd() {
    for (int i = 0; i < dlls.size(); i++) {
        dlls[i]->ClearObjectStores();           // Also clear object stores.
        dlls[i]->Plugin()->End();
    }
}

void PluginDLLManager::ProgramPause() {
    for (int i = 0; i < dlls.size(); i++)
        dlls[i]->Plugin()->Pause();
}

void PluginDLLManager::ProgramResume() {
    for (int i = 0; i < dlls.size(); i++)
        dlls[i]->Plugin()->Resume();
}

void PluginDLLManager::ProgramDelayedResume() {
    for (int i = 0; i < dlls.size(); i++)
        dlls[i]->Plugin()->DelayedResume();
}

void PluginDLLManager::ProcessMessages() {
    for (int i = 0; i < dlls.size(); i++)
        dlls[i]->Plugin()->ProcessMessages();
}

void PluginDLLManager::RegisterInterface(
    void *intf,
    std::string name,
    int major,
    int minor,
    PluginDLL *owner) {

    // Construct unique string key
    std::string key         = SharedInterfaceKey(name, major, minor);

    // Save interface to key
    sharedInterfaces[key]   = PluginDLLSharedInterface(intf, owner);
}

void *PluginDLLManager::FetchInterface(
    std::string name,
    int major,
    int minor,
    PluginDLL *requester) {

    // Construct unique string key
    std::string key = SharedInterfaceKey(name, major, minor);

    // Fetch object
    std::map<std::string,PluginDLLSharedInterface>::const_iterator i = sharedInterfaces.find(key);
    if (i == sharedInterfaces.end())
        return NULL;

    // Add a dependency between the requester and the owner.
    if (requester != NULL && i->second.owner != NULL)
        i->second.owner->AddReferencingDLL(requester);

    // Return the interface
    return i->second.intf;
}

int PluginDLLManager::FetchStructure(
    std::string name,
    int major,
    int minor,
    PluginDLL *requester) {

    // Find handle
    int handle = StructureManager().FindStructure(name);
    if (handle != 0) {

        // Find structure and check version
        PluginStructure* structure = StructureManager().GetStructure(handle);
        if (structure->VersionMajor() == major &&
                structure->VersionMinor() == minor) {

            // Add dependency between structure owner and requester
            if (structure->Owner() != NULL && structure->Owner() != requester)
                ((PluginDLL *) structure->Owner())->AddReferencingDLL(requester);

            return handle;
        }
    }

    // Not found or version mismatch
    return 0;
}

std::string PluginDLLManager::SharedInterfaceKey(
    std::string name,
    int major,
    int minor) {
    return name + "_" + IntToString(major) + "_" + IntToString(minor);
}

std::string PluginDLLManager::FunctionName(int dllIndex, int functionIndex) {
    if (dllIndex >= 0 && dllIndex < Count())
        return dlls[dllIndex]->Filename() + " " + dlls[dllIndex]->FunctionName(functionIndex);
    else
        return "???";
}

bool PluginDLLManager::FindConstant(
    std::string name,
    compConstantMap::const_iterator& itor) {

    // Search all DLLs for constant
    for (int i = 0; i < dlls.size(); i++)
        if (dlls[i]->FindConstant(name, itor))
            return true;

    return false;
}

#ifdef VM_STATE_STREAMING

void PluginDLLManager::StreamOut(std::ostream& stream) {
    // Write DLL filenames, and versions
    WriteLong(stream, dlls.size());
    for (int i = 0; i < dlls.size(); i++) {
        string filename = dlls[i]->FileDetails().filename;
        WriteString(stream, filename);
        WriteLong(stream, dlls[i]->FileDetails().version.major);
        WriteLong(stream, dlls[i]->FileDetails().version.minor);
    }
}

bool PluginDLLManager::StreamIn(std::istream& stream) {

    // Clear out any existing plugins
    Clear();

    int count = ReadLong(stream);
    for (int i = 0; i < count; i++) {

        // Read file details
        string filename = ReadString(stream);
        PluginVersion version;
        version.major = ReadLong(stream);
        version.minor = ReadLong(stream);

        // Attempt to load DLL
        if (!LoadDLL(filename))
            return false;

        // Check version number
        PluginDLL *dll = Find(filename);
        if (!dll->FileDetails().version.Matches(version)) {
            error = "Plugin DLL " + filename + " is the wrong version.\r\n" +
                "Version is " + dll->FileDetails().version.VersionString() +
                ", expected " + version.VersionString();
            return false;
        }
    }
    return true;
}
#endif

void PluginDLLManager::CreateVMFunctionSpecs() {
    for (   DLLVector::iterator i = dlls.begin();
            i != dlls.end();
            i++)
        (*i)->CreateVMFunctionSpecs();
}

////////////////////////////////////////////////////////////////////////////////
//  PluginDLLObjectStore

void PluginDLLObjectStore::DeleteObject(int handle) {
    // Free object
    void *object = Object(handle);
    if (callback != NULL)
        callback->ObjectRemoved(this, object);
}

int DLLFUNC PluginDLLObjectStore::Add(void *object) {
    int handle = store.Alloc();
    store.Value(handle) = object;
    return handle;
}

void DLLFUNC PluginDLLObjectStore::Remove(int handle) {
    if (HandleIsValid(handle)) {

        // Free object
        DeleteObject(handle);

        // Deallocate handle
        store.Free(handle);
    }
}

bool DLLFUNC PluginDLLObjectStore::HandleIsValid(int handle) {
    return store.IndexStored(handle);
}

void *DLLFUNC PluginDLLObjectStore::Object(int handle) {
    return HandleIsValid(handle) ? store.Value(handle) : NULL;
}

void PluginDLLObjectStore::Clear() {
    // Delete each individual element
    for (int i = 0; i < store.Array().size(); i++)
        if (store.ValAllocated() [i])
            DeleteObject(i);

    // Clear store
    store.Clear ();
}

