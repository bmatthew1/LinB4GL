/*  Main.cpp
Copyright 2012 Josh Koert
original code copyright Tom Mulgrew 2004
*/

#include "TomComp.h"
#include "TomStdBasicLib.h"
#include "TomTrigBasicLib.h"
#include "TomFileIOBasicLib.h"
#include "JoshSDLLIB.h"
#include "GLBasicLib_gl.h"
#include "GLBasicLib_glu.h"
#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

char buffer [1024];
char* srcFile;

void WrapPrint(TomVM& vm)
{
    cout << vm.GetStringParam(1).c_str();
}

void WrapPrintr(TomVM& vm)
{
    cout << vm.GetStringParam(1).c_str() << endl;
}

class DummyVMDebugger : public IVMDebugger {
public:
    virtual int UserBreakPtCount();
    virtual int UserBreakPtLine(int index);
};

int DummyVMDebugger::UserBreakPtCount() {
	return 0;
}

int DummyVMDebugger::UserBreakPtLine(int index) {
	return 0;
}

void startCompiler () {
    //preliminary text dump
    cout << "TomBasicCore BASIC compiler and virtual machine (C) Tom Mulgrew 2003-2004" << endl;
    cout << "Based on 2.5.8 source repository" << endl;
    cout << "Current work by Darkjester, Matthew" << endl;
    cout << "Enter basic program with *.gb extension" << endl;
    cout << endl;

    //create compiler and virtual machine
    PluginDLLManager plugins("", true);
    DummyVMDebugger Debugger;
    TomVM vm(plugins, Debugger);
    TomBasicCompiler comp(vm, plugins);
    FileOpener files;

    //Print and Printr for compiler test
    comp.AddFunction("print",  WrapPrint,  compParamTypeList()<<VTP_STRING, false, false, VTP_INT);
    comp.AddFunction("printr", WrapPrintr, compParamTypeList()<<VTP_STRING, false, false, VTP_INT);

    //Additional libraries
    InitTomStdBasicLib (comp);
    InitTomTrigBasicLib (comp);
    InitTomFileIOBasicLib (comp, &files);
    InitJoshSDLLib(comp);
    InitGLBasicLib_gl(comp);
    InitGLBasicLib_glu(comp);

    // Read source from cin
    cout<<"Opening file "<<srcFile<<"..."<<endl;
    ifstream file(srcFile);
    while(!file.eof()){
    file.getline(buffer,1023);
        comp.Parser().SourceCode().push_back(buffer);
    }

    // Compile program
    cout<<"Compiling.."<<endl;
    comp.ClearError();
    comp.Compile();
    if (comp.Error()) {
        cout << endl << "Syntax Error! " << comp.GetError().c_str() << endl;
    return;
    }

    // Run program
    cout<<"Executing!"<<endl;
	vm.Reset();
	do {
		vm.Continue(1000); //execute maximum opcodes
	} while (!(vm.Error() || vm.Done()));

	// Check for virtual machine error
	if(vm.Error()) cout << endl << "Virtual machine error. " << vm.GetError().c_str() << endl;
	else cout << endl << "Done!" << endl;
};

int main (int argc, char* argv[]) {
    if(argc==2) {srcFile = argv[1];}
	else {cout << "Incorrect number of arguments!" << endl; return 0;}
    // InitSDL(Width, Height, Title)
	InitSDL(640, 480, srcFile);
	InitGL (640, 480);
	startCompiler();
	return 0;
};






