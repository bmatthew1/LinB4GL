//---------------------------------------------------------------------------
/*  Created 15-Feb-06: Thomas Mulgrew (tmulgrew@slingshot.co.nz)

    Interfaces the Basic4GL compiler to plugin DLLs
*/

#ifndef PluginDLLH
#define PluginDLLH

#include "compFunction.h"
#include "compConstant.h"
#include "vmData.h"
#include "vmTypes.h"
#include "C:\Bas4glSource\DLL SDK\include\Basic4GLDLLInterface.h"
#include "C:\Bas4glSource\DLLInterface\PluginDataStructures.h"
#include <string>
#include <list>
#include <map>
#include <set>

////////////////////////////////////////////////////////////////////////////////
// compExtFuncSpec
//
// Extended function specification including information about where the
// function is stored (whether it's built in, or stored in a DLL and which one.)
// Used by the DLL manager to pass info to the compiler.
struct compExtFuncSpec {

    // Pointer to main specification
    compFuncSpec    *m_spec;

    // Function details
    bool            m_builtin;            // True = builtin, false = plugin DLL function
    int             m_pluginIndex;        // Index of DLL (if applicable). Note m_spec.m_index holds index of function WITHIN the DLL.
};

////////////////////////////////////////////////////////////////////////////////
//  PluginVersion
//
struct PluginVersion {
    int major;
    int minor;

    PluginVersion() : major(0), minor(0) {}
    PluginVersion(int _major, int _minor) : major(_major), minor(_minor) {}
    PluginVersion(const PluginVersion& p) : major(p.major), minor(p.minor) {}

    bool Matches(const PluginVersion& p) const {
        return p.minor == minor && p.major == major;
    }
    std::string VersionString() const {
        return IntToString(major) + "." + IntToString(minor);
    }
};

////////////////////////////////////////////////////////////////////////////////
//  PluginDLLFile
//
/// File details of a plugin DLL.
struct PluginDLLFile {
    std::string filename;
    std::string description;
    bool loaded;
    PluginVersion version;

    /// True if this is actually an external DLL (rather than a local library)
    bool isExternal;
};

typedef std::vector<PluginDLLFile> DLLFileVector;

class PluginDLLManager;

////////////////////////////////////////////////////////////////////////////////
//  PluginDLL
//
/// A plugin DLL as the Basic4GL compiler and virtual machine sees it.
class PluginDLL : private IDLL_Basic4GL_FunctionRegistry {

    /// Main DLL manager
    PluginDLLManager &manager;

    /// Filename (excluding path)
    std::string filename;

    /// DLL handle.
    /// Note: This is really a HINSTANCE, but I'm damned if I'll include the entire
    /// <windows.h> in this header just for that defn.
    int handle;

    /// Main plugin interface
    IDLL_Basic4GL_Plugin *plugin;

    /// DLL file details
    PluginDLLFile fileDetails;

    /// True if loading failed. Calling code should not try to use DLL.
    bool failed;

    // IDLL_Basic4GL_FunctionRegistry data
    bool definingFunc;                          // True if currently defining a function
    DLL_Basic4GL_Function   currentFunc;        // Pointer to current function
    compFuncSpec            currentSpec;        // Current DLL runtime function being defined
    std::string             currentName;        // Name of current function

    // DLL constants
    compConstantMap         constants;

    // DLL functions
    std::vector<DLL_Basic4GL_Function>  functions;
    std::multimap<std::string,int>      functionLookup;     // Maps function name to index

    // Function specifications
    // Note: We maintain 2 versions of each.
    // The first version uses the plugin structure index when refering to structures
    // (for return types or parameter types). The second uses the virtual machine
    // structure index.
    std::vector<compFuncSpec>           pluginFunctionSpecs;
    std::vector<compFuncSpec>           vmFunctionSpecs;

    // DLL->DLL references
    std::set<PluginDLL*> referencingDLLs;                   // DLLs that reference this one

    // Resource stores
    std::vector<IDLL_Basic4GL_ObjectStore*> objectStores;

    // Structure building
    PluginStructure *currentStructure;

