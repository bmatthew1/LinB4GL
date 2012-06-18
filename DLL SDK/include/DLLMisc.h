/*	DLLMisc.h

	Created 12-Mar-06: Thomas Mulgrew (tmulgrew@slingshot.co.nz)

	Miscellaneous DLL types.
*/

#ifndef _DLLMisc_h
#define _DLLMisc_h

// DLL function/method modifiers.
// (This may be different for different compilers)

#ifndef DLLExport
#define DLLExport __declspec(dllexport)
#endif

#ifndef DLLFUNC
#define DLLFUNC __cdecl
#endif

#endif
