//---------------------------------------------------------------------------
// Created 27-Sep-2003: Thomas Mulgrew (tmulgrew@slingshot.co.nz)
// Copyright (C) Thomas Mulgrew
#pragma hdrstop

#include "TomStdBasicLib.h"
//#include "JonWindows.h"
#include "JoshSDLLib.h"
#include <stdlib.h>
#ifndef _MSC_VER
#include <time.h>
#endif

//---------------------------------------------------------------------------

#ifndef _MSC_VER
#pragma package(smart_init)
#endif

// Constants
#define DEF_MAX_CATCHUP_TIME 150     // .15 seconds

// Globals
DWORD lastTickCount = 0;
int maxCatchupTime = DEF_MAX_CATCHUP_TIME;
int catchupTime = maxCatchupTime - 1;

////////////////////////////////////////////////////////////////////////////////
// Pre-run initialisation
static void Init (TomVM& vm) {
    lastTickCount   = 0;
    maxCatchupTime  = DEF_MAX_CATCHUP_TIME;
    catchupTime     = maxCatchupTime - 1;
}

////////////////////////////////////////////////////////////////////////////////
// Function wrappers

void WrapAbs (TomVM& vm)            { vm.Reg ().RealVal ()  = fabs (vm.GetRealParam (1)); }
void WrapAsc (TomVM& vm)            { vm.Reg ().IntVal ()   = vm.GetStringParam (1) [0]; }
void WrapAtn (TomVM& vm)            { vm.Reg ().RealVal ()  = atan (vm.GetRealParam (1)); }
void WrapChr (TomVM& vm)            { vm.RegString ()       = (char) vm.GetIntParam (1); }
void WrapCos (TomVM& vm)            { vm.Reg ().RealVal ()  = cos (vm.GetRealParam (1)); }
void WrapExp (TomVM& vm)            { vm.Reg ().RealVal ()  = pow (2.7182818284590452353602874713526, vm.GetRealParam (1)); }
void WrapInt (TomVM& vm) {
    vmReal realVal = vm.GetRealParam (1);
    vmInt intVal = (vmInt) realVal;
    if (realVal < 0 && realVal != intVal)       // Special case, negative numbers
        intVal--;
    vm.Reg ().IntVal ()  = intVal;
}
void WrapLeft (TomVM& vm) {
    std::string &s = vm.GetStringParam (2);
    int c = vm.GetIntParam (1);
    if (c <= 0)
        vm.RegString () = "";
    else if (c >= s.length ())
        vm.RegString () = s;
    else
        vm.RegString () = s.substr (0, c);
}
void WrapLen (TomVM& vm)            { vm.Reg ().IntVal ()   = vm.GetStringParam (1).length (); }
void WrapLog (TomVM& vm)            { vm.Reg ().RealVal ()  = log (vm.GetRealParam (1)); }
void WrapMid (TomVM& vm) {
    std::string& s = vm.GetStringParam (3);
    int i = vm.GetIntParam (2) - 1, c = vm.GetIntParam (1);
    if (i < 0) {
        c += i;
        i = 0;
    }
    if (c > 0 && s.length () > 0 && i < s.length ()) {
        if (i + c > s.length ())
            c = s.length () - i;
        vm.RegString () = s.substr (i, c);
    }
    else
        vm.RegString () = "";
}
void WrapLCase (TomVM& vm) {
    vm.RegString () = LowerCase (vm.GetStringParam (1));
}
void WrapUCase (TomVM& vm) {
    vm.RegString () = UpperCase (vm.GetStringParam (1));
}
void WrapPow (TomVM& vm)            { vm.Reg ().RealVal ()  = pow (vm.GetRealParam (2), vm.GetRealParam (1)); }
void WrapRight (TomVM& vm) {
    std::string &s = vm.GetStringParam (2);
    int c = vm.GetIntParam (1);
    if (c <= 0)
        vm.RegString () = "";
    else if (c >= s.length ())
        vm.RegString () = s;
    else
        vm.RegString () = s.substr (s.length () - c, c);
}
void WrapRnd (TomVM& vm)            { vm.Reg ().IntVal ()   = rand ();}
void WrapRandomize (TomVM& vm)      { srand (vm.GetIntParam (1)); }
void WrapRandomize_2 (TomVM& vm)    { srand( (unsigned)time( NULL ) ); }
void WrapSgn (TomVM& vm) {
    int i = vm.GetRealParam (1);
    if (i < 0)          vm.Reg ().IntVal () = -1;
    else if (i == 0)    vm.Reg ().IntVal () = 0;
    else                vm.Reg ().IntVal () = 1;
}
void WrapSin (TomVM& vm)            { vm.Reg ().RealVal ()  = sin (vm.GetRealParam (1)); }
void WrapSqrt (TomVM& vm)           {
    vmReal param = vm.GetRealParam (1);
    if (param < 0)  vm.Reg ().RealVal () = sqrt (-param);
    else            vm.Reg ().RealVal () = sqrt (param);
}
void WrapStr (TomVM& vm)            { char buffer [1024];
                                      vm.RegString ()       = gcvt (vm.GetRealParam (1), 8, buffer); }