    // IDLL_Basic4GL_FunctionRegistry methods
    virtual void DLLFUNC RegisterStringConstant(
        const char *name,
        const char *value);
    virtual void DLLFUNC RegisterIntConstant(
        const char *name,
        int value);
    virtual void DLLFUNC RegisterFloatConstant(
        const char *name,
        float value);
    virtual void DLLFUNC RegisterVoidFunction(
        const char *name,
        DLL_Basic4GL_Function function);
    virtual void DLLFUNC RegisterFunction(
        const char *name,
        DLL_Basic4GL_Function function,
        DLL_Basic4GL_TypeCode typeCode);
    virtual void DLLFUNC RegisterArrayFunction(
        const char *name,
        DLL_Basic4GL_Function function,
        DLL_Basic4GL_TypeCode typeCode,
        int dimensions);
	virtual void DLLFUNC RegisterStructureFunction(
		const char *name,
		DLL_Basic4GL_Function function,
		int structureTypeHandle);
	virtual void DLLFUNC ModReturnArray(int dimensions);
	virtual void DLLFUNC ModReturnPointer(int level);
    virtual void DLLFUNC ModNoBrackets();
    virtual void DLLFUNC ModTimeshare();
    virtual void DLLFUNC AddParam(DLL_Basic4GL_TypeCode typeCode);
    virtual void DLLFUNC AddArrayParam(
        DLL_Basic4GL_TypeCode typeCode,
        int dimensions);
	virtual void DLLFUNC AddStrucParam(int handle);
	virtual void DLLFUNC ModParamArray(int dimensions);
	virtual void DLLFUNC ModParamPointer(int level);
	virtual void DLLFUNC ModParamReference();
	virtual void DLLFUNC RegisterInterface(
		void *object,
		const char *name,
		int major,
		int minor);
	virtual void *DLLFUNC FetchInterface(
		const char *name,
		int major,
		int minor);
    virtual IDLL_Basic4GL_ObjectStore *DLLFUNC CreateObjectStore(IDLL_Basic4GL_ObjectStoreCallback *callback);

	virtual int DLLFUNC RegisterStructure(const char *name, int versionMajor, int versionMinor);
	virtual void DLLFUNC AddStrucPadding(int numBytes);
	virtual void DLLFUNC AddStrucField(const char *name, int type);
	virtual void DLLFUNC AddStrucStringField(const char *name, int size);
	virtual void DLLFUNC ModStrucFieldArray(int dimensions, int dimension1Size, ...);
	virtual void DLLFUNC ModStrucFieldPointer(int level);
    virtual int DLLFUNC FetchStructure(
        const char *name,
        int versionMajor,
        int versionMinor);

    // Routines
    void CompleteFunction();
    void NewFunction(std::string name, DLL_Basic4GL_Function function);
    void FixType(vmValType& type);

public:

    /// Create plugin DLL from DLL file
    PluginDLL(PluginDLLManager &_manager, std::string path, std::string _filename, bool isStandaloneExe);

    /// Create plugin DLL from plugin object.
    /// Note: This is typically used for local libraries, so aren't really plugin DLLs at all.
    /// However the plugin interface is actually cleaner and fuller featured than the regular
    /// interface, so this has become the preferred way to register builtin functions.
    PluginDLL(PluginDLLManager &_manager, std::string name, IDLL_Basic4GL_Plugin* _plugin, bool isStandaloneExe);
    ~PluginDLL();

    /// Return true if DLL failed to load and/or initialise
    bool Failed() const                         { return failed; }

    /// Error text if failed
    std::string Error();

    std::string Filename() const                { return filename; }
    IDLL_Basic4GL_Plugin *Plugin()              { assert(!failed); return plugin; }
    const PluginDLLFile &FileDetails() const    { return fileDetails; }
    const std::vector<compFuncSpec>& FunctionSpecs() const  { return pluginFunctionSpecs; }

    /// Search for a constant
    bool FindConstant(std::string name, compConstantMap::const_iterator& i);

    /// Return true if name matches a function in this DLL
    bool IsFunction(std::string& name) const {
        return functionLookup.find(LowerCase(name)) != functionLookup.end();
    }

    /// Find all functions of a given name within this DLL and add them to the array
    void FindFunctions(
        std::string& name,
        compExtFuncSpec *functions,
        int& count,
        int max,
        int pluginIndex);

    // Function retrieval by index
    int Count() { return functions.size(); }

    /// Retrieve function by index
    DLL_Basic4GL_Function GetFunction(int index) {
        assert(index >= 0);
        assert(index < Count());
        return functions[index];
    }

    /// Retrieve function name by index
    std::string FunctionName(int index);

    /// Iterate constants
    const compConstantMap Constants() { return constants; }

    /// Log that we are referenced by another DLL.
    /// (Thus we cannot be unloaded until the other DLL has been).
    void AddReferencingDLL(PluginDLL *dll);

    /// Log that we are no longer referenced by another specific DLL.
    /// (Typically means that DLL has been unloaded)
    void RemoveReferencingDLL(PluginDLL *dll);