void WrapTan (TomVM& vm)            { vm.Reg ().RealVal ()  = tan (vm.GetRealParam (1)); }
void WrapTanh (TomVM& vm)           { vm.Reg ().RealVal ()  = tanh (vm.GetRealParam (1)); }
void WrapVal (TomVM& vm)            { vm.Reg ().RealVal ()  = atof (vm.GetStringParam (1).c_str ()); }

// THIS IS BROKEN
void WrapInitTimer (TomVM& vm) {
    lastTickCount = GetTickCount ();
}
// THIS IS BROKEN
void WrapWaitTimer (TomVM& vm) {

    // Fetch and validate delay
    int delay = vm.GetIntParam (1);
    if (delay < 0)
        delay = 0;
    if (delay > 5000)
        delay = 5000;

    // Find clock tick count to wait for
    lastTickCount += delay;
    if (GetTickCount () > lastTickCount)
        lastTickCount = GetTickCount ();

    // Wait for tick count
    while (GetTickCount () < lastTickCount)
        ;
}
void WrapSyncTimerCatchup (TomVM& vm) {
    maxCatchupTime = vm.GetIntParam (1);
    if (maxCatchupTime < 1)
        maxCatchupTime = 1;
}
//THIS IS BROKEN
void WrapSyncTimer (TomVM& vm) {

    // Fetch and validate delay
    int delay = vm.GetIntParam (1);
    if (delay < 0)
        delay = 0;
    if (delay > 5000)
        delay = 5000;

    int tickCount = GetTickCount ();
    int diff = tickCount - lastTickCount;
    if (diff < delay) {
        catchupTime = 0;
        vm.Reg ().IntVal () = 0;
    }
    else if (catchupTime >= maxCatchupTime) {
        lastTickCount = tickCount;
        catchupTime = 0;
        vm.Reg ().IntVal () = 0;
    }
    else {
        vm.Reg ().IntVal () = -1;
        lastTickCount += delay;
        catchupTime += delay;
    }
}

// Sin, cos and tan using degrees
void WrapSinD (TomVM& vm) {
    vm.Reg ().RealVal ()  = sin (vm.GetRealParam (1) * M_DEG2RAD);
}
void WrapCosD (TomVM& vm) {
    vm.Reg ().RealVal ()  = cos (vm.GetRealParam (1) * M_DEG2RAD);
}
void WrapTanD (TomVM& vm) {
    vm.Reg ().RealVal ()  = tan (vm.GetRealParam (1) * M_DEG2RAD);
}
void WrapATanD (TomVM& vm) {
    vm.Reg ().RealVal ()  = atan (vm.GetRealParam (1)) * M_RAD2DEG;
}

////////////////////////////////////////////////////////////////////////////////
// Initialisation