    /// Return true if we are referenced by at least one other DLL
    bool IsReferenced() const { return !referencingDLLs.empty(); }

    /// List DLLs that reference this one
    std::string DescribeReferencingDLLs() const;

    /// Clear all resource stores allocated by DLL
    void ClearObjectStores();

    /// Create VM versions of function specifications
    void CreateVMFunctionSpecs();
};

typedef std::vector<PluginDLL *> DLLVector;

////////////////////////////////////////////////////////////////////////////////
//  PluginDLLSharedInterface
//
//  Tracks shared interfaces registered by plugin DLLs
struct PluginDLLSharedInterface {
    void        *intf;      // Interface
    PluginDLL   *owner;     // DLL that owns the object
    PluginDLLSharedInterface(void *_intf, PluginDLL *_owner)
        : intf(_intf), owner(_owner) {;}
    PluginDLLSharedInterface(const PluginDLLSharedInterface& s)
        : intf(s.intf), owner(s.owner) {;}
    PluginDLLSharedInterface()
        : intf(NULL), owner(NULL) {;}
};

////////////////////////////////////////////////////////////////////////////////
//  PluginDLLManager
//
/// Manages loading and maintaining plugin DLLs
class PluginDLLManager {
    std::string directory;
    DLLVector   dlls;
    std::string error;
    std::map<std::string,PluginDLLSharedInterface> sharedInterfaces;
    bool isStandaloneExe;

    // Data structures defined by plugins
    PluginStructureManager structureManager;

    /// Find itor for DLL with filename
    DLLVector::iterator FindItor(std::string filename);
    std::string SharedInterfaceKey(
        std::string name,
        int major,
        int minor);
public:
    PluginDLLManager(std::string _directory, bool _isStandaloneExe);
    virtual ~PluginDLLManager();

    // Member access
    PluginStructureManager& StructureManager() { return structureManager; }

    // DLL loading/unloading

    /// Iterate loaded DLLs
    const DLLVector& LoadedDLLs() { return dlls; }

    /// Find and list DLL files.
    DLLFileVector DLLFiles();

    /// Find plugin DLL by name
    PluginDLL *Find(std::string filename);

    /// Return true if a DLL file is loaded
    bool IsLoaded(std::string filename) { return Find(filename) != NULL; }

    /// Load DLL. Returns true if DLL loaded successfully, or false if an error
    /// occurred (use Error() to retrive text).
    bool LoadDLL(std::string filename);

    /// Load a local library.
    /// Note: Cannot be unloaded (or removed with ::Clear())
    bool LoadLocalLibrary(IDLL_Basic4GL_Plugin* library, std::string name);

    /// Unload DLL. Returns true if DLL unloaded successfully.
    bool UnloadDLL(std::string filename);

    /// Return text of last error.
    std::string Error() const { return error; }

    /// Unload all files
    void Clear();

    // Find DLL by name

    /// Return true if name matches a DLL function
    bool IsPluginFunction(std::string& name) const;

    /// Find constant with a given name within all loaded DLLs
    bool FindConstant(
        std::string name,
        compConstantMap::const_iterator& itor);

    /// Find functions of a given name within all loaded DLLs and append to array
    void FindFunctions(
        std::string& name,
        compExtFuncSpec *functions,
        int& count,
        int max);

    // Plugin access by index
    int Count() { return dlls.size(); }

    /// Retrieve DLL by index
    PluginDLL &GetPluginDLL(int index) {
        assert(index >= 0);
        assert(index < Count());
        return *dlls[index];
    }

    std::string FunctionName(int dllIndex, int functionIndex);

    /// Create virtual machine version of function specifications.
    /// Called immediately before a compile, but AFTER the VM versions of the
    /// plugin structures have been created.
    void CreateVMFunctionSpecs();

    // DLL events
    bool ProgramStart();        // Returns true if all plugins started successfully. Otherwise program should not proceed.
    void ProgramEnd();
    void ProgramPause();
    void ProgramResume();
    void ProgramDelayedResume();
    void ProcessMessages();

    // Interface sharing
    void RegisterInterface(
        void *intf,
        std::string name,
        int major,
        int minor,
        PluginDLL *owner);

    void *FetchInterface(
        std::string name,
        int major,
        int minor,
        PluginDLL *requester);

    int FetchStructure(
        std::string name,
        int major,
        int minor,
        PluginDLL *requester);

#ifdef VM_STATE_STREAMING
    void StreamOut(std::ostream& stream);
    bool StreamIn(std::istream& stream);
#endif
};

#endif