void InitTomStdBasicLib (TomBasicCompiler& comp) {

    /////////////////////
    // Initialise state
    srand( (unsigned)time( NULL ) );            // Seed random number generator with timer

    ///////////////////////
    // Register constants

    // Regular constants
    comp.AddConstant ("true",       -1);
    comp.AddConstant ("false",      0);
    comp.AddConstant ("rnd_max",    RAND_MAX);

    // Mathematics constants
    comp.AddConstant ("m_pi",       M_PI);
    comp.AddConstant ("m_e",        M_E);

    ///////////////////////
    // Register functions
    // GCC doesn't like compParaTypeList with no Parameters so we create a dummy noParam
    compParamTypeList noParam;
    comp.AddFunction ("abs",        WrapAbs,        compParamTypeList () << VTP_REAL,                           true,   true,   VTP_REAL);
    comp.AddFunction ("asc",        WrapAsc,        compParamTypeList () << VTP_STRING,                         true,   true,   VTP_INT);
    comp.AddFunction ("atn",        WrapAtn,        compParamTypeList () << VTP_REAL,                           true,   true,   VTP_REAL);
    comp.AddFunction ("chr$",       WrapChr,        compParamTypeList () << VTP_INT,                            true,   true,   VTP_STRING);
    comp.AddFunction ("cos",        WrapCos,        compParamTypeList () << VTP_REAL,                           true,   true,   VTP_REAL);
    comp.AddFunction ("exp",        WrapExp,        compParamTypeList () << VTP_REAL,                           true,   true,   VTP_REAL);
    comp.AddFunction ("int",        WrapInt,        compParamTypeList () << VTP_REAL,                           true,   true,   VTP_INT);
    comp.AddFunction ("left$",      WrapLeft,       compParamTypeList () << VTP_STRING << VTP_INT,              true,   true,   VTP_STRING);
    comp.AddFunction ("len",        WrapLen,        compParamTypeList () << VTP_STRING,                         true,   true,   VTP_INT);
    comp.AddFunction ("log",        WrapLog,        compParamTypeList () << VTP_REAL,                           true,   true,   VTP_REAL);
    comp.AddFunction ("mid$",       WrapMid,        compParamTypeList () << VTP_STRING << VTP_INT << VTP_INT,   true,   true,   VTP_STRING);
    comp.AddFunction ("pow",        WrapPow,        compParamTypeList () << VTP_REAL << VTP_REAL,               true,   true,   VTP_REAL);
    comp.AddFunction ("right$",     WrapRight,      compParamTypeList () << VTP_STRING << VTP_INT,              true,   true,   VTP_STRING);
    comp.AddFunction ("rnd",        WrapRnd,        noParam,                                       true,   true,   VTP_INT);
    comp.AddFunction ("sgn",        WrapSgn,        compParamTypeList () << VTP_REAL,                           true,   true,   VTP_INT);
    comp.AddFunction ("sin",        WrapSin,        compParamTypeList () << VTP_REAL,                           true,   true,   VTP_REAL);
    comp.AddFunction ("sqrt",       WrapSqrt,       compParamTypeList () << VTP_REAL,                           true,   true,   VTP_REAL);
    comp.AddFunction ("sqr",        WrapSqrt,       compParamTypeList () << VTP_REAL,                           true,   true,   VTP_REAL);      // sqr = Synonym for sqrt
    comp.AddFunction ("str$",       WrapStr,        compParamTypeList () << VTP_REAL,                           true,   true,   VTP_STRING);
    comp.AddFunction ("tan",        WrapTan,        compParamTypeList () << VTP_REAL,                           true,   true,   VTP_REAL);
    comp.AddFunction ("tanh",       WrapTanh,       compParamTypeList () << VTP_REAL,                           true,   true,   VTP_REAL);
    comp.AddFunction ("val",        WrapVal,        compParamTypeList () << VTP_STRING,                         true,   true,   VTP_REAL);
    comp.AddFunction ("sind",       WrapSinD,       compParamTypeList () << VTP_REAL,                           true,   true,   VTP_REAL);
    comp.AddFunction ("cosd",       WrapCosD,       compParamTypeList () << VTP_REAL,                           true,   true,   VTP_REAL);
    comp.AddFunction ("tand",       WrapTanD,       compParamTypeList () << VTP_REAL,                           true,   true,   VTP_REAL);
    comp.AddFunction ("atand",      WrapATanD,      compParamTypeList () << VTP_REAL,                           true,   true,   VTP_REAL);
    comp.AddFunction ("lcase$",     WrapLCase,      compParamTypeList () << VTP_STRING,                         true,   true,   VTP_STRING);
    comp.AddFunction ("ucase$",     WrapUCase,      compParamTypeList () << VTP_STRING,                         true,   true,   VTP_STRING);
    comp.AddFunction ("randomize",  WrapRandomize,  compParamTypeList () << VTP_INT,                            true,   false,  VTP_INT);
    comp.AddFunction ("randomize",  WrapRandomize_2,noParam,                                       true,   false,  VTP_INT);

    // Timer
    comp.AddFunction ("inittimer",  WrapInitTimer,  noParam,                                       true,   false,  VTP_INT);
    comp.AddFunction ("waittimer",  WrapWaitTimer,  compParamTypeList () << VTP_INT,                            true,   false,  VTP_INT, true);
    comp.AddFunction ("synctimer",  WrapSyncTimer,  compParamTypeList () << VTP_INT,                            true,   true,   VTP_INT);
    comp.AddFunction ("synctimercatchup",  WrapSyncTimerCatchup,  compParamTypeList () << VTP_INT,              true,   false,  VTP_INT);
}
