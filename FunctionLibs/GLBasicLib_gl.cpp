// Function wrappers
#include "GLBasicLib_gl.h"
#include <GL/glut.h>
#include <GL/GLext.h>

void WrapglAccum(TomVM& vm){glAccum(vm.GetIntParam (2), vm.GetRealParam (1));}
void WrapglAlphaFunc(TomVM& vm){glAlphaFunc(vm.GetIntParam (2), vm.GetRealParam (1));}

/*
void WrapglAreTexturesResident(TomVM& vm){if(!ValidateSizeParam(vm,3))return;GLuint a1[65536];
	ReadAndZero(vm.Data(),vm.GetIntParam(2),vmValType(VTP_INT,1,1,true),a1,vm.GetIntParam(3));
	GLboolean a2[65536];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a2,vm.GetIntParam(3));
	vm.Reg ().IntVal () = glAreTexturesResident(vm.GetIntParam (3), a1, a2);
	WriteArray(vm.Data(),vm.GetIntParam(2),vmValType(VTP_INT,1,1,true),a1,vm.GetIntParam(3));

	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a2,vm.GetIntParam(3));
	}
*/

void WrapglArrayElement(TomVM& vm){glArrayElement(vm.GetIntParam (1));}
void WrapglBindTexture(TomVM& vm){glBindTexture(vm.GetIntParam (2), vm.GetIntParam (1));}
void WrapglBlendFunc(TomVM& vm){glBlendFunc(vm.GetIntParam (2), vm.GetIntParam (1));}
void WrapglBegin(TomVM& vm){glBegin(vm.GetIntParam (1));}
void WrapglCallList(TomVM& vm){glCallList(vm.GetIntParam (1));}
void WrapglClear(TomVM& vm){glClear(vm.GetIntParam (1));}
void WrapglClearAccum(TomVM& vm){glClearAccum(vm.GetRealParam (4), vm.GetRealParam (3), vm.GetRealParam (2), vm.GetRealParam (1));}
void WrapglClearColor(TomVM& vm){glClearColor(vm.GetRealParam (4), vm.GetRealParam (3), vm.GetRealParam (2), vm.GetRealParam (1));}
void WrapglClearDepth(TomVM& vm){glClearDepth(vm.GetRealParam (1));}
void WrapglClearIndex(TomVM& vm){glClearIndex(vm.GetRealParam (1));}
void WrapglClearStencil(TomVM& vm){glClearStencil(vm.GetIntParam (1));}
void WrapglClipPlane(TomVM& vm){GLdouble a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	glClipPlane(vm.GetIntParam (2), a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	}
void WrapglClipPlane_2(TomVM& vm){GLdouble a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).RealVal();
	glClipPlane(vm.GetIntParam (2), a1);
	vm.GetRefParam(1).RealVal()=a1[0];
	}
void WrapglColor3b(TomVM& vm){glColor3b(vm.GetIntParam (3), vm.GetIntParam (2), vm.GetIntParam (1));}
void WrapglColor3bv(TomVM& vm){GLbyte a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	glColor3bv(a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	}
void WrapglColor3bv_2(TomVM& vm){GLbyte a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).IntVal();
	glColor3bv(a1);
	vm.GetRefParam(1).IntVal()=a1[0];
	}
void WrapglColor3d(TomVM& vm){glColor3d(vm.GetRealParam (3), vm.GetRealParam (2), vm.GetRealParam (1));}
void WrapglColor3dv(TomVM& vm){GLdouble a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	glColor3dv(a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	}
void WrapglColor3dv_2(TomVM& vm){GLdouble a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).RealVal();
	glColor3dv(a1);
	vm.GetRefParam(1).RealVal()=a1[0];
	}
void WrapglColor3f(TomVM& vm){glColor3f(vm.GetRealParam (3), vm.GetRealParam (2), vm.GetRealParam (1));}
void WrapglColor3fv(TomVM& vm){GLfloat a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	glColor3fv(a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	}
void WrapglColor3fv_2(TomVM& vm){GLfloat a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).RealVal();
	glColor3fv(a1);
	vm.GetRefParam(1).RealVal()=a1[0];
	}
void WrapglColor3i(TomVM& vm){glColor3i(vm.GetIntParam (3), vm.GetIntParam (2), vm.GetIntParam (1));}
void WrapglColor3iv(TomVM& vm){GLint a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	glColor3iv(a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	}
void WrapglColor3iv_2(TomVM& vm){GLint a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).IntVal();
	glColor3iv(a1);
	vm.GetRefParam(1).IntVal()=a1[0];
	}
void WrapglColor3s(TomVM& vm){glColor3s(vm.GetIntParam (3), vm.GetIntParam (2), vm.GetIntParam (1));}
void WrapglColor3sv(TomVM& vm){GLshort a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	glColor3sv(a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	}
void WrapglColor3sv_2(TomVM& vm){GLshort a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).IntVal();
	glColor3sv(a1);
	vm.GetRefParam(1).IntVal()=a1[0];
	}
void WrapglColor3ub(TomVM& vm){glColor3ub(vm.GetIntParam (3), vm.GetIntParam (2), vm.GetIntParam (1));}
void WrapglColor3ubv(TomVM& vm){GLubyte a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	glColor3ubv(a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	}
void WrapglColor3ubv_2(TomVM& vm){GLubyte a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).IntVal();
	glColor3ubv(a1);
	vm.GetRefParam(1).IntVal()=a1[0];
	}
void WrapglColor3ui(TomVM& vm){glColor3ui(vm.GetIntParam (3), vm.GetIntParam (2), vm.GetIntParam (1));}
void WrapglColor3uiv(TomVM& vm){GLuint a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	glColor3uiv(a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	}
void WrapglColor3uiv_2(TomVM& vm){GLuint a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).IntVal();
	glColor3uiv(a1);
	vm.GetRefParam(1).IntVal()=a1[0];
	}
void WrapglColor3us(TomVM& vm){glColor3us(vm.GetIntParam (3), vm.GetIntParam (2), vm.GetIntParam (1));}
void WrapglColor3usv(TomVM& vm){GLushort a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	glColor3usv(a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	}
void WrapglColor3usv_2(TomVM& vm){GLushort a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).IntVal();
	glColor3usv(a1);
	vm.GetRefParam(1).IntVal()=a1[0];
	}
void WrapglColor4b(TomVM& vm){glColor4b(vm.GetIntParam (4), vm.GetIntParam (3), vm.GetIntParam (2), vm.GetIntParam (1));}
void WrapglColor4bv(TomVM& vm){GLbyte a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	glColor4bv(a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	}
void WrapglColor4bv_2(TomVM& vm){GLbyte a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).IntVal();
	glColor4bv(a1);
	vm.GetRefParam(1).IntVal()=a1[0];
	}
void WrapglColor4d(TomVM& vm){glColor4d(vm.GetRealParam (4), vm.GetRealParam (3), vm.GetRealParam (2), vm.GetRealParam (1));}
void WrapglColor4dv(TomVM& vm){GLdouble a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	glColor4dv(a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	}
void WrapglColor4dv_2(TomVM& vm){GLdouble a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).RealVal();
	glColor4dv(a1);
	vm.GetRefParam(1).RealVal()=a1[0];
	}
void WrapglColor4f(TomVM& vm){glColor4f(vm.GetRealParam (4), vm.GetRealParam (3), vm.GetRealParam (2), vm.GetRealParam (1));}
void WrapglColor4fv(TomVM& vm){GLfloat a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	glColor4fv(a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	}
void WrapglColor4fv_2(TomVM& vm){GLfloat a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).RealVal();
	glColor4fv(a1);
	vm.GetRefParam(1).RealVal()=a1[0];
	}
void WrapglColor4i(TomVM& vm){glColor4i(vm.GetIntParam (4), vm.GetIntParam (3), vm.GetIntParam (2), vm.GetIntParam (1));}
void WrapglColor4iv(TomVM& vm){GLint a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	glColor4iv(a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	}
void WrapglColor4iv_2(TomVM& vm){GLint a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).IntVal();
	glColor4iv(a1);
	vm.GetRefParam(1).IntVal()=a1[0];
	}
void WrapglColor4s(TomVM& vm){glColor4s(vm.GetIntParam (4), vm.GetIntParam (3), vm.GetIntParam (2), vm.GetIntParam (1));}
void WrapglColor4sv(TomVM& vm){GLshort a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	glColor4sv(a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	}
void WrapglColor4sv_2(TomVM& vm){GLshort a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).IntVal();
	glColor4sv(a1);
	vm.GetRefParam(1).IntVal()=a1[0];
	}
void WrapglColor4ub(TomVM& vm){glColor4ub(vm.GetIntParam (4), vm.GetIntParam (3), vm.GetIntParam (2), vm.GetIntParam (1));}
void WrapglColor4ubv(TomVM& vm){GLubyte a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	glColor4ubv(a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	}
void WrapglColor4ubv_2(TomVM& vm){GLubyte a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).IntVal();
	glColor4ubv(a1);
	vm.GetRefParam(1).IntVal()=a1[0];
	}
void WrapglColor4ui(TomVM& vm){glColor4ui(vm.GetIntParam (4), vm.GetIntParam (3), vm.GetIntParam (2), vm.GetIntParam (1));}
void WrapglColor4uiv(TomVM& vm){GLuint a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	glColor4uiv(a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	}
void WrapglColor4uiv_2(TomVM& vm){GLuint a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).IntVal();
	glColor4uiv(a1);
	vm.GetRefParam(1).IntVal()=a1[0];
	}
void WrapglColor4us(TomVM& vm){glColor4us(vm.GetIntParam (4), vm.GetIntParam (3), vm.GetIntParam (2), vm.GetIntParam (1));}
void WrapglColor4usv(TomVM& vm){GLushort a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	glColor4usv(a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	}
void WrapglColor4usv_2(TomVM& vm){GLushort a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).IntVal();
	glColor4usv(a1);
	vm.GetRefParam(1).IntVal()=a1[0];
	}
void WrapglColorMask(TomVM& vm){glColorMask(vm.GetIntParam (4), vm.GetIntParam (3), vm.GetIntParam (2), vm.GetIntParam (1));}
void WrapglColorMaterial(TomVM& vm){glColorMaterial(vm.GetIntParam (2), vm.GetIntParam (1));}
void WrapglCopyPixels(TomVM& vm){glCopyPixels(vm.GetIntParam (5), vm.GetIntParam (4), vm.GetIntParam (3), vm.GetIntParam (2), vm.GetIntParam (1));}
void WrapglCopyTexImage1D(TomVM& vm){glCopyTexImage1D(vm.GetIntParam (7), vm.GetIntParam (6), vm.GetIntParam (5), vm.GetIntParam (4), vm.GetIntParam (3), vm.GetIntParam (2), vm.GetIntParam (1));}
void WrapglCopyTexImage2D(TomVM& vm){glCopyTexImage2D(vm.GetIntParam (8), vm.GetIntParam (7), vm.GetIntParam (6), vm.GetIntParam (5), vm.GetIntParam (4), vm.GetIntParam (3), vm.GetIntParam (2), vm.GetIntParam (1));}
void WrapglCopyTexSubImage1D(TomVM& vm){glCopyTexSubImage1D(vm.GetIntParam (6), vm.GetIntParam (5), vm.GetIntParam (4), vm.GetIntParam (3), vm.GetIntParam (2), vm.GetIntParam (1));}
void WrapglCopyTexSubImage2D(TomVM& vm){glCopyTexSubImage2D(vm.GetIntParam (8), vm.GetIntParam (7), vm.GetIntParam (6), vm.GetIntParam (5), vm.GetIntParam (4), vm.GetIntParam (3), vm.GetIntParam (2), vm.GetIntParam (1));}
void WrapglCullFace(TomVM& vm){glCullFace(vm.GetIntParam (1));}
void WrapglDepthFunc(TomVM& vm){glDepthFunc(vm.GetIntParam (1));}
void WrapglDepthMask(TomVM& vm){glDepthMask(vm.GetIntParam (1));}
void WrapglDepthRange(TomVM& vm){glDepthRange(vm.GetRealParam (2), vm.GetRealParam (1));}
void WrapglDisable(TomVM& vm){glDisable(vm.GetIntParam (1));}
void WrapglDisableClientState(TomVM& vm){glDisableClientState(vm.GetIntParam (1));}

/*
void WrapglDrawArrays(TomVM& vm){if(!ValidateSizeParam(vm,1))return;glDrawArrays(vm.GetIntParam (3), vm.GetIntParam (2), vm.GetIntParam (1));}
*/

void WrapglDrawBuffer(TomVM& vm){glDrawBuffer(vm.GetIntParam (1));}
void WrapglEdgeFlag(TomVM& vm){glEdgeFlag(vm.GetIntParam (1));}
void WrapglEdgeFlagv(TomVM& vm){GLboolean a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	glEdgeFlagv(a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	}
void WrapglEdgeFlagv_2(TomVM& vm){GLboolean a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).IntVal();
	glEdgeFlagv(a1);
	vm.GetRefParam(1).IntVal()=a1[0];
	}
void WrapglEnable(TomVM& vm){glEnable(vm.GetIntParam (1));}
void WrapglEnableClientState(TomVM& vm){glEnableClientState(vm.GetIntParam (1));}
void WrapglEnd (TomVM& vm) {glEnd();}
void WrapglEndList(TomVM& vm){glEndList();}
void WrapglEvalCoord1d(TomVM& vm){glEvalCoord1d(vm.GetRealParam (1));}
void WrapglEvalCoord1dv(TomVM& vm){GLdouble a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	glEvalCoord1dv(a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	}
void WrapglEvalCoord1dv_2(TomVM& vm){GLdouble a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).RealVal();
	glEvalCoord1dv(a1);
	vm.GetRefParam(1).RealVal()=a1[0];
	}
void WrapglEvalCoord1f(TomVM& vm){glEvalCoord1f(vm.GetRealParam (1));}
void WrapglEvalCoord1fv(TomVM& vm){GLfloat a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	glEvalCoord1fv(a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	}
void WrapglEvalCoord1fv_2(TomVM& vm){GLfloat a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).RealVal();
	glEvalCoord1fv(a1);
	vm.GetRefParam(1).RealVal()=a1[0];
	}
void WrapglEvalCoord2d(TomVM& vm){glEvalCoord2d(vm.GetRealParam (2), vm.GetRealParam (1));}
void WrapglEvalCoord2dv(TomVM& vm){GLdouble a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	glEvalCoord2dv(a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	}
void WrapglEvalCoord2dv_2(TomVM& vm){GLdouble a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).RealVal();
	glEvalCoord2dv(a1);
	vm.GetRefParam(1).RealVal()=a1[0];
	}
void WrapglEvalCoord2f(TomVM& vm){glEvalCoord2f(vm.GetRealParam (2), vm.GetRealParam (1));}
void WrapglEvalCoord2fv(TomVM& vm){GLfloat a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	glEvalCoord2fv(a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	}
void WrapglEvalCoord2fv_2(TomVM& vm){GLfloat a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).RealVal();
	glEvalCoord2fv(a1);
	vm.GetRefParam(1).RealVal()=a1[0];
	}
void WrapglEvalMesh1(TomVM& vm){glEvalMesh1(vm.GetIntParam (3), vm.GetIntParam (2), vm.GetIntParam (1));}
void WrapglEvalMesh2(TomVM& vm){glEvalMesh2(vm.GetIntParam (5), vm.GetIntParam (4), vm.GetIntParam (3), vm.GetIntParam (2), vm.GetIntParam (1));}
void WrapglEvalPoint1(TomVM& vm){glEvalPoint1(vm.GetIntParam (1));}
void WrapglEvalPoint2(TomVM& vm){glEvalPoint2(vm.GetIntParam (2), vm.GetIntParam (1));}

/*
void WrapglFeedbackBuffer(TomVM& vm){if(!ValidateSizeParam(vm,3))return;GLfloat a1[65536];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,vm.GetIntParam(3));
	glFeedbackBuffer(vm.GetIntParam (3), vm.GetIntParam (2), a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,vm.GetIntParam(3));
	}
*/

void WrapglFinish(TomVM& vm){glFinish();}
void WrapglFlush(TomVM& vm){glFlush();}
void WrapglFogf(TomVM& vm){glFogf(vm.GetIntParam (2), vm.GetRealParam (1));}
void WrapglFogfv(TomVM& vm){GLfloat a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	glFogfv(vm.GetIntParam (2), a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	}
void WrapglFogfv_2(TomVM& vm){GLfloat a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).RealVal();
	glFogfv(vm.GetIntParam (2), a1);
	vm.GetRefParam(1).RealVal()=a1[0];
	}
void WrapglFogi(TomVM& vm){glFogi(vm.GetIntParam (2), vm.GetIntParam (1));}
void WrapglFogiv(TomVM& vm){GLint a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	glFogiv(vm.GetIntParam (2), a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	}
void WrapglFogiv_2(TomVM& vm){GLint a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).IntVal();
	glFogiv(vm.GetIntParam (2), a1);
	vm.GetRefParam(1).IntVal()=a1[0];
	}
void WrapglFrontFace(TomVM& vm){glFrontFace(vm.GetIntParam (1));}
void WrapglFrustum(TomVM& vm){glFrustum(vm.GetRealParam (6), vm.GetRealParam (5), vm.GetRealParam (4), vm.GetRealParam (3), vm.GetRealParam (2), vm.GetRealParam (1));}
void WrapglGetBooleanv(TomVM& vm){GLboolean a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	glGetBooleanv(vm.GetIntParam (2), a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	}
void WrapglGetBooleanv_2(TomVM& vm){GLboolean a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).IntVal();
	glGetBooleanv(vm.GetIntParam (2), a1);
	vm.GetRefParam(1).IntVal()=a1[0];
	}
void WrapglGetClipPlane(TomVM& vm){GLdouble a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	glGetClipPlane(vm.GetIntParam (2), a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	}
void WrapglGetClipPlane_2(TomVM& vm){GLdouble a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).RealVal();
	glGetClipPlane(vm.GetIntParam (2), a1);
	vm.GetRefParam(1).RealVal()=a1[0];
	}
void WrapglGetDoublev(TomVM& vm){GLdouble a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	glGetDoublev(vm.GetIntParam (2), a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	}
void WrapglGetDoublev_2(TomVM& vm){GLdouble a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).RealVal();
	glGetDoublev(vm.GetIntParam (2), a1);
	vm.GetRefParam(1).RealVal()=a1[0];
	}
void WrapglGetError(TomVM& vm){vm.Reg ().IntVal () = glGetError();}
void WrapglGetFloatv(TomVM& vm){GLfloat a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	glGetFloatv(vm.GetIntParam (2), a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	}
void WrapglGetFloatv_2(TomVM& vm){GLfloat a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).RealVal();
	glGetFloatv(vm.GetIntParam (2), a1);
	vm.GetRefParam(1).RealVal()=a1[0];
	}
void WrapglGetIntegerv(TomVM& vm){GLint a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	glGetIntegerv(vm.GetIntParam (2), a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	}
void WrapglGetIntegerv_2(TomVM& vm){GLint a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).IntVal();
	glGetIntegerv(vm.GetIntParam (2), a1);
	vm.GetRefParam(1).IntVal()=a1[0];
	}
void WrapglGetLightfv(TomVM& vm){GLfloat a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	glGetLightfv(vm.GetIntParam (3), vm.GetIntParam (2), a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	}
void WrapglGetLightfv_2(TomVM& vm){GLfloat a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).RealVal();
	glGetLightfv(vm.GetIntParam (3), vm.GetIntParam (2), a1);
	vm.GetRefParam(1).RealVal()=a1[0];
	}
void WrapglGetLightiv(TomVM& vm){GLint a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	glGetLightiv(vm.GetIntParam (3), vm.GetIntParam (2), a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	}
void WrapglGetLightiv_2(TomVM& vm){GLint a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).IntVal();
	glGetLightiv(vm.GetIntParam (3), vm.GetIntParam (2), a1);
	vm.GetRefParam(1).IntVal()=a1[0];
	}
void WrapglGetMaterialfv(TomVM& vm){GLfloat a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	glGetMaterialfv(vm.GetIntParam (3), vm.GetIntParam (2), a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	}
void WrapglGetMaterialfv_2(TomVM& vm){GLfloat a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).RealVal();
	glGetMaterialfv(vm.GetIntParam (3), vm.GetIntParam (2), a1);
	vm.GetRefParam(1).RealVal()=a1[0];
	}
void WrapglGetMaterialiv(TomVM& vm){GLint a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	glGetMaterialiv(vm.GetIntParam (3), vm.GetIntParam (2), a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	}
void WrapglGetMaterialiv_2(TomVM& vm){GLint a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).IntVal();
	glGetMaterialiv(vm.GetIntParam (3), vm.GetIntParam (2), a1);
	vm.GetRefParam(1).IntVal()=a1[0];
	}
void WrapglGetPixelMapuiv(TomVM& vm){GLuint a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	glGetPixelMapuiv(vm.GetIntParam (2), a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	}
void WrapglGetPixelMapuiv_2(TomVM& vm){GLuint a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).IntVal();
	glGetPixelMapuiv(vm.GetIntParam (2), a1);
	vm.GetRefParam(1).IntVal()=a1[0];
	}
void WrapglGetTexEnvfv(TomVM& vm){GLfloat a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	glGetTexEnvfv(vm.GetIntParam (3), vm.GetIntParam (2), a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	}
void WrapglGetTexEnvfv_2(TomVM& vm){GLfloat a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).RealVal();
	glGetTexEnvfv(vm.GetIntParam (3), vm.GetIntParam (2), a1);
	vm.GetRefParam(1).RealVal()=a1[0];
	}
void WrapglGetTexEnviv(TomVM& vm){GLint a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	glGetTexEnviv(vm.GetIntParam (3), vm.GetIntParam (2), a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	}
void WrapglGetTexEnviv_2(TomVM& vm){GLint a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).IntVal();
	glGetTexEnviv(vm.GetIntParam (3), vm.GetIntParam (2), a1);
	vm.GetRefParam(1).IntVal()=a1[0];
	}
void WrapglGetTexGendv(TomVM& vm){GLdouble a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	glGetTexGendv(vm.GetIntParam (3), vm.GetIntParam (2), a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	}
void WrapglGetTexGendv_2(TomVM& vm){GLdouble a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).RealVal();
	glGetTexGendv(vm.GetIntParam (3), vm.GetIntParam (2), a1);
	vm.GetRefParam(1).RealVal()=a1[0];
	}
void WrapglGetTexGenfv(TomVM& vm){GLfloat a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	glGetTexGenfv(vm.GetIntParam (3), vm.GetIntParam (2), a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	}
void WrapglGetTexGenfv_2(TomVM& vm){GLfloat a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).RealVal();
	glGetTexGenfv(vm.GetIntParam (3), vm.GetIntParam (2), a1);
	vm.GetRefParam(1).RealVal()=a1[0];
	}
void WrapglGetTexGeniv(TomVM& vm){GLint a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	glGetTexGeniv(vm.GetIntParam (3), vm.GetIntParam (2), a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	}
void WrapglGetTexGeniv_2(TomVM& vm){GLint a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).IntVal();
	glGetTexGeniv(vm.GetIntParam (3), vm.GetIntParam (2), a1);
	vm.GetRefParam(1).IntVal()=a1[0];
	}
void WrapglGetTexLevelParameterfv(TomVM& vm){GLfloat a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	glGetTexLevelParameterfv(vm.GetIntParam (4), vm.GetIntParam (3), vm.GetIntParam (2), a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	}
void WrapglGetTexLevelParameterfv_2(TomVM& vm){GLfloat a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).RealVal();
	glGetTexLevelParameterfv(vm.GetIntParam (4), vm.GetIntParam (3), vm.GetIntParam (2), a1);
	vm.GetRefParam(1).RealVal()=a1[0];
	}
void WrapglGetTexLevelParameteriv(TomVM& vm){GLint a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	glGetTexLevelParameteriv(vm.GetIntParam (4), vm.GetIntParam (3), vm.GetIntParam (2), a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	}
void WrapglGetTexLevelParameteriv_2(TomVM& vm){GLint a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).IntVal();
	glGetTexLevelParameteriv(vm.GetIntParam (4), vm.GetIntParam (3), vm.GetIntParam (2), a1);
	vm.GetRefParam(1).IntVal()=a1[0];
	}
void WrapglGetTexParameterfv(TomVM& vm){GLfloat a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	glGetTexParameterfv(vm.GetIntParam (3), vm.GetIntParam (2), a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	}
void WrapglGetTexParameterfv_2(TomVM& vm){GLfloat a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).RealVal();
	glGetTexParameterfv(vm.GetIntParam (3), vm.GetIntParam (2), a1);
	vm.GetRefParam(1).RealVal()=a1[0];
	}
void WrapglGetTexParameteriv(TomVM& vm){GLint a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	glGetTexParameteriv(vm.GetIntParam (3), vm.GetIntParam (2), a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	}
void WrapglGetTexParameteriv_2(TomVM& vm){GLint a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).IntVal();
	glGetTexParameteriv(vm.GetIntParam (3), vm.GetIntParam (2), a1);
	vm.GetRefParam(1).IntVal()=a1[0];
	}
void WrapglHint(TomVM& vm){glHint(vm.GetIntParam (2), vm.GetIntParam (1));}
void WrapglIndexMask(TomVM& vm){glIndexMask(vm.GetIntParam (1));}
void WrapglIndexd(TomVM& vm){glIndexd(vm.GetRealParam (1));}
void WrapglIndexdv(TomVM& vm){GLdouble a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	glIndexdv(a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	}
void WrapglIndexdv_2(TomVM& vm){GLdouble a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).RealVal();
	glIndexdv(a1);
	vm.GetRefParam(1).RealVal()=a1[0];
	}
void WrapglIndexf(TomVM& vm){glIndexf(vm.GetRealParam (1));}
void WrapglIndexfv(TomVM& vm){GLfloat a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	glIndexfv(a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	}
void WrapglIndexfv_2(TomVM& vm){GLfloat a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).RealVal();
	glIndexfv(a1);
	vm.GetRefParam(1).RealVal()=a1[0];
	}
void WrapglIndexi(TomVM& vm){glIndexi(vm.GetIntParam (1));}
void WrapglIndexiv(TomVM& vm){GLint a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	glIndexiv(a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	}
void WrapglIndexiv_2(TomVM& vm){GLint a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).IntVal();
	glIndexiv(a1);
	vm.GetRefParam(1).IntVal()=a1[0];
	}
void WrapglIndexs(TomVM& vm){glIndexs(vm.GetIntParam (1));}
void WrapglIndexsv(TomVM& vm){GLshort a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	glIndexsv(a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	}
void WrapglIndexsv_2(TomVM& vm){GLshort a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).IntVal();
	glIndexsv(a1);
	vm.GetRefParam(1).IntVal()=a1[0];
	}
void WrapglIndexub(TomVM& vm){glIndexub(vm.GetIntParam (1));}
void WrapglIndexubv(TomVM& vm){GLubyte a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	glIndexubv(a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	}
void WrapglIndexubv_2(TomVM& vm){GLubyte a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).IntVal();
	glIndexubv(a1);
	vm.GetRefParam(1).IntVal()=a1[0];
	}
void WrapglInitNames(TomVM& vm){glInitNames();}
void WrapglIsEnabled(TomVM& vm){vm.Reg ().IntVal () = glIsEnabled(vm.GetIntParam (1));}
void WrapglIsList(TomVM& vm){vm.Reg ().IntVal () = glIsList(vm.GetIntParam (1));}
void WrapglIsTexture(TomVM& vm){vm.Reg ().IntVal () = glIsTexture(vm.GetIntParam (1));}
void WrapglLightModelf(TomVM& vm){glLightModelf(vm.GetIntParam (2), vm.GetRealParam (1));}
void WrapglLightModelfv(TomVM& vm){GLfloat a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	glLightModelfv(vm.GetIntParam (2), a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	}
void WrapglLightModelfv_2(TomVM& vm){GLfloat a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).RealVal();
	glLightModelfv(vm.GetIntParam (2), a1);
	vm.GetRefParam(1).RealVal()=a1[0];
	}
void WrapglLightModeli(TomVM& vm){glLightModeli(vm.GetIntParam (2), vm.GetIntParam (1));}
void WrapglLightModeliv(TomVM& vm){GLint a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	glLightModeliv(vm.GetIntParam (2), a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	}
void WrapglLightModeliv_2(TomVM& vm){GLint a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).IntVal();
	glLightModeliv(vm.GetIntParam (2), a1);
	vm.GetRefParam(1).IntVal()=a1[0];
	}
void WrapglLightf(TomVM& vm){glLightf(vm.GetIntParam (3), vm.GetIntParam (2), vm.GetRealParam (1));}
void WrapglLightfv(TomVM& vm){GLfloat a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	glLightfv(vm.GetIntParam (3), vm.GetIntParam (2), a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	}
void WrapglLightfv_2(TomVM& vm){GLfloat a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).RealVal();
	glLightfv(vm.GetIntParam (3), vm.GetIntParam (2), a1);
	vm.GetRefParam(1).RealVal()=a1[0];
	}
void WrapglLighti(TomVM& vm){glLighti(vm.GetIntParam (3), vm.GetIntParam (2), vm.GetIntParam (1));}
void WrapglLightiv(TomVM& vm){GLint a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	glLightiv(vm.GetIntParam (3), vm.GetIntParam (2), a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	}
void WrapglLightiv_2(TomVM& vm){GLint a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).IntVal();
	glLightiv(vm.GetIntParam (3), vm.GetIntParam (2), a1);
	vm.GetRefParam(1).IntVal()=a1[0];
	}
void WrapglLineStipple(TomVM& vm){glLineStipple(vm.GetIntParam (2), vm.GetIntParam (1));}
void WrapglLineWidth(TomVM& vm){glLineWidth(vm.GetRealParam (1));}
void WrapglListBase(TomVM& vm){glListBase(vm.GetIntParam (1));}
void WrapglLoadIdentity(TomVM& vm){glLoadIdentity();}
void WrapglLoadName(TomVM& vm){glLoadName(vm.GetIntParam (1));}
void WrapglLogicOp(TomVM& vm){glLogicOp(vm.GetIntParam (1));}
void WrapglMapGrid1d(TomVM& vm){glMapGrid1d(vm.GetIntParam (3), vm.GetRealParam (2), vm.GetRealParam (1));}
void WrapglMapGrid1f(TomVM& vm){glMapGrid1f(vm.GetIntParam (3), vm.GetRealParam (2), vm.GetRealParam (1));}
void WrapglMapGrid2d(TomVM& vm){glMapGrid2d(vm.GetIntParam (6), vm.GetRealParam (5), vm.GetRealParam (4), vm.GetIntParam (3), vm.GetRealParam (2), vm.GetRealParam (1));}
void WrapglMapGrid2f(TomVM& vm){glMapGrid2f(vm.GetIntParam (6), vm.GetRealParam (5), vm.GetRealParam (4), vm.GetIntParam (3), vm.GetRealParam (2), vm.GetRealParam (1));}
void WrapglMaterialf(TomVM& vm){glMaterialf(vm.GetIntParam (3), vm.GetIntParam (2), vm.GetRealParam (1));}
void WrapglMaterialfv(TomVM& vm){GLfloat a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	glMaterialfv(vm.GetIntParam (3), vm.GetIntParam (2), a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	}
void WrapglMaterialfv_2(TomVM& vm){GLfloat a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).RealVal();
	glMaterialfv(vm.GetIntParam (3), vm.GetIntParam (2), a1);
	vm.GetRefParam(1).RealVal()=a1[0];
	}
void WrapglMateriali(TomVM& vm){glMateriali(vm.GetIntParam (3), vm.GetIntParam (2), vm.GetIntParam (1));}
void WrapglMaterialiv(TomVM& vm){GLint a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	glMaterialiv(vm.GetIntParam (3), vm.GetIntParam (2), a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	}
void WrapglMaterialiv_2(TomVM& vm){GLint a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).IntVal();
	glMaterialiv(vm.GetIntParam (3), vm.GetIntParam (2), a1);
	vm.GetRefParam(1).IntVal()=a1[0];
	}
void WrapglMatrixMode(TomVM& vm){glMatrixMode(vm.GetIntParam (1));}
void WrapglNewList(TomVM& vm){glNewList(vm.GetIntParam (2), vm.GetIntParam (1));}
void WrapglNormal3b(TomVM& vm){glNormal3b(vm.GetIntParam (3), vm.GetIntParam (2), vm.GetIntParam (1));}
void WrapglNormal3bv(TomVM& vm){GLbyte a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	glNormal3bv(a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	}
void WrapglNormal3bv_2(TomVM& vm){GLbyte a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).IntVal();
	glNormal3bv(a1);
	vm.GetRefParam(1).IntVal()=a1[0];
	}
void WrapglNormal3d(TomVM& vm){glNormal3d(vm.GetRealParam (3), vm.GetRealParam (2), vm.GetRealParam (1));}
void WrapglNormal3dv(TomVM& vm){GLdouble a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	glNormal3dv(a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	}
void WrapglNormal3dv_2(TomVM& vm){GLdouble a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).RealVal();
	glNormal3dv(a1);
	vm.GetRefParam(1).RealVal()=a1[0];
	}
void WrapglNormal3f(TomVM& vm){glNormal3f(vm.GetRealParam (3), vm.GetRealParam (2), vm.GetRealParam (1));}
void WrapglNormal3fv(TomVM& vm){GLfloat a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	glNormal3fv(a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	}
void WrapglNormal3fv_2(TomVM& vm){GLfloat a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).RealVal();
	glNormal3fv(a1);
	vm.GetRefParam(1).RealVal()=a1[0];
	}
void WrapglNormal3i(TomVM& vm){glNormal3i(vm.GetIntParam (3), vm.GetIntParam (2), vm.GetIntParam (1));}
void WrapglNormal3iv(TomVM& vm){GLint a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	glNormal3iv(a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	}
void WrapglNormal3iv_2(TomVM& vm){GLint a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).IntVal();
	glNormal3iv(a1);
	vm.GetRefParam(1).IntVal()=a1[0];
	}
void WrapglNormal3s(TomVM& vm){glNormal3s(vm.GetIntParam (3), vm.GetIntParam (2), vm.GetIntParam (1));}
void WrapglNormal3sv(TomVM& vm){GLshort a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	glNormal3sv(a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	}
void WrapglNormal3sv_2(TomVM& vm){GLshort a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).IntVal();
	glNormal3sv(a1);
	vm.GetRefParam(1).IntVal()=a1[0];
	}
void WrapglOrtho(TomVM& vm){glOrtho(vm.GetRealParam (6), vm.GetRealParam (5), vm.GetRealParam (4), vm.GetRealParam (3), vm.GetRealParam (2), vm.GetRealParam (1));}
void WrapglPassThrough(TomVM& vm){glPassThrough(vm.GetRealParam (1));}
void WrapglPixelStoref(TomVM& vm){glPixelStoref(vm.GetIntParam (2), vm.GetRealParam (1));}
void WrapglPixelStorei(TomVM& vm){glPixelStorei(vm.GetIntParam (2), vm.GetIntParam (1));}
void WrapglPixelTransferf(TomVM& vm){glPixelTransferf(vm.GetIntParam (2), vm.GetRealParam (1));}
void WrapglPixelTransferi(TomVM& vm){glPixelTransferi(vm.GetIntParam (2), vm.GetIntParam (1));}
void WrapglPixelZoom(TomVM& vm){glPixelZoom(vm.GetRealParam (2), vm.GetRealParam (1));}
void WrapglPointSize(TomVM& vm){glPointSize(vm.GetRealParam (1));}
void WrapglPolygonMode(TomVM& vm){glPolygonMode(vm.GetIntParam (2), vm.GetIntParam (1));}
void WrapglPolygonOffset(TomVM& vm){glPolygonOffset(vm.GetRealParam (2), vm.GetRealParam (1));}
void WrapglPopAttrib(TomVM& vm){glPopAttrib();}
void WrapglPopClientAttrib(TomVM& vm){glPopClientAttrib();}
void WrapglPopMatrix(TomVM& vm){glPopMatrix();}
void WrapglPopName(TomVM& vm){glPopName();}

/*
void WrapglPrioritizeTextures(TomVM& vm){if(!ValidateSizeParam(vm,3))return;GLuint a1[65536];
	ReadAndZero(vm.Data(),vm.GetIntParam(2),vmValType(VTP_INT,1,1,true),a1,vm.GetIntParam(3));
	GLclampf a2[65536];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a2,vm.GetIntParam(3));
	glPrioritizeTextures(vm.GetIntParam (3), a1, a2);
	WriteArray(vm.Data(),vm.GetIntParam(2),vmValType(VTP_INT,1,1,true),a1,vm.GetIntParam(3));

	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a2,vm.GetIntParam(3));
	}
*/

void WrapglPushAttrib(TomVM& vm){glPushAttrib(vm.GetIntParam (1));}
void WrapglPushClientAttrib(TomVM& vm){glPushClientAttrib(vm.GetIntParam (1));}
void WrapglPushMatrix(TomVM& vm){glPushMatrix();}
void WrapglPushName(TomVM& vm){glPushName(vm.GetIntParam (1));}
void WrapglRasterPos2d(TomVM& vm){glRasterPos2d(vm.GetRealParam (2), vm.GetRealParam (1));}
void WrapglRasterPos2dv(TomVM& vm){GLdouble a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	glRasterPos2dv(a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	}
void WrapglRasterPos2dv_2(TomVM& vm){GLdouble a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).RealVal();
	glRasterPos2dv(a1);
	vm.GetRefParam(1).RealVal()=a1[0];
	}
void WrapglRasterPos2f(TomVM& vm){glRasterPos2f(vm.GetRealParam (2), vm.GetRealParam (1));}
void WrapglRasterPos2fv(TomVM& vm){GLfloat a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	glRasterPos2fv(a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	}
void WrapglRasterPos2fv_2(TomVM& vm){GLfloat a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).RealVal();
	glRasterPos2fv(a1);
	vm.GetRefParam(1).RealVal()=a1[0];
	}
void WrapglRasterPos2i(TomVM& vm){glRasterPos2i(vm.GetIntParam (2), vm.GetIntParam (1));}
void WrapglRasterPos2iv(TomVM& vm){GLint a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	glRasterPos2iv(a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	}
void WrapglRasterPos2iv_2(TomVM& vm){GLint a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).IntVal();
	glRasterPos2iv(a1);
	vm.GetRefParam(1).IntVal()=a1[0];
	}
void WrapglRasterPos2s(TomVM& vm){glRasterPos2s(vm.GetIntParam (2), vm.GetIntParam (1));}
void WrapglRasterPos2sv(TomVM& vm){GLshort a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	glRasterPos2sv(a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	}
void WrapglRasterPos2sv_2(TomVM& vm){GLshort a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).IntVal();
	glRasterPos2sv(a1);
	vm.GetRefParam(1).IntVal()=a1[0];
	}
void WrapglRasterPos3d(TomVM& vm){glRasterPos3d(vm.GetRealParam (3), vm.GetRealParam (2), vm.GetRealParam (1));}
void WrapglRasterPos3dv(TomVM& vm){GLdouble a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	glRasterPos3dv(a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	}
void WrapglRasterPos3dv_2(TomVM& vm){GLdouble a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).RealVal();
	glRasterPos3dv(a1);
	vm.GetRefParam(1).RealVal()=a1[0];
	}
void WrapglRasterPos3f(TomVM& vm){glRasterPos3f(vm.GetRealParam (3), vm.GetRealParam (2), vm.GetRealParam (1));}
void WrapglRasterPos3fv(TomVM& vm){GLfloat a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	glRasterPos3fv(a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	}
void WrapglRasterPos3fv_2(TomVM& vm){GLfloat a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).RealVal();
	glRasterPos3fv(a1);
	vm.GetRefParam(1).RealVal()=a1[0];
	}
void WrapglRasterPos3i(TomVM& vm){glRasterPos3i(vm.GetIntParam (3), vm.GetIntParam (2), vm.GetIntParam (1));}
void WrapglRasterPos3iv(TomVM& vm){GLint a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	glRasterPos3iv(a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	}
void WrapglRasterPos3iv_2(TomVM& vm){GLint a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).IntVal();
	glRasterPos3iv(a1);
	vm.GetRefParam(1).IntVal()=a1[0];
	}
void WrapglRasterPos3s(TomVM& vm){glRasterPos3s(vm.GetIntParam (3), vm.GetIntParam (2), vm.GetIntParam (1));}
void WrapglRasterPos3sv(TomVM& vm){GLshort a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	glRasterPos3sv(a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	}
void WrapglRasterPos3sv_2(TomVM& vm){GLshort a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).IntVal();
	glRasterPos3sv(a1);
	vm.GetRefParam(1).IntVal()=a1[0];
	}
void WrapglRasterPos4d(TomVM& vm){glRasterPos4d(vm.GetRealParam (4), vm.GetRealParam (3), vm.GetRealParam (2), vm.GetRealParam (1));}
void WrapglRasterPos4dv(TomVM& vm){GLdouble a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	glRasterPos4dv(a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	}
void WrapglRasterPos4dv_2(TomVM& vm){GLdouble a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).RealVal();
	glRasterPos4dv(a1);
	vm.GetRefParam(1).RealVal()=a1[0];
	}
void WrapglRasterPos4f(TomVM& vm){glRasterPos4f(vm.GetRealParam (4), vm.GetRealParam (3), vm.GetRealParam (2), vm.GetRealParam (1));}
void WrapglRasterPos4fv(TomVM& vm){GLfloat a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	glRasterPos4fv(a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	}
void WrapglRasterPos4fv_2(TomVM& vm){GLfloat a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).RealVal();
	glRasterPos4fv(a1);
	vm.GetRefParam(1).RealVal()=a1[0];
	}
void WrapglRasterPos4i(TomVM& vm){glRasterPos4i(vm.GetIntParam (4), vm.GetIntParam (3), vm.GetIntParam (2), vm.GetIntParam (1));}
void WrapglRasterPos4iv(TomVM& vm){GLint a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	glRasterPos4iv(a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	}
void WrapglRasterPos4iv_2(TomVM& vm){GLint a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).IntVal();
	glRasterPos4iv(a1);
	vm.GetRefParam(1).IntVal()=a1[0];
	}
void WrapglRasterPos4s(TomVM& vm){glRasterPos4s(vm.GetIntParam (4), vm.GetIntParam (3), vm.GetIntParam (2), vm.GetIntParam (1));}
void WrapglRasterPos4sv(TomVM& vm){GLshort a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	glRasterPos4sv(a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	}
void WrapglRasterPos4sv_2(TomVM& vm){GLshort a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).IntVal();
	glRasterPos4sv(a1);
	vm.GetRefParam(1).IntVal()=a1[0];
	}
void WrapglReadBuffer(TomVM& vm){glReadBuffer(vm.GetIntParam (1));}
void WrapglRectd(TomVM& vm){glRectd(vm.GetRealParam (4), vm.GetRealParam (3), vm.GetRealParam (2), vm.GetRealParam (1));}
void WrapglRectdv(TomVM& vm){GLdouble a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(2),vmValType(VTP_REAL,1,1,true),a1,16);
	GLdouble a2[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a2,16);
	glRectdv(a1, a2);
	WriteArray(vm.Data(),vm.GetIntParam(2),vmValType(VTP_REAL,1,1,true),a1,16);

	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a2,16);
	}
void WrapglRectdv_2(TomVM& vm){GLdouble a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(2))return;a1[0]=vm.GetRefParam(2).RealVal();
	GLdouble a2[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a2,16);
	glRectdv(a1, a2);
	vm.GetRefParam(2).RealVal()=a1[0];

	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a2,16);
	}
void WrapglRectdv_3(TomVM& vm){GLdouble a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(2),vmValType(VTP_REAL,1,1,true),a1,16);
	GLdouble a2[16];ZeroArray(a2,16);
	if(!vm.CheckNullRefParam(1))return;a2[0]=vm.GetRefParam(1).RealVal();
	glRectdv(a1, a2);
	WriteArray(vm.Data(),vm.GetIntParam(2),vmValType(VTP_REAL,1,1,true),a1,16);

	vm.GetRefParam(1).RealVal()=a2[0];
	}
void WrapglRectdv_4(TomVM& vm){GLdouble a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(2))return;a1[0]=vm.GetRefParam(2).RealVal();
	GLdouble a2[16];ZeroArray(a2,16);
	if(!vm.CheckNullRefParam(1))return;a2[0]=vm.GetRefParam(1).RealVal();
	glRectdv(a1, a2);
	vm.GetRefParam(2).RealVal()=a1[0];

	vm.GetRefParam(1).RealVal()=a2[0];
	}
void WrapglRectf(TomVM& vm){glRectf(vm.GetRealParam (4), vm.GetRealParam (3), vm.GetRealParam (2), vm.GetRealParam (1));}
void WrapglRectfv(TomVM& vm){GLfloat a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(2),vmValType(VTP_REAL,1,1,true),a1,16);
	GLfloat a2[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a2,16);
	glRectfv(a1, a2);
	WriteArray(vm.Data(),vm.GetIntParam(2),vmValType(VTP_REAL,1,1,true),a1,16);

	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a2,16);
	}
void WrapglRectfv_2(TomVM& vm){GLfloat a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(2))return;a1[0]=vm.GetRefParam(2).RealVal();
	GLfloat a2[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a2,16);
	glRectfv(a1, a2);
	vm.GetRefParam(2).RealVal()=a1[0];

	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a2,16);
	}
void WrapglRectfv_3(TomVM& vm){GLfloat a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(2),vmValType(VTP_REAL,1,1,true),a1,16);
	GLfloat a2[16];ZeroArray(a2,16);
	if(!vm.CheckNullRefParam(1))return;a2[0]=vm.GetRefParam(1).RealVal();
	glRectfv(a1, a2);
	WriteArray(vm.Data(),vm.GetIntParam(2),vmValType(VTP_REAL,1,1,true),a1,16);

	vm.GetRefParam(1).RealVal()=a2[0];
	}
void WrapglRectfv_4(TomVM& vm){GLfloat a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(2))return;a1[0]=vm.GetRefParam(2).RealVal();
	GLfloat a2[16];ZeroArray(a2,16);
	if(!vm.CheckNullRefParam(1))return;a2[0]=vm.GetRefParam(1).RealVal();
	glRectfv(a1, a2);
	vm.GetRefParam(2).RealVal()=a1[0];

	vm.GetRefParam(1).RealVal()=a2[0];
	}
void WrapglRecti(TomVM& vm){glRecti(vm.GetIntParam (4), vm.GetIntParam (3), vm.GetIntParam (2), vm.GetIntParam (1));}
void WrapglRectiv(TomVM& vm){GLint a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(2),vmValType(VTP_INT,1,1,true),a1,16);
	GLint a2[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a2,16);
	glRectiv(a1, a2);
	WriteArray(vm.Data(),vm.GetIntParam(2),vmValType(VTP_INT,1,1,true),a1,16);

	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a2,16);
	}
void WrapglRectiv_2(TomVM& vm){GLint a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(2))return;a1[0]=vm.GetRefParam(2).IntVal();
	GLint a2[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a2,16);
	glRectiv(a1, a2);
	vm.GetRefParam(2).IntVal()=a1[0];

	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a2,16);
	}
void WrapglRectiv_3(TomVM& vm){GLint a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(2),vmValType(VTP_INT,1,1,true),a1,16);
	GLint a2[16];ZeroArray(a2,16);
	if(!vm.CheckNullRefParam(1))return;a2[0]=vm.GetRefParam(1).IntVal();
	glRectiv(a1, a2);
	WriteArray(vm.Data(),vm.GetIntParam(2),vmValType(VTP_INT,1,1,true),a1,16);

	vm.GetRefParam(1).IntVal()=a2[0];
	}
void WrapglRectiv_4(TomVM& vm){GLint a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(2))return;a1[0]=vm.GetRefParam(2).IntVal();
	GLint a2[16];ZeroArray(a2,16);
	if(!vm.CheckNullRefParam(1))return;a2[0]=vm.GetRefParam(1).IntVal();
	glRectiv(a1, a2);
	vm.GetRefParam(2).IntVal()=a1[0];

	vm.GetRefParam(1).IntVal()=a2[0];
	}
void WrapglRects(TomVM& vm){glRects(vm.GetIntParam (4), vm.GetIntParam (3), vm.GetIntParam (2), vm.GetIntParam (1));}
void WrapglRectsv(TomVM& vm){GLshort a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(2),vmValType(VTP_INT,1,1,true),a1,16);
	GLshort a2[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a2,16);
	glRectsv(a1, a2);
	WriteArray(vm.Data(),vm.GetIntParam(2),vmValType(VTP_INT,1,1,true),a1,16);

	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a2,16);
	}
void WrapglRectsv_2(TomVM& vm){GLshort a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(2))return;a1[0]=vm.GetRefParam(2).IntVal();
	GLshort a2[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a2,16);
	glRectsv(a1, a2);
	vm.GetRefParam(2).IntVal()=a1[0];

	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a2,16);
	}
void WrapglRectsv_3(TomVM& vm){GLshort a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(2),vmValType(VTP_INT,1,1,true),a1,16);
	GLshort a2[16];ZeroArray(a2,16);
	if(!vm.CheckNullRefParam(1))return;a2[0]=vm.GetRefParam(1).IntVal();
	glRectsv(a1, a2);
	WriteArray(vm.Data(),vm.GetIntParam(2),vmValType(VTP_INT,1,1,true),a1,16);

	vm.GetRefParam(1).IntVal()=a2[0];
	}
void WrapglRectsv_4(TomVM& vm){GLshort a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(2))return;a1[0]=vm.GetRefParam(2).IntVal();
	GLshort a2[16];ZeroArray(a2,16);
	if(!vm.CheckNullRefParam(1))return;a2[0]=vm.GetRefParam(1).IntVal();
	glRectsv(a1, a2);
	vm.GetRefParam(2).IntVal()=a1[0];

	vm.GetRefParam(1).IntVal()=a2[0];
	}
void WrapglRenderMode(TomVM& vm){vm.Reg ().IntVal () = glRenderMode(vm.GetIntParam (1));}
void WrapglRotated(TomVM& vm){glRotated(vm.GetRealParam (4), vm.GetRealParam (3), vm.GetRealParam (2), vm.GetRealParam (1));}
void WrapglRotatef(TomVM& vm){glRotatef(vm.GetRealParam (4), vm.GetRealParam (3), vm.GetRealParam (2), vm.GetRealParam (1));}
void WrapglScaled(TomVM& vm){glScaled(vm.GetRealParam (3), vm.GetRealParam (2), vm.GetRealParam (1));}
void WrapglScalef(TomVM& vm){glScalef(vm.GetRealParam (3), vm.GetRealParam (2), vm.GetRealParam (1));}
void WrapglScissor(TomVM& vm){glScissor(vm.GetIntParam (4), vm.GetIntParam (3), vm.GetIntParam (2), vm.GetIntParam (1));}

/*
void WrapglSelectBuffer(TomVM& vm){if(!ValidateSizeParam(vm,2))return;GLuint a1[65536];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,vm.GetIntParam(2));
	glSelectBuffer(vm.GetIntParam (2), a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,vm.GetIntParam(2));
	}
*/

void WrapglShadeModel(TomVM& vm){glShadeModel(vm.GetIntParam (1));}
void WrapglStencilFunc(TomVM& vm){glStencilFunc(vm.GetIntParam (3), vm.GetIntParam (2), vm.GetIntParam (1));}
void WrapglStencilMask(TomVM& vm){glStencilMask(vm.GetIntParam (1));}
void WrapglStencilOp(TomVM& vm){glStencilOp(vm.GetIntParam (3), vm.GetIntParam (2), vm.GetIntParam (1));}
void WrapglTexCoord1d(TomVM& vm){glTexCoord1d(vm.GetRealParam (1));}
void WrapglTexCoord1dv(TomVM& vm){GLdouble a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	glTexCoord1dv(a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	}
void WrapglTexCoord1dv_2(TomVM& vm){GLdouble a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).RealVal();
	glTexCoord1dv(a1);
	vm.GetRefParam(1).RealVal()=a1[0];
	}
void WrapglTexCoord1f(TomVM& vm){glTexCoord1f(vm.GetRealParam (1));}
void WrapglTexCoord1fv(TomVM& vm){GLfloat a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	glTexCoord1fv(a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	}
void WrapglTexCoord1fv_2(TomVM& vm){GLfloat a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).RealVal();
	glTexCoord1fv(a1);
	vm.GetRefParam(1).RealVal()=a1[0];
	}
void WrapglTexCoord1i(TomVM& vm){glTexCoord1i(vm.GetIntParam (1));}
void WrapglTexCoord1iv(TomVM& vm){GLint a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	glTexCoord1iv(a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	}
void WrapglTexCoord1iv_2(TomVM& vm){GLint a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).IntVal();
	glTexCoord1iv(a1);
	vm.GetRefParam(1).IntVal()=a1[0];
	}
void WrapglTexCoord1s(TomVM& vm){glTexCoord1s(vm.GetIntParam (1));}
void WrapglTexCoord1sv(TomVM& vm){GLshort a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	glTexCoord1sv(a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	}
void WrapglTexCoord1sv_2(TomVM& vm){GLshort a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).IntVal();
	glTexCoord1sv(a1);
	vm.GetRefParam(1).IntVal()=a1[0];
	}
void WrapglTexCoord2d(TomVM& vm){glTexCoord2d(vm.GetRealParam (2), vm.GetRealParam (1));}
void WrapglTexCoord2dv(TomVM& vm){GLdouble a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	glTexCoord2dv(a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	}
void WrapglTexCoord2dv_2(TomVM& vm){GLdouble a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).RealVal();
	glTexCoord2dv(a1);
	vm.GetRefParam(1).RealVal()=a1[0];
	}
void WrapglTexCoord2f(TomVM& vm){glTexCoord2f(vm.GetRealParam (2), vm.GetRealParam (1));}
void WrapglTexCoord2fv(TomVM& vm){GLfloat a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	glTexCoord2fv(a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	}
void WrapglTexCoord2fv_2(TomVM& vm){GLfloat a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).RealVal();
	glTexCoord2fv(a1);
	vm.GetRefParam(1).RealVal()=a1[0];
	}
void WrapglTexCoord2i(TomVM& vm){glTexCoord2i(vm.GetIntParam (2), vm.GetIntParam (1));}
void WrapglTexCoord2iv(TomVM& vm){GLint a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	glTexCoord2iv(a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	}
void WrapglTexCoord2iv_2(TomVM& vm){GLint a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).IntVal();
	glTexCoord2iv(a1);
	vm.GetRefParam(1).IntVal()=a1[0];
	}
void WrapglTexCoord2s(TomVM& vm){glTexCoord2s(vm.GetIntParam (2), vm.GetIntParam (1));}
void WrapglTexCoord2sv(TomVM& vm){GLshort a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	glTexCoord2sv(a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	}
void WrapglTexCoord2sv_2(TomVM& vm){GLshort a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).IntVal();
	glTexCoord2sv(a1);
	vm.GetRefParam(1).IntVal()=a1[0];
	}
void WrapglTexCoord3d(TomVM& vm){glTexCoord3d(vm.GetRealParam (3), vm.GetRealParam (2), vm.GetRealParam (1));}
void WrapglTexCoord3dv(TomVM& vm){GLdouble a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	glTexCoord3dv(a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	}
void WrapglTexCoord3dv_2(TomVM& vm){GLdouble a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).RealVal();
	glTexCoord3dv(a1);
	vm.GetRefParam(1).RealVal()=a1[0];
	}
void WrapglTexCoord3f(TomVM& vm){glTexCoord3f(vm.GetRealParam (3), vm.GetRealParam (2), vm.GetRealParam (1));}
void WrapglTexCoord3fv(TomVM& vm){GLfloat a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	glTexCoord3fv(a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	}
void WrapglTexCoord3fv_2(TomVM& vm){GLfloat a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).RealVal();
	glTexCoord3fv(a1);
	vm.GetRefParam(1).RealVal()=a1[0];
	}
void WrapglTexCoord3i(TomVM& vm){glTexCoord3i(vm.GetIntParam (3), vm.GetIntParam (2), vm.GetIntParam (1));}
void WrapglTexCoord3iv(TomVM& vm){GLint a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	glTexCoord3iv(a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	}
void WrapglTexCoord3iv_2(TomVM& vm){GLint a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).IntVal();
	glTexCoord3iv(a1);
	vm.GetRefParam(1).IntVal()=a1[0];
	}
void WrapglTexCoord3s(TomVM& vm){glTexCoord3s(vm.GetIntParam (3), vm.GetIntParam (2), vm.GetIntParam (1));}
void WrapglTexCoord3sv(TomVM& vm){GLshort a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	glTexCoord3sv(a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	}
void WrapglTexCoord3sv_2(TomVM& vm){GLshort a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).IntVal();
	glTexCoord3sv(a1);
	vm.GetRefParam(1).IntVal()=a1[0];
	}
void WrapglTexCoord4d(TomVM& vm){glTexCoord4d(vm.GetRealParam (4), vm.GetRealParam (3), vm.GetRealParam (2), vm.GetRealParam (1));}
void WrapglTexCoord4dv(TomVM& vm){GLdouble a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	glTexCoord4dv(a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	}
void WrapglTexCoord4dv_2(TomVM& vm){GLdouble a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).RealVal();
	glTexCoord4dv(a1);
	vm.GetRefParam(1).RealVal()=a1[0];
	}
void WrapglTexCoord4f(TomVM& vm){glTexCoord4f(vm.GetRealParam (4), vm.GetRealParam (3), vm.GetRealParam (2), vm.GetRealParam (1));}
void WrapglTexCoord4fv(TomVM& vm){GLfloat a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	glTexCoord4fv(a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	}
void WrapglTexCoord4fv_2(TomVM& vm){GLfloat a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).RealVal();
	glTexCoord4fv(a1);
	vm.GetRefParam(1).RealVal()=a1[0];
	}
void WrapglTexCoord4i(TomVM& vm){glTexCoord4i(vm.GetIntParam (4), vm.GetIntParam (3), vm.GetIntParam (2), vm.GetIntParam (1));}
void WrapglTexCoord4iv(TomVM& vm){GLint a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	glTexCoord4iv(a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	}
void WrapglTexCoord4iv_2(TomVM& vm){GLint a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).IntVal();
	glTexCoord4iv(a1);
	vm.GetRefParam(1).IntVal()=a1[0];
	}
void WrapglTexCoord4s(TomVM& vm){glTexCoord4s(vm.GetIntParam (4), vm.GetIntParam (3), vm.GetIntParam (2), vm.GetIntParam (1));}
void WrapglTexCoord4sv(TomVM& vm){GLshort a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	glTexCoord4sv(a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	}
void WrapglTexCoord4sv_2(TomVM& vm){GLshort a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).IntVal();
	glTexCoord4sv(a1);
	vm.GetRefParam(1).IntVal()=a1[0];
	}
void WrapglTexEnvf(TomVM& vm){glTexEnvf(vm.GetIntParam (3), vm.GetIntParam (2), vm.GetRealParam (1));}
void WrapglTexEnvfv(TomVM& vm){GLfloat a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	glTexEnvfv(vm.GetIntParam (3), vm.GetIntParam (2), a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	}
void WrapglTexEnvfv_2(TomVM& vm){GLfloat a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).RealVal();
	glTexEnvfv(vm.GetIntParam (3), vm.GetIntParam (2), a1);
	vm.GetRefParam(1).RealVal()=a1[0];
	}
void WrapglTexEnvi(TomVM& vm){glTexEnvi(vm.GetIntParam (3), vm.GetIntParam (2), vm.GetIntParam (1));}
void WrapglTexEnviv(TomVM& vm){GLint a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	glTexEnviv(vm.GetIntParam (3), vm.GetIntParam (2), a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	}
void WrapglTexEnviv_2(TomVM& vm){GLint a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).IntVal();
	glTexEnviv(vm.GetIntParam (3), vm.GetIntParam (2), a1);
	vm.GetRefParam(1).IntVal()=a1[0];
	}
void WrapglTexGend(TomVM& vm){glTexGend(vm.GetIntParam (3), vm.GetIntParam (2), vm.GetRealParam (1));}
void WrapglTexGendv(TomVM& vm){GLdouble a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	glTexGendv(vm.GetIntParam (3), vm.GetIntParam (2), a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	}
void WrapglTexGendv_2(TomVM& vm){GLdouble a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).RealVal();
	glTexGendv(vm.GetIntParam (3), vm.GetIntParam (2), a1);
	vm.GetRefParam(1).RealVal()=a1[0];
	}
void WrapglTexGenf(TomVM& vm){glTexGenf(vm.GetIntParam (3), vm.GetIntParam (2), vm.GetRealParam (1));}
void WrapglTexGenfv(TomVM& vm){GLfloat a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	glTexGenfv(vm.GetIntParam (3), vm.GetIntParam (2), a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	}
void WrapglTexGenfv_2(TomVM& vm){GLfloat a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).RealVal();
	glTexGenfv(vm.GetIntParam (3), vm.GetIntParam (2), a1);
	vm.GetRefParam(1).RealVal()=a1[0];
	}
void WrapglTexGeni(TomVM& vm){glTexGeni(vm.GetIntParam (3), vm.GetIntParam (2), vm.GetIntParam (1));}
void WrapglTexGeniv(TomVM& vm){GLint a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	glTexGeniv(vm.GetIntParam (3), vm.GetIntParam (2), a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	}
void WrapglTexGeniv_2(TomVM& vm){GLint a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).IntVal();
	glTexGeniv(vm.GetIntParam (3), vm.GetIntParam (2), a1);
	vm.GetRefParam(1).IntVal()=a1[0];
	}
void WrapglTexParameterf(TomVM& vm){glTexParameterf(vm.GetIntParam (3), vm.GetIntParam (2), vm.GetRealParam (1));}
void WrapglTexParameterfv(TomVM& vm){GLfloat a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	glTexParameterfv(vm.GetIntParam (3), vm.GetIntParam (2), a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	}
void WrapglTexParameterfv_2(TomVM& vm){GLfloat a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).RealVal();
	glTexParameterfv(vm.GetIntParam (3), vm.GetIntParam (2), a1);
	vm.GetRefParam(1).RealVal()=a1[0];
	}
void WrapglTexParameteri(TomVM& vm){glTexParameteri(vm.GetIntParam (3), vm.GetIntParam (2), vm.GetIntParam (1));}
void WrapglTexParameteriv(TomVM& vm){GLint a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	glTexParameteriv(vm.GetIntParam (3), vm.GetIntParam (2), a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	}
void WrapglTexParameteriv_2(TomVM& vm){GLint a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).IntVal();
	glTexParameteriv(vm.GetIntParam (3), vm.GetIntParam (2), a1);
	vm.GetRefParam(1).IntVal()=a1[0];
	}
void WrapglTranslated(TomVM& vm){glTranslated(vm.GetRealParam (3), vm.GetRealParam (2), vm.GetRealParam (1));}
void WrapglTranslatef(TomVM& vm){glTranslatef(vm.GetRealParam (3), vm.GetRealParam (2), vm.GetRealParam (1));}
void WrapglVertex2d(TomVM& vm){glVertex2d(vm.GetRealParam (2), vm.GetRealParam (1));}
void WrapglVertex2dv(TomVM& vm){GLdouble a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	glVertex2dv(a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	}
void WrapglVertex2dv_2(TomVM& vm){GLdouble a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).RealVal();
	glVertex2dv(a1);
	vm.GetRefParam(1).RealVal()=a1[0];
	}
void WrapglVertex2f(TomVM& vm){glVertex2f(vm.GetRealParam (2), vm.GetRealParam (1));}
void WrapglVertex2fv(TomVM& vm){GLfloat a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	glVertex2fv(a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	}
void WrapglVertex2fv_2(TomVM& vm){GLfloat a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).RealVal();
	glVertex2fv(a1);
	vm.GetRefParam(1).RealVal()=a1[0];
	}
void WrapglVertex2i(TomVM& vm){glVertex2i(vm.GetIntParam (2), vm.GetIntParam (1));}
void WrapglVertex2iv(TomVM& vm){GLint a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	glVertex2iv(a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	}
void WrapglVertex2iv_2(TomVM& vm){GLint a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).IntVal();
	glVertex2iv(a1);
	vm.GetRefParam(1).IntVal()=a1[0];
	}
void WrapglVertex2s(TomVM& vm){glVertex2s(vm.GetIntParam (2), vm.GetIntParam (1));}
void WrapglVertex2sv(TomVM& vm){GLshort a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	glVertex2sv(a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	}
void WrapglVertex2sv_2(TomVM& vm){GLshort a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).IntVal();
	glVertex2sv(a1);
	vm.GetRefParam(1).IntVal()=a1[0];
	}
void WrapglVertex3d(TomVM& vm){glVertex3d(vm.GetRealParam (3), vm.GetRealParam (2), vm.GetRealParam (1));}
void WrapglVertex3dv(TomVM& vm){GLdouble a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	glVertex3dv(a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	}
void WrapglVertex3dv_2(TomVM& vm){GLdouble a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).RealVal();
	glVertex3dv(a1);
	vm.GetRefParam(1).RealVal()=a1[0];
	}
void WrapglVertex3f(TomVM& vm){glVertex3f(vm.GetRealParam (3), vm.GetRealParam (2), vm.GetRealParam (1));}
void WrapglVertex3fv(TomVM& vm){GLfloat a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	glVertex3fv(a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	}
void WrapglVertex3fv_2(TomVM& vm){GLfloat a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).RealVal();
	glVertex3fv(a1);
	vm.GetRefParam(1).RealVal()=a1[0];
	}
void WrapglVertex3i(TomVM& vm){glVertex3i(vm.GetIntParam (3), vm.GetIntParam (2), vm.GetIntParam (1));}
void WrapglVertex3iv(TomVM& vm){GLint a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	glVertex3iv(a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	}
void WrapglVertex3iv_2(TomVM& vm){GLint a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).IntVal();
	glVertex3iv(a1);
	vm.GetRefParam(1).IntVal()=a1[0];
	}
void WrapglVertex3s(TomVM& vm){glVertex3s(vm.GetIntParam (3), vm.GetIntParam (2), vm.GetIntParam (1));}
void WrapglVertex3sv(TomVM& vm){GLshort a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	glVertex3sv(a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	}
void WrapglVertex3sv_2(TomVM& vm){GLshort a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).IntVal();
	glVertex3sv(a1);
	vm.GetRefParam(1).IntVal()=a1[0];
	}
void WrapglVertex4d(TomVM& vm){glVertex4d(vm.GetRealParam (4), vm.GetRealParam (3), vm.GetRealParam (2), vm.GetRealParam (1));}
void WrapglVertex4dv(TomVM& vm){GLdouble a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	glVertex4dv(a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	}
void WrapglVertex4dv_2(TomVM& vm){GLdouble a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).RealVal();
	glVertex4dv(a1);
	vm.GetRefParam(1).RealVal()=a1[0];
	}
void WrapglVertex4f(TomVM& vm){glVertex4f(vm.GetRealParam (4), vm.GetRealParam (3), vm.GetRealParam (2), vm.GetRealParam (1));}
void WrapglVertex4fv(TomVM& vm){GLfloat a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	glVertex4fv(a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_REAL,1,1,true),a1,16);
	}
void WrapglVertex4fv_2(TomVM& vm){GLfloat a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).RealVal();
	glVertex4fv(a1);
	vm.GetRefParam(1).RealVal()=a1[0];
	}
void WrapglVertex4i(TomVM& vm){glVertex4i(vm.GetIntParam (4), vm.GetIntParam (3), vm.GetIntParam (2), vm.GetIntParam (1));}
void WrapglVertex4iv(TomVM& vm){GLint a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	glVertex4iv(a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	}
void WrapglVertex4iv_2(TomVM& vm){GLint a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).IntVal();
	glVertex4iv(a1);
	vm.GetRefParam(1).IntVal()=a1[0];
	}
void WrapglVertex4s(TomVM& vm){glVertex4s(vm.GetIntParam (4), vm.GetIntParam (3), vm.GetIntParam (2), vm.GetIntParam (1));}
void WrapglVertex4sv(TomVM& vm){GLshort a1[16];
	ReadAndZero(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	glVertex4sv(a1);
	WriteArray(vm.Data(),vm.GetIntParam(1),vmValType(VTP_INT,1,1,true),a1,16);
	}
void WrapglVertex4sv_2(TomVM& vm){GLshort a1[16];ZeroArray(a1,16);
	if(!vm.CheckNullRefParam(1))return;a1[0]=vm.GetRefParam(1).IntVal();
	glVertex4sv(a1);
	vm.GetRefParam(1).IntVal()=a1[0];
	}
void WrapglViewport(TomVM& vm){glViewport(vm.GetIntParam (4), vm.GetIntParam (3), vm.GetIntParam (2), vm.GetIntParam (1));}

void WrapglGenTexture(TomVM& vm) {
    GLuint texture = vm.GetIntParam(1);
	glGenTextures (vm.GetIntParam(2), &texture);
	vm.Reg().IntVal() = texture;
}


// Initialisation

void InitGLBasicLib_gl(TomBasicCompiler& comp) {

		// Add noParam TypeList //
		compParamTypeList noParam;

    // Constants
    comp.AddConstant("GL_VERSION_1_1", GL_VERSION_1_1);
    comp.AddConstant("GL_ACCUM", GL_ACCUM);
    comp.AddConstant("GL_LOAD", GL_LOAD);
    comp.AddConstant("GL_RETURN", GL_RETURN);
    comp.AddConstant("GL_MULT", GL_MULT);
    comp.AddConstant("GL_ADD", GL_ADD);
    comp.AddConstant("GL_NEVER", GL_NEVER);
    comp.AddConstant("GL_LESS", GL_LESS);
    comp.AddConstant("GL_EQUAL", GL_EQUAL);
    comp.AddConstant("GL_LEQUAL", GL_LEQUAL);
    comp.AddConstant("GL_GREATER", GL_GREATER);
    comp.AddConstant("GL_NOTEQUAL", GL_NOTEQUAL);
    comp.AddConstant("GL_GEQUAL", GL_GEQUAL);
    comp.AddConstant("GL_ALWAYS", GL_ALWAYS);
    comp.AddConstant("GL_CURRENT_BIT", GL_CURRENT_BIT);
    comp.AddConstant("GL_POINT_BIT", GL_POINT_BIT);
    comp.AddConstant("GL_LINE_BIT", GL_LINE_BIT);
    comp.AddConstant("GL_POLYGON_BIT", GL_POLYGON_BIT);
    comp.AddConstant("GL_POLYGON_STIPPLE_BIT", GL_POLYGON_STIPPLE_BIT);
    comp.AddConstant("GL_PIXEL_MODE_BIT", GL_PIXEL_MODE_BIT);
    comp.AddConstant("GL_LIGHTING_BIT", GL_LIGHTING_BIT);
    comp.AddConstant("GL_FOG_BIT", GL_FOG_BIT);
    comp.AddConstant("GL_DEPTH_BUFFER_BIT", GL_DEPTH_BUFFER_BIT);
    comp.AddConstant("GL_ACCUM_BUFFER_BIT", GL_ACCUM_BUFFER_BIT);
    comp.AddConstant("GL_STENCIL_BUFFER_BIT", GL_STENCIL_BUFFER_BIT);
    comp.AddConstant("GL_VIEWPORT_BIT", GL_VIEWPORT_BIT);
    comp.AddConstant("GL_TRANSFORM_BIT", GL_TRANSFORM_BIT);
    comp.AddConstant("GL_ENABLE_BIT", GL_ENABLE_BIT);
    comp.AddConstant("GL_COLOR_BUFFER_BIT", GL_COLOR_BUFFER_BIT);
    comp.AddConstant("GL_HINT_BIT", GL_HINT_BIT);
    comp.AddConstant("GL_EVAL_BIT", GL_EVAL_BIT);
    comp.AddConstant("GL_LIST_BIT", GL_LIST_BIT);
    comp.AddConstant("GL_TEXTURE_BIT", GL_TEXTURE_BIT);
    comp.AddConstant("GL_SCISSOR_BIT", GL_SCISSOR_BIT);
    comp.AddConstant("GL_ALL_ATTRIB_BITS", GL_ALL_ATTRIB_BITS);
    comp.AddConstant("GL_POINTS", GL_POINTS);
    comp.AddConstant("GL_LINES", GL_LINES);
    comp.AddConstant("GL_LINE_LOOP", GL_LINE_LOOP);
    comp.AddConstant("GL_LINE_STRIP", GL_LINE_STRIP);
    comp.AddConstant("GL_TRIANGLES", GL_TRIANGLES);
    comp.AddConstant("GL_TRIANGLE_STRIP", GL_TRIANGLE_STRIP);
    comp.AddConstant("GL_TRIANGLE_FAN", GL_TRIANGLE_FAN);
    comp.AddConstant("GL_QUADS", GL_QUADS);
    comp.AddConstant("GL_QUAD_STRIP", GL_QUAD_STRIP);
    comp.AddConstant("GL_POLYGON", GL_POLYGON);
    comp.AddConstant("GL_ZERO", GL_ZERO);
    comp.AddConstant("GL_ONE", GL_ONE);
    comp.AddConstant("GL_SRC_COLOR", GL_SRC_COLOR);
    comp.AddConstant("GL_ONE_MINUS_SRC_COLOR", GL_ONE_MINUS_SRC_COLOR);
    comp.AddConstant("GL_SRC_ALPHA", GL_SRC_ALPHA);
    comp.AddConstant("GL_ONE_MINUS_SRC_ALPHA", GL_ONE_MINUS_SRC_ALPHA);
    comp.AddConstant("GL_DST_ALPHA", GL_DST_ALPHA);
    comp.AddConstant("GL_ONE_MINUS_DST_ALPHA", GL_ONE_MINUS_DST_ALPHA);
    comp.AddConstant("GL_DST_COLOR", GL_DST_COLOR);
    comp.AddConstant("GL_ONE_MINUS_DST_COLOR", GL_ONE_MINUS_DST_COLOR);
    comp.AddConstant("GL_SRC_ALPHA_SATURATE", GL_SRC_ALPHA_SATURATE);
    comp.AddConstant("GL_TRUE", GL_TRUE);
    comp.AddConstant("GL_FALSE", GL_FALSE);
    comp.AddConstant("GL_CLIP_PLANE0", GL_CLIP_PLANE0);
    comp.AddConstant("GL_CLIP_PLANE1", GL_CLIP_PLANE1);
    comp.AddConstant("GL_CLIP_PLANE2", GL_CLIP_PLANE2);
    comp.AddConstant("GL_CLIP_PLANE3", GL_CLIP_PLANE3);
    comp.AddConstant("GL_CLIP_PLANE4", GL_CLIP_PLANE4);
    comp.AddConstant("GL_CLIP_PLANE5", GL_CLIP_PLANE5);
    comp.AddConstant("GL_BYTE", GL_BYTE);
    comp.AddConstant("GL_UNSIGNED_BYTE", GL_UNSIGNED_BYTE);
    comp.AddConstant("GL_SHORT", GL_SHORT);
    comp.AddConstant("GL_UNSIGNED_SHORT", GL_UNSIGNED_SHORT);
    comp.AddConstant("GL_INT", GL_INT);
    comp.AddConstant("GL_UNSIGNED_INT", GL_UNSIGNED_INT);
    comp.AddConstant("GL_FLOAT", GL_FLOAT);
    comp.AddConstant("GL_2_BYTES", GL_2_BYTES);
    comp.AddConstant("GL_3_BYTES", GL_3_BYTES);
    comp.AddConstant("GL_4_BYTES", GL_4_BYTES);
    comp.AddConstant("GL_DOUBLE", GL_DOUBLE);
    comp.AddConstant("GL_NONE", GL_NONE);
    comp.AddConstant("GL_FRONT_LEFT", GL_FRONT_LEFT);
    comp.AddConstant("GL_FRONT_RIGHT", GL_FRONT_RIGHT);
    comp.AddConstant("GL_BACK_LEFT", GL_BACK_LEFT);
    comp.AddConstant("GL_BACK_RIGHT", GL_BACK_RIGHT);
    comp.AddConstant("GL_FRONT", GL_FRONT);
    comp.AddConstant("GL_BACK", GL_BACK);
    comp.AddConstant("GL_LEFT", GL_LEFT);
    comp.AddConstant("GL_RIGHT", GL_RIGHT);
    comp.AddConstant("GL_FRONT_AND_BACK", GL_FRONT_AND_BACK);
    comp.AddConstant("GL_AUX0", GL_AUX0);
    comp.AddConstant("GL_AUX1", GL_AUX1);
    comp.AddConstant("GL_AUX2", GL_AUX2);
    comp.AddConstant("GL_AUX3", GL_AUX3);
    comp.AddConstant("GL_NO_ERROR", GL_NO_ERROR);
    comp.AddConstant("GL_INVALID_ENUM", GL_INVALID_ENUM);
    comp.AddConstant("GL_INVALID_VALUE", GL_INVALID_VALUE);
    comp.AddConstant("GL_INVALID_OPERATION", GL_INVALID_OPERATION);
    comp.AddConstant("GL_STACK_OVERFLOW", GL_STACK_OVERFLOW);
    comp.AddConstant("GL_STACK_UNDERFLOW", GL_STACK_UNDERFLOW);
    comp.AddConstant("GL_OUT_OF_MEMORY", GL_OUT_OF_MEMORY);
    comp.AddConstant("GL_2D", GL_2D);
    comp.AddConstant("GL_3D", GL_3D);
    comp.AddConstant("GL_3D_COLOR", GL_3D_COLOR);
    comp.AddConstant("GL_3D_COLOR_TEXTURE", GL_3D_COLOR_TEXTURE);
    comp.AddConstant("GL_4D_COLOR_TEXTURE", GL_4D_COLOR_TEXTURE);
    comp.AddConstant("GL_PASS_THROUGH_TOKEN", GL_PASS_THROUGH_TOKEN);
    comp.AddConstant("GL_POINT_TOKEN", GL_POINT_TOKEN);
    comp.AddConstant("GL_LINE_TOKEN", GL_LINE_TOKEN);
    comp.AddConstant("GL_POLYGON_TOKEN", GL_POLYGON_TOKEN);
    comp.AddConstant("GL_BITMAP_TOKEN", GL_BITMAP_TOKEN);
    comp.AddConstant("GL_DRAW_PIXEL_TOKEN", GL_DRAW_PIXEL_TOKEN);
    comp.AddConstant("GL_COPY_PIXEL_TOKEN", GL_COPY_PIXEL_TOKEN);
    comp.AddConstant("GL_LINE_RESET_TOKEN", GL_LINE_RESET_TOKEN);
    comp.AddConstant("GL_EXP", GL_EXP);
    comp.AddConstant("GL_EXP2", GL_EXP2);
    comp.AddConstant("GL_CW", GL_CW);
    comp.AddConstant("GL_CCW", GL_CCW);
    comp.AddConstant("GL_COEFF", GL_COEFF);
    comp.AddConstant("GL_ORDER", GL_ORDER);
    comp.AddConstant("GL_DOMAIN", GL_DOMAIN);
    comp.AddConstant("GL_CURRENT_COLOR", GL_CURRENT_COLOR);
    comp.AddConstant("GL_CURRENT_INDEX", GL_CURRENT_INDEX);
    comp.AddConstant("GL_CURRENT_NORMAL", GL_CURRENT_NORMAL);
    comp.AddConstant("GL_CURRENT_TEXTURE_COORDS", GL_CURRENT_TEXTURE_COORDS);
    comp.AddConstant("GL_CURRENT_RASTER_COLOR", GL_CURRENT_RASTER_COLOR);
    comp.AddConstant("GL_CURRENT_RASTER_INDEX", GL_CURRENT_RASTER_INDEX);
    comp.AddConstant("GL_CURRENT_RASTER_TEXTURE_COORDS", GL_CURRENT_RASTER_TEXTURE_COORDS);
    comp.AddConstant("GL_CURRENT_RASTER_POSITION", GL_CURRENT_RASTER_POSITION);
    comp.AddConstant("GL_CURRENT_RASTER_POSITION_VALID", GL_CURRENT_RASTER_POSITION_VALID);
    comp.AddConstant("GL_CURRENT_RASTER_DISTANCE", GL_CURRENT_RASTER_DISTANCE);
    comp.AddConstant("GL_POINT_SMOOTH", GL_POINT_SMOOTH);
    comp.AddConstant("GL_POINT_SIZE", GL_POINT_SIZE);
    comp.AddConstant("GL_POINT_SIZE_RANGE", GL_POINT_SIZE_RANGE);
    comp.AddConstant("GL_POINT_SIZE_GRANULARITY", GL_POINT_SIZE_GRANULARITY);
    comp.AddConstant("GL_LINE_SMOOTH", GL_LINE_SMOOTH);
    comp.AddConstant("GL_LINE_WIDTH", GL_LINE_WIDTH);
    comp.AddConstant("GL_LINE_WIDTH_RANGE", GL_LINE_WIDTH_RANGE);
    comp.AddConstant("GL_LINE_WIDTH_GRANULARITY", GL_LINE_WIDTH_GRANULARITY);
    comp.AddConstant("GL_LINE_STIPPLE", GL_LINE_STIPPLE);
    comp.AddConstant("GL_LINE_STIPPLE_PATTERN", GL_LINE_STIPPLE_PATTERN);
    comp.AddConstant("GL_LINE_STIPPLE_REPEAT", GL_LINE_STIPPLE_REPEAT);
    comp.AddConstant("GL_LIST_MODE", GL_LIST_MODE);
    comp.AddConstant("GL_MAX_LIST_NESTING", GL_MAX_LIST_NESTING);
    comp.AddConstant("GL_LIST_BASE", GL_LIST_BASE);
    comp.AddConstant("GL_LIST_INDEX", GL_LIST_INDEX);
    comp.AddConstant("GL_POLYGON_MODE", GL_POLYGON_MODE);
    comp.AddConstant("GL_POLYGON_SMOOTH", GL_POLYGON_SMOOTH);
    comp.AddConstant("GL_POLYGON_STIPPLE", GL_POLYGON_STIPPLE);
    comp.AddConstant("GL_EDGE_FLAG", GL_EDGE_FLAG);
    comp.AddConstant("GL_CULL_FACE", GL_CULL_FACE);
    comp.AddConstant("GL_CULL_FACE_MODE", GL_CULL_FACE_MODE);
    comp.AddConstant("GL_FRONT_FACE", GL_FRONT_FACE);
    comp.AddConstant("GL_LIGHTING", GL_LIGHTING);
    comp.AddConstant("GL_LIGHT_MODEL_LOCAL_VIEWER", GL_LIGHT_MODEL_LOCAL_VIEWER);
    comp.AddConstant("GL_LIGHT_MODEL_TWO_SIDE", GL_LIGHT_MODEL_TWO_SIDE);
    comp.AddConstant("GL_LIGHT_MODEL_AMBIENT", GL_LIGHT_MODEL_AMBIENT);
    comp.AddConstant("GL_SHADE_MODEL", GL_SHADE_MODEL);
    comp.AddConstant("GL_COLOR_MATERIAL_FACE", GL_COLOR_MATERIAL_FACE);
    comp.AddConstant("GL_COLOR_MATERIAL_PARAMETER", GL_COLOR_MATERIAL_PARAMETER);
    comp.AddConstant("GL_COLOR_MATERIAL", GL_COLOR_MATERIAL);
    comp.AddConstant("GL_FOG", GL_FOG);
    comp.AddConstant("GL_FOG_INDEX", GL_FOG_INDEX);
    comp.AddConstant("GL_FOG_DENSITY", GL_FOG_DENSITY);
    comp.AddConstant("GL_FOG_START", GL_FOG_START);
    comp.AddConstant("GL_FOG_END", GL_FOG_END);
    comp.AddConstant("GL_FOG_MODE", GL_FOG_MODE);
    comp.AddConstant("GL_FOG_COLOR", GL_FOG_COLOR);
    comp.AddConstant("GL_DEPTH_RANGE", GL_DEPTH_RANGE);
    comp.AddConstant("GL_DEPTH_TEST", GL_DEPTH_TEST);
    comp.AddConstant("GL_DEPTH_WRITEMASK", GL_DEPTH_WRITEMASK);
    comp.AddConstant("GL_DEPTH_CLEAR_VALUE", GL_DEPTH_CLEAR_VALUE);
    comp.AddConstant("GL_DEPTH_FUNC", GL_DEPTH_FUNC);
    comp.AddConstant("GL_ACCUM_CLEAR_VALUE", GL_ACCUM_CLEAR_VALUE);
    comp.AddConstant("GL_STENCIL_TEST", GL_STENCIL_TEST);
    comp.AddConstant("GL_STENCIL_CLEAR_VALUE", GL_STENCIL_CLEAR_VALUE);
    comp.AddConstant("GL_STENCIL_FUNC", GL_STENCIL_FUNC);
    comp.AddConstant("GL_STENCIL_VALUE_MASK", GL_STENCIL_VALUE_MASK);
    comp.AddConstant("GL_STENCIL_FAIL", GL_STENCIL_FAIL);
    comp.AddConstant("GL_STENCIL_PASS_DEPTH_FAIL", GL_STENCIL_PASS_DEPTH_FAIL);
    comp.AddConstant("GL_STENCIL_PASS_DEPTH_PASS", GL_STENCIL_PASS_DEPTH_PASS);
    comp.AddConstant("GL_STENCIL_REF", GL_STENCIL_REF);
    comp.AddConstant("GL_STENCIL_WRITEMASK", GL_STENCIL_WRITEMASK);
    comp.AddConstant("GL_MATRIX_MODE", GL_MATRIX_MODE);
    comp.AddConstant("GL_NORMALIZE", GL_NORMALIZE);
    comp.AddConstant("GL_VIEWPORT", GL_VIEWPORT);
    comp.AddConstant("GL_MODELVIEW_STACK_DEPTH", GL_MODELVIEW_STACK_DEPTH);
    comp.AddConstant("GL_PROJECTION_STACK_DEPTH", GL_PROJECTION_STACK_DEPTH);
    comp.AddConstant("GL_TEXTURE_STACK_DEPTH", GL_TEXTURE_STACK_DEPTH);
    comp.AddConstant("GL_MODELVIEW_MATRIX", GL_MODELVIEW_MATRIX);
    comp.AddConstant("GL_PROJECTION_MATRIX", GL_PROJECTION_MATRIX);
    comp.AddConstant("GL_TEXTURE_MATRIX", GL_TEXTURE_MATRIX);
    comp.AddConstant("GL_ATTRIB_STACK_DEPTH", GL_ATTRIB_STACK_DEPTH);
    comp.AddConstant("GL_CLIENT_ATTRIB_STACK_DEPTH", GL_CLIENT_ATTRIB_STACK_DEPTH);
    comp.AddConstant("GL_ALPHA_TEST", GL_ALPHA_TEST);
    comp.AddConstant("GL_ALPHA_TEST_FUNC", GL_ALPHA_TEST_FUNC);
    comp.AddConstant("GL_ALPHA_TEST_REF", GL_ALPHA_TEST_REF);
    comp.AddConstant("GL_DITHER", GL_DITHER);
    comp.AddConstant("GL_BLEND_DST", GL_BLEND_DST);
    comp.AddConstant("GL_BLEND_SRC", GL_BLEND_SRC);
    comp.AddConstant("GL_BLEND", GL_BLEND);
    comp.AddConstant("GL_LOGIC_OP_MODE", GL_LOGIC_OP_MODE);
    comp.AddConstant("GL_INDEX_LOGIC_OP", GL_INDEX_LOGIC_OP);
    comp.AddConstant("GL_COLOR_LOGIC_OP", GL_COLOR_LOGIC_OP);
    comp.AddConstant("GL_AUX_BUFFERS", GL_AUX_BUFFERS);
    comp.AddConstant("GL_DRAW_BUFFER", GL_DRAW_BUFFER);
    comp.AddConstant("GL_READ_BUFFER", GL_READ_BUFFER);
    comp.AddConstant("GL_SCISSOR_BOX", GL_SCISSOR_BOX);
    comp.AddConstant("GL_SCISSOR_TEST", GL_SCISSOR_TEST);
    comp.AddConstant("GL_INDEX_CLEAR_VALUE", GL_INDEX_CLEAR_VALUE);
    comp.AddConstant("GL_INDEX_WRITEMASK", GL_INDEX_WRITEMASK);
    comp.AddConstant("GL_COLOR_CLEAR_VALUE", GL_COLOR_CLEAR_VALUE);
    comp.AddConstant("GL_COLOR_WRITEMASK", GL_COLOR_WRITEMASK);
    comp.AddConstant("GL_INDEX_MODE", GL_INDEX_MODE);
    comp.AddConstant("GL_RGBA_MODE", GL_RGBA_MODE);
    comp.AddConstant("GL_DOUBLEBUFFER", GL_DOUBLEBUFFER);
    comp.AddConstant("GL_STEREO", GL_STEREO);
    comp.AddConstant("GL_RENDER_MODE", GL_RENDER_MODE);
    comp.AddConstant("GL_PERSPECTIVE_CORRECTION_HINT", GL_PERSPECTIVE_CORRECTION_HINT);
    comp.AddConstant("GL_POINT_SMOOTH_HINT", GL_POINT_SMOOTH_HINT);
    comp.AddConstant("GL_LINE_SMOOTH_HINT", GL_LINE_SMOOTH_HINT);
    comp.AddConstant("GL_POLYGON_SMOOTH_HINT", GL_POLYGON_SMOOTH_HINT);
    comp.AddConstant("GL_FOG_HINT", GL_FOG_HINT);
    comp.AddConstant("GL_TEXTURE_GEN_S", GL_TEXTURE_GEN_S);
    comp.AddConstant("GL_TEXTURE_GEN_T", GL_TEXTURE_GEN_T);
    comp.AddConstant("GL_TEXTURE_GEN_R", GL_TEXTURE_GEN_R);
    comp.AddConstant("GL_TEXTURE_GEN_Q", GL_TEXTURE_GEN_Q);
    comp.AddConstant("GL_PIXEL_MAP_I_TO_I", GL_PIXEL_MAP_I_TO_I);
    comp.AddConstant("GL_PIXEL_MAP_S_TO_S", GL_PIXEL_MAP_S_TO_S);
    comp.AddConstant("GL_PIXEL_MAP_I_TO_R", GL_PIXEL_MAP_I_TO_R);
    comp.AddConstant("GL_PIXEL_MAP_I_TO_G", GL_PIXEL_MAP_I_TO_G);
    comp.AddConstant("GL_PIXEL_MAP_I_TO_B", GL_PIXEL_MAP_I_TO_B);
    comp.AddConstant("GL_PIXEL_MAP_I_TO_A", GL_PIXEL_MAP_I_TO_A);
    comp.AddConstant("GL_PIXEL_MAP_R_TO_R", GL_PIXEL_MAP_R_TO_R);
    comp.AddConstant("GL_PIXEL_MAP_G_TO_G", GL_PIXEL_MAP_G_TO_G);
    comp.AddConstant("GL_PIXEL_MAP_B_TO_B", GL_PIXEL_MAP_B_TO_B);
    comp.AddConstant("GL_PIXEL_MAP_A_TO_A", GL_PIXEL_MAP_A_TO_A);
    comp.AddConstant("GL_PIXEL_MAP_I_TO_I_SIZE", GL_PIXEL_MAP_I_TO_I_SIZE);
    comp.AddConstant("GL_PIXEL_MAP_S_TO_S_SIZE", GL_PIXEL_MAP_S_TO_S_SIZE);
    comp.AddConstant("GL_PIXEL_MAP_I_TO_R_SIZE", GL_PIXEL_MAP_I_TO_R_SIZE);
    comp.AddConstant("GL_PIXEL_MAP_I_TO_G_SIZE", GL_PIXEL_MAP_I_TO_G_SIZE);
    comp.AddConstant("GL_PIXEL_MAP_I_TO_B_SIZE", GL_PIXEL_MAP_I_TO_B_SIZE);
    comp.AddConstant("GL_PIXEL_MAP_I_TO_A_SIZE", GL_PIXEL_MAP_I_TO_A_SIZE);
    comp.AddConstant("GL_PIXEL_MAP_R_TO_R_SIZE", GL_PIXEL_MAP_R_TO_R_SIZE);
    comp.AddConstant("GL_PIXEL_MAP_G_TO_G_SIZE", GL_PIXEL_MAP_G_TO_G_SIZE);
    comp.AddConstant("GL_PIXEL_MAP_B_TO_B_SIZE", GL_PIXEL_MAP_B_TO_B_SIZE);
    comp.AddConstant("GL_PIXEL_MAP_A_TO_A_SIZE", GL_PIXEL_MAP_A_TO_A_SIZE);
    comp.AddConstant("GL_UNPACK_SWAP_BYTES", GL_UNPACK_SWAP_BYTES);
    comp.AddConstant("GL_UNPACK_LSB_FIRST", GL_UNPACK_LSB_FIRST);
    comp.AddConstant("GL_UNPACK_ROW_LENGTH", GL_UNPACK_ROW_LENGTH);
    comp.AddConstant("GL_UNPACK_SKIP_ROWS", GL_UNPACK_SKIP_ROWS);
    comp.AddConstant("GL_UNPACK_SKIP_PIXELS", GL_UNPACK_SKIP_PIXELS);
    comp.AddConstant("GL_UNPACK_ALIGNMENT", GL_UNPACK_ALIGNMENT);
    comp.AddConstant("GL_PACK_SWAP_BYTES", GL_PACK_SWAP_BYTES);
    comp.AddConstant("GL_PACK_LSB_FIRST", GL_PACK_LSB_FIRST);
    comp.AddConstant("GL_PACK_ROW_LENGTH", GL_PACK_ROW_LENGTH);
    comp.AddConstant("GL_PACK_SKIP_ROWS", GL_PACK_SKIP_ROWS);
    comp.AddConstant("GL_PACK_SKIP_PIXELS", GL_PACK_SKIP_PIXELS);
    comp.AddConstant("GL_PACK_ALIGNMENT", GL_PACK_ALIGNMENT);
    comp.AddConstant("GL_MAP_COLOR", GL_MAP_COLOR);
    comp.AddConstant("GL_MAP_STENCIL", GL_MAP_STENCIL);
    comp.AddConstant("GL_INDEX_SHIFT", GL_INDEX_SHIFT);
    comp.AddConstant("GL_INDEX_OFFSET", GL_INDEX_OFFSET);
    comp.AddConstant("GL_RED_SCALE", GL_RED_SCALE);
    comp.AddConstant("GL_RED_BIAS", GL_RED_BIAS);
    comp.AddConstant("GL_ZOOM_X", GL_ZOOM_X);
    comp.AddConstant("GL_ZOOM_Y", GL_ZOOM_Y);
    comp.AddConstant("GL_GREEN_SCALE", GL_GREEN_SCALE);
    comp.AddConstant("GL_GREEN_BIAS", GL_GREEN_BIAS);
    comp.AddConstant("GL_BLUE_SCALE", GL_BLUE_SCALE);
    comp.AddConstant("GL_BLUE_BIAS", GL_BLUE_BIAS);
    comp.AddConstant("GL_ALPHA_SCALE", GL_ALPHA_SCALE);
    comp.AddConstant("GL_ALPHA_BIAS", GL_ALPHA_BIAS);
    comp.AddConstant("GL_DEPTH_SCALE", GL_DEPTH_SCALE);
    comp.AddConstant("GL_DEPTH_BIAS", GL_DEPTH_BIAS);
    comp.AddConstant("GL_MAX_EVAL_ORDER", GL_MAX_EVAL_ORDER);
    comp.AddConstant("GL_MAX_LIGHTS", GL_MAX_LIGHTS);
    comp.AddConstant("GL_MAX_CLIP_PLANES", GL_MAX_CLIP_PLANES);
    comp.AddConstant("GL_MAX_TEXTURE_SIZE", GL_MAX_TEXTURE_SIZE);
    comp.AddConstant("GL_MAX_PIXEL_MAP_TABLE", GL_MAX_PIXEL_MAP_TABLE);
    comp.AddConstant("GL_MAX_ATTRIB_STACK_DEPTH", GL_MAX_ATTRIB_STACK_DEPTH);
    comp.AddConstant("GL_MAX_MODELVIEW_STACK_DEPTH", GL_MAX_MODELVIEW_STACK_DEPTH);
    comp.AddConstant("GL_MAX_NAME_STACK_DEPTH", GL_MAX_NAME_STACK_DEPTH);
    comp.AddConstant("GL_MAX_PROJECTION_STACK_DEPTH", GL_MAX_PROJECTION_STACK_DEPTH);
    comp.AddConstant("GL_MAX_TEXTURE_STACK_DEPTH", GL_MAX_TEXTURE_STACK_DEPTH);
    comp.AddConstant("GL_MAX_VIEWPORT_DIMS", GL_MAX_VIEWPORT_DIMS);
    comp.AddConstant("GL_MAX_CLIENT_ATTRIB_STACK_DEPTH", GL_MAX_CLIENT_ATTRIB_STACK_DEPTH);
    comp.AddConstant("GL_SUBPIXEL_BITS", GL_SUBPIXEL_BITS);
    comp.AddConstant("GL_INDEX_BITS", GL_INDEX_BITS);
    comp.AddConstant("GL_RED_BITS", GL_RED_BITS);
    comp.AddConstant("GL_GREEN_BITS", GL_GREEN_BITS);
    comp.AddConstant("GL_BLUE_BITS", GL_BLUE_BITS);
    comp.AddConstant("GL_ALPHA_BITS", GL_ALPHA_BITS);
    comp.AddConstant("GL_DEPTH_BITS", GL_DEPTH_BITS);
    comp.AddConstant("GL_STENCIL_BITS", GL_STENCIL_BITS);
    comp.AddConstant("GL_ACCUM_RED_BITS", GL_ACCUM_RED_BITS);
    comp.AddConstant("GL_ACCUM_GREEN_BITS", GL_ACCUM_GREEN_BITS);
    comp.AddConstant("GL_ACCUM_BLUE_BITS", GL_ACCUM_BLUE_BITS);
    comp.AddConstant("GL_ACCUM_ALPHA_BITS", GL_ACCUM_ALPHA_BITS);
    comp.AddConstant("GL_NAME_STACK_DEPTH", GL_NAME_STACK_DEPTH);
    comp.AddConstant("GL_AUTO_NORMAL", GL_AUTO_NORMAL);
    comp.AddConstant("GL_MAP1_COLOR_4", GL_MAP1_COLOR_4);
    comp.AddConstant("GL_MAP1_INDEX", GL_MAP1_INDEX);
    comp.AddConstant("GL_MAP1_NORMAL", GL_MAP1_NORMAL);
    comp.AddConstant("GL_MAP1_TEXTURE_COORD_1", GL_MAP1_TEXTURE_COORD_1);
    comp.AddConstant("GL_MAP1_TEXTURE_COORD_2", GL_MAP1_TEXTURE_COORD_2);
    comp.AddConstant("GL_MAP1_TEXTURE_COORD_3", GL_MAP1_TEXTURE_COORD_3);
    comp.AddConstant("GL_MAP1_TEXTURE_COORD_4", GL_MAP1_TEXTURE_COORD_4);
    comp.AddConstant("GL_MAP1_VERTEX_3", GL_MAP1_VERTEX_3);
    comp.AddConstant("GL_MAP1_VERTEX_4", GL_MAP1_VERTEX_4);
    comp.AddConstant("GL_MAP2_COLOR_4", GL_MAP2_COLOR_4);
    comp.AddConstant("GL_MAP2_INDEX", GL_MAP2_INDEX);
    comp.AddConstant("GL_MAP2_NORMAL", GL_MAP2_NORMAL);
    comp.AddConstant("GL_MAP2_TEXTURE_COORD_1", GL_MAP2_TEXTURE_COORD_1);
    comp.AddConstant("GL_MAP2_TEXTURE_COORD_2", GL_MAP2_TEXTURE_COORD_2);
    comp.AddConstant("GL_MAP2_TEXTURE_COORD_3", GL_MAP2_TEXTURE_COORD_3);
    comp.AddConstant("GL_MAP2_TEXTURE_COORD_4", GL_MAP2_TEXTURE_COORD_4);
    comp.AddConstant("GL_MAP2_VERTEX_3", GL_MAP2_VERTEX_3);
    comp.AddConstant("GL_MAP2_VERTEX_4", GL_MAP2_VERTEX_4);
    comp.AddConstant("GL_MAP1_GRID_DOMAIN", GL_MAP1_GRID_DOMAIN);
    comp.AddConstant("GL_MAP1_GRID_SEGMENTS", GL_MAP1_GRID_SEGMENTS);
    comp.AddConstant("GL_MAP2_GRID_DOMAIN", GL_MAP2_GRID_DOMAIN);
    comp.AddConstant("GL_MAP2_GRID_SEGMENTS", GL_MAP2_GRID_SEGMENTS);
    comp.AddConstant("GL_TEXTURE_1D", GL_TEXTURE_1D);
    comp.AddConstant("GL_TEXTURE_2D", GL_TEXTURE_2D);
    comp.AddConstant("GL_FEEDBACK_BUFFER_POINTER", GL_FEEDBACK_BUFFER_POINTER);
    comp.AddConstant("GL_FEEDBACK_BUFFER_SIZE", GL_FEEDBACK_BUFFER_SIZE);
    comp.AddConstant("GL_FEEDBACK_BUFFER_TYPE", GL_FEEDBACK_BUFFER_TYPE);
    comp.AddConstant("GL_SELECTION_BUFFER_POINTER", GL_SELECTION_BUFFER_POINTER);
    comp.AddConstant("GL_SELECTION_BUFFER_SIZE", GL_SELECTION_BUFFER_SIZE);
    comp.AddConstant("GL_TEXTURE_WIDTH", GL_TEXTURE_WIDTH);
    comp.AddConstant("GL_TEXTURE_HEIGHT", GL_TEXTURE_HEIGHT);
    comp.AddConstant("GL_TEXTURE_INTERNAL_FORMAT", GL_TEXTURE_INTERNAL_FORMAT);
    comp.AddConstant("GL_TEXTURE_BORDER_COLOR", GL_TEXTURE_BORDER_COLOR);
    comp.AddConstant("GL_TEXTURE_BORDER", GL_TEXTURE_BORDER);
    comp.AddConstant("GL_DONT_CARE", GL_DONT_CARE);
    comp.AddConstant("GL_FASTEST", GL_FASTEST);
    comp.AddConstant("GL_NICEST", GL_NICEST);
    comp.AddConstant("GL_LIGHT0", GL_LIGHT0);
    comp.AddConstant("GL_LIGHT1", GL_LIGHT1);
    comp.AddConstant("GL_LIGHT2", GL_LIGHT2);
    comp.AddConstant("GL_LIGHT3", GL_LIGHT3);
    comp.AddConstant("GL_LIGHT4", GL_LIGHT4);
    comp.AddConstant("GL_LIGHT5", GL_LIGHT5);
    comp.AddConstant("GL_LIGHT6", GL_LIGHT6);
    comp.AddConstant("GL_LIGHT7", GL_LIGHT7);
    comp.AddConstant("GL_AMBIENT", GL_AMBIENT);
    comp.AddConstant("GL_DIFFUSE", GL_DIFFUSE);
    comp.AddConstant("GL_SPECULAR", GL_SPECULAR);
    comp.AddConstant("GL_POSITION", GL_POSITION);
    comp.AddConstant("GL_SPOT_DIRECTION", GL_SPOT_DIRECTION);
    comp.AddConstant("GL_SPOT_EXPONENT", GL_SPOT_EXPONENT);
    comp.AddConstant("GL_SPOT_CUTOFF", GL_SPOT_CUTOFF);
    comp.AddConstant("GL_CONSTANT_ATTENUATION", GL_CONSTANT_ATTENUATION);
    comp.AddConstant("GL_LINEAR_ATTENUATION", GL_LINEAR_ATTENUATION);
    comp.AddConstant("GL_QUADRATIC_ATTENUATION", GL_QUADRATIC_ATTENUATION);
    comp.AddConstant("GL_COMPILE", GL_COMPILE);
    comp.AddConstant("GL_COMPILE_AND_EXECUTE", GL_COMPILE_AND_EXECUTE);
    comp.AddConstant("GL_CLEAR", GL_CLEAR);
    comp.AddConstant("GL_AND", GL_AND);
    comp.AddConstant("GL_AND_REVERSE", GL_AND_REVERSE);
    comp.AddConstant("GL_COPY", GL_COPY);
    comp.AddConstant("GL_AND_INVERTED", GL_AND_INVERTED);
    comp.AddConstant("GL_NOOP", GL_NOOP);
    comp.AddConstant("GL_XOR", GL_XOR);
    comp.AddConstant("GL_OR", GL_OR);
    comp.AddConstant("GL_NOR", GL_NOR);
    comp.AddConstant("GL_EQUIV", GL_EQUIV);
    comp.AddConstant("GL_INVERT", GL_INVERT);
    comp.AddConstant("GL_OR_REVERSE", GL_OR_REVERSE);
    comp.AddConstant("GL_COPY_INVERTED", GL_COPY_INVERTED);
    comp.AddConstant("GL_OR_INVERTED", GL_OR_INVERTED);
    comp.AddConstant("GL_NAND", GL_NAND);
    comp.AddConstant("GL_SET", GL_SET);
    comp.AddConstant("GL_EMISSION", GL_EMISSION);
    comp.AddConstant("GL_SHININESS", GL_SHININESS);
    comp.AddConstant("GL_AMBIENT_AND_DIFFUSE", GL_AMBIENT_AND_DIFFUSE);
    comp.AddConstant("GL_COLOR_INDEXES", GL_COLOR_INDEXES);
    comp.AddConstant("GL_MODELVIEW", GL_MODELVIEW);
    comp.AddConstant("GL_PROJECTION", GL_PROJECTION);
    comp.AddConstant("GL_TEXTURE", GL_TEXTURE);
    comp.AddConstant("GL_COLOR", GL_COLOR);
    comp.AddConstant("GL_DEPTH", GL_DEPTH);
    comp.AddConstant("GL_STENCIL", GL_STENCIL);
    comp.AddConstant("GL_COLOR_INDEX", GL_COLOR_INDEX);
    comp.AddConstant("GL_STENCIL_INDEX", GL_STENCIL_INDEX);
    comp.AddConstant("GL_DEPTH_COMPONENT", GL_DEPTH_COMPONENT);
    comp.AddConstant("GL_RED", GL_RED);
    comp.AddConstant("GL_GREEN", GL_GREEN);
    comp.AddConstant("GL_BLUE", GL_BLUE);
    comp.AddConstant("GL_ALPHA", GL_ALPHA);
    comp.AddConstant("GL_RGB", GL_RGB);
    comp.AddConstant("GL_RGBA", GL_RGBA);
    comp.AddConstant("GL_LUMINANCE", GL_LUMINANCE);
    comp.AddConstant("GL_LUMINANCE_ALPHA", GL_LUMINANCE_ALPHA);
    comp.AddConstant("GL_BITMAP", GL_BITMAP);
    comp.AddConstant("GL_POINT", GL_POINT);
    comp.AddConstant("GL_LINE", GL_LINE);
    comp.AddConstant("GL_FILL", GL_FILL);
    comp.AddConstant("GL_RENDER", GL_RENDER);
    comp.AddConstant("GL_FEEDBACK", GL_FEEDBACK);
    comp.AddConstant("GL_SELECT", GL_SELECT);
    comp.AddConstant("GL_FLAT", GL_FLAT);
    comp.AddConstant("GL_SMOOTH", GL_SMOOTH);
    comp.AddConstant("GL_KEEP", GL_KEEP);
    comp.AddConstant("GL_REPLACE", GL_REPLACE);
    comp.AddConstant("GL_INCR", GL_INCR);
    comp.AddConstant("GL_DECR", GL_DECR);
    comp.AddConstant("GL_VENDOR", GL_VENDOR);
    comp.AddConstant("GL_RENDERER", GL_RENDERER);
    comp.AddConstant("GL_VERSION", GL_VERSION);
    comp.AddConstant("GL_EXTENSIONS", GL_EXTENSIONS);
    comp.AddConstant("GL_S", GL_S);
    comp.AddConstant("GL_T", GL_T);
    comp.AddConstant("GL_R", GL_R);
    comp.AddConstant("GL_Q", GL_Q);
    comp.AddConstant("GL_MODULATE", GL_MODULATE);
    comp.AddConstant("GL_DECAL", GL_DECAL);
    comp.AddConstant("GL_TEXTURE_ENV_MODE", GL_TEXTURE_ENV_MODE);
    comp.AddConstant("GL_TEXTURE_ENV_COLOR", GL_TEXTURE_ENV_COLOR);
    comp.AddConstant("GL_TEXTURE_ENV", GL_TEXTURE_ENV);
    comp.AddConstant("GL_EYE_LINEAR", GL_EYE_LINEAR);
    comp.AddConstant("GL_OBJECT_LINEAR", GL_OBJECT_LINEAR);
    comp.AddConstant("GL_SPHERE_MAP", GL_SPHERE_MAP);
    comp.AddConstant("GL_TEXTURE_GEN_MODE", GL_TEXTURE_GEN_MODE);
    comp.AddConstant("GL_OBJECT_PLANE", GL_OBJECT_PLANE);
    comp.AddConstant("GL_EYE_PLANE", GL_EYE_PLANE);
    comp.AddConstant("GL_NEAREST", GL_NEAREST);
    comp.AddConstant("GL_LINEAR", GL_LINEAR);
    comp.AddConstant("GL_NEAREST_MIPMAP_NEAREST", GL_NEAREST_MIPMAP_NEAREST);
    comp.AddConstant("GL_LINEAR_MIPMAP_NEAREST", GL_LINEAR_MIPMAP_NEAREST);
    comp.AddConstant("GL_NEAREST_MIPMAP_LINEAR", GL_NEAREST_MIPMAP_LINEAR);
    comp.AddConstant("GL_LINEAR_MIPMAP_LINEAR", GL_LINEAR_MIPMAP_LINEAR);
    comp.AddConstant("GL_TEXTURE_MAG_FILTER", GL_TEXTURE_MAG_FILTER);
    comp.AddConstant("GL_TEXTURE_MIN_FILTER", GL_TEXTURE_MIN_FILTER);
    comp.AddConstant("GL_TEXTURE_WRAP_S", GL_TEXTURE_WRAP_S);
    comp.AddConstant("GL_TEXTURE_WRAP_T", GL_TEXTURE_WRAP_T);
    comp.AddConstant("GL_CLAMP", GL_CLAMP);
    comp.AddConstant("GL_REPEAT", GL_REPEAT);
    comp.AddConstant("GL_CLIENT_PIXEL_STORE_BIT", GL_CLIENT_PIXEL_STORE_BIT);
    comp.AddConstant("GL_CLIENT_VERTEX_ARRAY_BIT", GL_CLIENT_VERTEX_ARRAY_BIT);
    comp.AddConstant("GL_CLIENT_ALL_ATTRIB_BITS", (unsigned int) GL_CLIENT_ALL_ATTRIB_BITS);
    comp.AddConstant("GL_POLYGON_OFFSET_FACTOR", GL_POLYGON_OFFSET_FACTOR);
    comp.AddConstant("GL_POLYGON_OFFSET_UNITS", GL_POLYGON_OFFSET_UNITS);
    comp.AddConstant("GL_POLYGON_OFFSET_POINT", GL_POLYGON_OFFSET_POINT);
    comp.AddConstant("GL_POLYGON_OFFSET_LINE", GL_POLYGON_OFFSET_LINE);
    comp.AddConstant("GL_POLYGON_OFFSET_FILL", GL_POLYGON_OFFSET_FILL);
    comp.AddConstant("GL_ALPHA4", GL_ALPHA4);
    comp.AddConstant("GL_ALPHA8", GL_ALPHA8);
    comp.AddConstant("GL_ALPHA12", GL_ALPHA12);
    comp.AddConstant("GL_ALPHA16", GL_ALPHA16);
    comp.AddConstant("GL_LUMINANCE4", GL_LUMINANCE4);
    comp.AddConstant("GL_LUMINANCE8", GL_LUMINANCE8);
    comp.AddConstant("GL_LUMINANCE12", GL_LUMINANCE12);
    comp.AddConstant("GL_LUMINANCE16", GL_LUMINANCE16);
    comp.AddConstant("GL_LUMINANCE4_ALPHA4", GL_LUMINANCE4_ALPHA4);
    comp.AddConstant("GL_LUMINANCE6_ALPHA2", GL_LUMINANCE6_ALPHA2);
    comp.AddConstant("GL_LUMINANCE8_ALPHA8", GL_LUMINANCE8_ALPHA8);
    comp.AddConstant("GL_LUMINANCE12_ALPHA4", GL_LUMINANCE12_ALPHA4);
    comp.AddConstant("GL_LUMINANCE12_ALPHA12", GL_LUMINANCE12_ALPHA12);
    comp.AddConstant("GL_LUMINANCE16_ALPHA16", GL_LUMINANCE16_ALPHA16);
    comp.AddConstant("GL_INTENSITY", GL_INTENSITY);
    comp.AddConstant("GL_INTENSITY4", GL_INTENSITY4);
    comp.AddConstant("GL_INTENSITY8", GL_INTENSITY8);
    comp.AddConstant("GL_INTENSITY12", GL_INTENSITY12);
    comp.AddConstant("GL_INTENSITY16", GL_INTENSITY16);
    comp.AddConstant("GL_R3_G3_B2", GL_R3_G3_B2);
    comp.AddConstant("GL_RGB4", GL_RGB4);
    comp.AddConstant("GL_RGB5", GL_RGB5);
    comp.AddConstant("GL_RGB8", GL_RGB8);
    comp.AddConstant("GL_RGB10", GL_RGB10);
    comp.AddConstant("GL_RGB12", GL_RGB12);
    comp.AddConstant("GL_RGB16", GL_RGB16);
    comp.AddConstant("GL_RGBA2", GL_RGBA2);
    comp.AddConstant("GL_RGBA4", GL_RGBA4);
    comp.AddConstant("GL_RGB5_A1", GL_RGB5_A1);
    comp.AddConstant("GL_RGBA8", GL_RGBA8);
    comp.AddConstant("GL_RGB10_A2", GL_RGB10_A2);
    comp.AddConstant("GL_RGBA12", GL_RGBA12);
    comp.AddConstant("GL_RGBA16", GL_RGBA16);
    comp.AddConstant("GL_TEXTURE_RED_SIZE", GL_TEXTURE_RED_SIZE);
    comp.AddConstant("GL_TEXTURE_GREEN_SIZE", GL_TEXTURE_GREEN_SIZE);
    comp.AddConstant("GL_TEXTURE_BLUE_SIZE", GL_TEXTURE_BLUE_SIZE);
    comp.AddConstant("GL_TEXTURE_ALPHA_SIZE", GL_TEXTURE_ALPHA_SIZE);
    comp.AddConstant("GL_TEXTURE_LUMINANCE_SIZE", GL_TEXTURE_LUMINANCE_SIZE);
    comp.AddConstant("GL_TEXTURE_INTENSITY_SIZE", GL_TEXTURE_INTENSITY_SIZE);
    comp.AddConstant("GL_PROXY_TEXTURE_1D", GL_PROXY_TEXTURE_1D);
    comp.AddConstant("GL_PROXY_TEXTURE_2D", GL_PROXY_TEXTURE_2D);
    comp.AddConstant("GL_TEXTURE_PRIORITY", GL_TEXTURE_PRIORITY);
    comp.AddConstant("GL_TEXTURE_RESIDENT", GL_TEXTURE_RESIDENT);
    comp.AddConstant("GL_TEXTURE_BINDING_1D", GL_TEXTURE_BINDING_1D);
    comp.AddConstant("GL_TEXTURE_BINDING_2D", GL_TEXTURE_BINDING_2D);
    comp.AddConstant("GL_VERTEX_ARRAY", GL_VERTEX_ARRAY);
    comp.AddConstant("GL_NORMAL_ARRAY", GL_NORMAL_ARRAY);
    comp.AddConstant("GL_COLOR_ARRAY", GL_COLOR_ARRAY);
    comp.AddConstant("GL_INDEX_ARRAY", GL_INDEX_ARRAY);
    comp.AddConstant("GL_TEXTURE_COORD_ARRAY", GL_TEXTURE_COORD_ARRAY);
    comp.AddConstant("GL_EDGE_FLAG_ARRAY", GL_EDGE_FLAG_ARRAY);
    comp.AddConstant("GL_VERTEX_ARRAY_SIZE", GL_VERTEX_ARRAY_SIZE);
    comp.AddConstant("GL_VERTEX_ARRAY_TYPE", GL_VERTEX_ARRAY_TYPE);
    comp.AddConstant("GL_VERTEX_ARRAY_STRIDE", GL_VERTEX_ARRAY_STRIDE);
    comp.AddConstant("GL_NORMAL_ARRAY_TYPE", GL_NORMAL_ARRAY_TYPE);
    comp.AddConstant("GL_NORMAL_ARRAY_STRIDE", GL_NORMAL_ARRAY_STRIDE);
    comp.AddConstant("GL_COLOR_ARRAY_SIZE", GL_COLOR_ARRAY_SIZE);
    comp.AddConstant("GL_COLOR_ARRAY_TYPE", GL_COLOR_ARRAY_TYPE);
    comp.AddConstant("GL_COLOR_ARRAY_STRIDE", GL_COLOR_ARRAY_STRIDE);
    comp.AddConstant("GL_INDEX_ARRAY_TYPE", GL_INDEX_ARRAY_TYPE);
    comp.AddConstant("GL_INDEX_ARRAY_STRIDE", GL_INDEX_ARRAY_STRIDE);
    comp.AddConstant("GL_TEXTURE_COORD_ARRAY_SIZE", GL_TEXTURE_COORD_ARRAY_SIZE);
    comp.AddConstant("GL_TEXTURE_COORD_ARRAY_TYPE", GL_TEXTURE_COORD_ARRAY_TYPE);
    comp.AddConstant("GL_TEXTURE_COORD_ARRAY_STRIDE", GL_TEXTURE_COORD_ARRAY_STRIDE);
    comp.AddConstant("GL_EDGE_FLAG_ARRAY_STRIDE", GL_EDGE_FLAG_ARRAY_STRIDE);
    comp.AddConstant("GL_VERTEX_ARRAY_POINTER", GL_VERTEX_ARRAY_POINTER);
    comp.AddConstant("GL_NORMAL_ARRAY_POINTER", GL_NORMAL_ARRAY_POINTER);
    comp.AddConstant("GL_COLOR_ARRAY_POINTER", GL_COLOR_ARRAY_POINTER);
    comp.AddConstant("GL_INDEX_ARRAY_POINTER", GL_INDEX_ARRAY_POINTER);
    comp.AddConstant("GL_TEXTURE_COORD_ARRAY_POINTER", GL_TEXTURE_COORD_ARRAY_POINTER);
    comp.AddConstant("GL_EDGE_FLAG_ARRAY_POINTER", GL_EDGE_FLAG_ARRAY_POINTER);
    comp.AddConstant("GL_V2F", GL_V2F);
    comp.AddConstant("GL_V3F", GL_V3F);
    comp.AddConstant("GL_C4UB_V2F", GL_C4UB_V2F);
    comp.AddConstant("GL_C4UB_V3F", GL_C4UB_V3F);
    comp.AddConstant("GL_C3F_V3F", GL_C3F_V3F);
    comp.AddConstant("GL_N3F_V3F", GL_N3F_V3F);
    comp.AddConstant("GL_C4F_N3F_V3F", GL_C4F_N3F_V3F);
    comp.AddConstant("GL_T2F_V3F", GL_T2F_V3F);
    comp.AddConstant("GL_T4F_V4F", GL_T4F_V4F);
    comp.AddConstant("GL_T2F_C4UB_V3F", GL_T2F_C4UB_V3F);
    comp.AddConstant("GL_T2F_C3F_V3F", GL_T2F_C3F_V3F);
    comp.AddConstant("GL_T2F_N3F_V3F", GL_T2F_N3F_V3F);
    comp.AddConstant("GL_T2F_C4F_N3F_V3F", GL_T2F_C4F_N3F_V3F);
    comp.AddConstant("GL_T4F_C4F_N3F_V4F", GL_T4F_C4F_N3F_V4F);
    comp.AddConstant("GL_EXT_vertex_array", GL_EXT_vertex_array);
    comp.AddConstant("GL_EXT_bgra", GL_EXT_bgra);
    comp.AddConstant("GL_EXT_paletted_texture", GL_EXT_paletted_texture);
//    comp.AddConstant("GL_WIN_swap_hint", GL_WIN_swap_hint);
//    comp.AddConstant("GL_WIN_draw_range_elements", GL_WIN_draw_range_elements);
    comp.AddConstant("GL_VERTEX_ARRAY_EXT", GL_VERTEX_ARRAY_EXT);
    comp.AddConstant("GL_NORMAL_ARRAY_EXT", GL_NORMAL_ARRAY_EXT);
    comp.AddConstant("GL_COLOR_ARRAY_EXT", GL_COLOR_ARRAY_EXT);
    comp.AddConstant("GL_INDEX_ARRAY_EXT", GL_INDEX_ARRAY_EXT);
    comp.AddConstant("GL_TEXTURE_COORD_ARRAY_EXT", GL_TEXTURE_COORD_ARRAY_EXT);
    comp.AddConstant("GL_EDGE_FLAG_ARRAY_EXT", GL_EDGE_FLAG_ARRAY_EXT);
    comp.AddConstant("GL_VERTEX_ARRAY_SIZE_EXT", GL_VERTEX_ARRAY_SIZE_EXT);
    comp.AddConstant("GL_VERTEX_ARRAY_TYPE_EXT", GL_VERTEX_ARRAY_TYPE_EXT);
    comp.AddConstant("GL_VERTEX_ARRAY_STRIDE_EXT", GL_VERTEX_ARRAY_STRIDE_EXT);
    comp.AddConstant("GL_VERTEX_ARRAY_COUNT_EXT", GL_VERTEX_ARRAY_COUNT_EXT);
    comp.AddConstant("GL_NORMAL_ARRAY_TYPE_EXT", GL_NORMAL_ARRAY_TYPE_EXT);
    comp.AddConstant("GL_NORMAL_ARRAY_STRIDE_EXT", GL_NORMAL_ARRAY_STRIDE_EXT);
    comp.AddConstant("GL_NORMAL_ARRAY_COUNT_EXT", GL_NORMAL_ARRAY_COUNT_EXT);
    comp.AddConstant("GL_COLOR_ARRAY_SIZE_EXT", GL_COLOR_ARRAY_SIZE_EXT);
    comp.AddConstant("GL_COLOR_ARRAY_TYPE_EXT", GL_COLOR_ARRAY_TYPE_EXT);
    comp.AddConstant("GL_COLOR_ARRAY_STRIDE_EXT", GL_COLOR_ARRAY_STRIDE_EXT);
    comp.AddConstant("GL_COLOR_ARRAY_COUNT_EXT", GL_COLOR_ARRAY_COUNT_EXT);
    comp.AddConstant("GL_INDEX_ARRAY_TYPE_EXT", GL_INDEX_ARRAY_TYPE_EXT);
    comp.AddConstant("GL_INDEX_ARRAY_STRIDE_EXT", GL_INDEX_ARRAY_STRIDE_EXT);
    comp.AddConstant("GL_INDEX_ARRAY_COUNT_EXT", GL_INDEX_ARRAY_COUNT_EXT);
    comp.AddConstant("GL_TEXTURE_COORD_ARRAY_SIZE_EXT", GL_TEXTURE_COORD_ARRAY_SIZE_EXT);
    comp.AddConstant("GL_TEXTURE_COORD_ARRAY_TYPE_EXT", GL_TEXTURE_COORD_ARRAY_TYPE_EXT);
    comp.AddConstant("GL_TEXTURE_COORD_ARRAY_STRIDE_EXT", GL_TEXTURE_COORD_ARRAY_STRIDE_EXT);
    comp.AddConstant("GL_TEXTURE_COORD_ARRAY_COUNT_EXT", GL_TEXTURE_COORD_ARRAY_COUNT_EXT);
    comp.AddConstant("GL_EDGE_FLAG_ARRAY_STRIDE_EXT", GL_EDGE_FLAG_ARRAY_STRIDE_EXT);
    comp.AddConstant("GL_EDGE_FLAG_ARRAY_COUNT_EXT", GL_EDGE_FLAG_ARRAY_COUNT_EXT);
    comp.AddConstant("GL_VERTEX_ARRAY_POINTER_EXT", GL_VERTEX_ARRAY_POINTER_EXT);
    comp.AddConstant("GL_NORMAL_ARRAY_POINTER_EXT", GL_NORMAL_ARRAY_POINTER_EXT);
    comp.AddConstant("GL_COLOR_ARRAY_POINTER_EXT", GL_COLOR_ARRAY_POINTER_EXT);
    comp.AddConstant("GL_INDEX_ARRAY_POINTER_EXT", GL_INDEX_ARRAY_POINTER_EXT);
    comp.AddConstant("GL_TEXTURE_COORD_ARRAY_POINTER_EXT", GL_TEXTURE_COORD_ARRAY_POINTER_EXT);
    comp.AddConstant("GL_EDGE_FLAG_ARRAY_POINTER_EXT", GL_EDGE_FLAG_ARRAY_POINTER_EXT);
//    comp.AddConstant("GL_DOUBLE_EXT", GL_DOUBLE_EXT);
    comp.AddConstant("GL_BGR_EXT", GL_BGR_EXT);
    comp.AddConstant("GL_BGRA_EXT", GL_BGRA_EXT);
//    comp.AddConstant("GL_COLOR_TABLE_FORMAT_EXT", GL_COLOR_TABLE_FORMAT_EXT);
//    comp.AddConstant("GL_COLOR_TABLE_WIDTH_EXT", GL_COLOR_TABLE_WIDTH_EXT);
//    comp.AddConstant("GL_COLOR_TABLE_RED_SIZE_EXT", GL_COLOR_TABLE_RED_SIZE_EXT);
//    comp.AddConstant("GL_COLOR_TABLE_GREEN_SIZE_EXT", GL_COLOR_TABLE_GREEN_SIZE_EXT);
//    comp.AddConstant("GL_COLOR_TABLE_BLUE_SIZE_EXT", GL_COLOR_TABLE_BLUE_SIZE_EXT);
//    comp.AddConstant("GL_COLOR_TABLE_ALPHA_SIZE_EXT", GL_COLOR_TABLE_ALPHA_SIZE_EXT);
//    comp.AddConstant("GL_COLOR_TABLE_LUMINANCE_SIZE_EXT", GL_COLOR_TABLE_LUMINANCE_SIZE_EXT);
//    comp.AddConstant("GL_COLOR_TABLE_INTENSITY_SIZE_EXT", GL_COLOR_TABLE_INTENSITY_SIZE_EXT);
    comp.AddConstant("GL_COLOR_INDEX1_EXT", GL_COLOR_INDEX1_EXT);
    comp.AddConstant("GL_COLOR_INDEX2_EXT", GL_COLOR_INDEX2_EXT);
    comp.AddConstant("GL_COLOR_INDEX4_EXT", GL_COLOR_INDEX4_EXT);
    comp.AddConstant("GL_COLOR_INDEX8_EXT", GL_COLOR_INDEX8_EXT);
    comp.AddConstant("GL_COLOR_INDEX12_EXT", GL_COLOR_INDEX12_EXT);
    comp.AddConstant("GL_COLOR_INDEX16_EXT", GL_COLOR_INDEX16_EXT);
//    comp.AddConstant("GL_MAX_ELEMENTS_VERTICES_WIN", GL_MAX_ELEMENTS_VERTICES_WIN);
//    comp.AddConstant("GL_MAX_ELEMENTS_INDICES_WIN", GL_MAX_ELEMENTS_INDICES_WIN);
    comp.AddConstant("GL_PHONG_WIN", GL_PHONG_WIN);
    comp.AddConstant("GL_PHONG_HINT_WIN", GL_PHONG_HINT_WIN);
    comp.AddConstant("GL_FOG_SPECULAR_TEXTURE_WIN", GL_FOG_SPECULAR_TEXTURE_WIN);
    comp.AddConstant("GL_LOGIC_OP", GL_LOGIC_OP);
    comp.AddConstant("GL_TEXTURE_COMPONENTS", GL_TEXTURE_COMPONENTS);

    // Register functions

    comp.AddFunction("glAccum", WrapglAccum,compParamTypeList () << VTP_INT << VTP_REAL, true, false, VTP_INT);
    comp.AddFunction("glAlphaFunc", WrapglAlphaFunc,compParamTypeList () << VTP_INT << VTP_REAL, true, false, VTP_INT);
//    comp.AddFunction("glAreTexturesResident", WrapglAreTexturesResident,compParamTypeList () << VTP_INT<<vmValType(VTP_INT,1,1,true)<<vmValType(VTP_INT,1,1,true), true, true, VTP_INT);
    comp.AddFunction("glArrayElement", WrapglArrayElement,compParamTypeList () << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glBegin", WrapglBegin,compParamTypeList () << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glBindTexture", WrapglBindTexture,compParamTypeList () << VTP_INT << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glBlendFunc", WrapglBlendFunc,compParamTypeList () << VTP_INT << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glCallList", WrapglCallList,compParamTypeList () << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glClear", WrapglClear,compParamTypeList () << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glClearAccum", WrapglClearAccum,compParamTypeList () << VTP_REAL << VTP_REAL << VTP_REAL << VTP_REAL, true, false, VTP_INT);
    comp.AddFunction("glClearColor", WrapglClearColor,compParamTypeList () << VTP_REAL << VTP_REAL << VTP_REAL << VTP_REAL, true, false, VTP_INT);
    comp.AddFunction("glClearDepth", WrapglClearDepth,compParamTypeList () << VTP_REAL, true, false, VTP_INT);
    comp.AddFunction("glClearIndex", WrapglClearIndex,compParamTypeList () << VTP_REAL, true, false, VTP_INT);
    comp.AddFunction("glClearStencil", WrapglClearStencil,compParamTypeList () << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glClipPlane", WrapglClipPlane,compParamTypeList () << VTP_INT<<vmValType(VTP_REAL,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glClipPlane", WrapglClipPlane_2,compParamTypeList () << VTP_INT<<vmValType(VTP_REAL,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glColor3b", WrapglColor3b,compParamTypeList () << VTP_INT << VTP_INT << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glColor3bv", WrapglColor3bv,compParamTypeList ()<<vmValType(VTP_INT,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glColor3bv", WrapglColor3bv_2,compParamTypeList ()<<vmValType(VTP_INT,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glColor3d", WrapglColor3d,compParamTypeList () << VTP_REAL << VTP_REAL << VTP_REAL, true, false, VTP_INT);
    comp.AddFunction("glColor3dv", WrapglColor3dv,compParamTypeList ()<<vmValType(VTP_REAL,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glColor3dv", WrapglColor3dv_2,compParamTypeList ()<<vmValType(VTP_REAL,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glColor3f", WrapglColor3f,compParamTypeList () << VTP_REAL << VTP_REAL << VTP_REAL, true, false, VTP_INT);
    comp.AddFunction("glColor3fv", WrapglColor3fv,compParamTypeList ()<<vmValType(VTP_REAL,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glColor3fv", WrapglColor3fv_2,compParamTypeList ()<<vmValType(VTP_REAL,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glColor3i", WrapglColor3i,compParamTypeList () << VTP_INT << VTP_INT << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glColor3iv", WrapglColor3iv,compParamTypeList ()<<vmValType(VTP_INT,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glColor3iv", WrapglColor3iv_2,compParamTypeList ()<<vmValType(VTP_INT,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glColor3s", WrapglColor3s,compParamTypeList () << VTP_INT << VTP_INT << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glColor3sv", WrapglColor3sv,compParamTypeList ()<<vmValType(VTP_INT,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glColor3sv", WrapglColor3sv_2,compParamTypeList ()<<vmValType(VTP_INT,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glColor3ub", WrapglColor3ub,compParamTypeList () << VTP_INT << VTP_INT << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glColor3ubv", WrapglColor3ubv,compParamTypeList ()<<vmValType(VTP_INT,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glColor3ubv", WrapglColor3ubv_2,compParamTypeList ()<<vmValType(VTP_INT,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glColor3ui", WrapglColor3ui,compParamTypeList () << VTP_INT << VTP_INT << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glColor3uiv", WrapglColor3uiv,compParamTypeList ()<<vmValType(VTP_INT,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glColor3uiv", WrapglColor3uiv_2,compParamTypeList ()<<vmValType(VTP_INT,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glColor3us", WrapglColor3us,compParamTypeList () << VTP_INT << VTP_INT << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glColor3usv", WrapglColor3usv,compParamTypeList ()<<vmValType(VTP_INT,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glColor3usv", WrapglColor3usv_2,compParamTypeList ()<<vmValType(VTP_INT,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glColor4b", WrapglColor4b,compParamTypeList () << VTP_INT << VTP_INT << VTP_INT << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glColor4bv", WrapglColor4bv,compParamTypeList ()<<vmValType(VTP_INT,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glColor4bv", WrapglColor4bv_2,compParamTypeList ()<<vmValType(VTP_INT,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glColor4d", WrapglColor4d,compParamTypeList () << VTP_REAL << VTP_REAL << VTP_REAL << VTP_REAL, true, false, VTP_INT);
    comp.AddFunction("glColor4dv", WrapglColor4dv,compParamTypeList ()<<vmValType(VTP_REAL,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glColor4dv", WrapglColor4dv_2,compParamTypeList ()<<vmValType(VTP_REAL,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glColor4f", WrapglColor4f,compParamTypeList () << VTP_REAL << VTP_REAL << VTP_REAL << VTP_REAL, true, false, VTP_INT);
    comp.AddFunction("glColor4fv", WrapglColor4fv,compParamTypeList ()<<vmValType(VTP_REAL,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glColor4fv", WrapglColor4fv_2,compParamTypeList ()<<vmValType(VTP_REAL,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glColor4i", WrapglColor4i,compParamTypeList () << VTP_INT << VTP_INT << VTP_INT << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glColor4iv", WrapglColor4iv,compParamTypeList ()<<vmValType(VTP_INT,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glColor4iv", WrapglColor4iv_2,compParamTypeList ()<<vmValType(VTP_INT,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glColor4s", WrapglColor4s,compParamTypeList () << VTP_INT << VTP_INT << VTP_INT << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glColor4sv", WrapglColor4sv,compParamTypeList ()<<vmValType(VTP_INT,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glColor4sv", WrapglColor4sv_2,compParamTypeList ()<<vmValType(VTP_INT,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glColor4ub", WrapglColor4ub,compParamTypeList () << VTP_INT << VTP_INT << VTP_INT << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glColor4ubv", WrapglColor4ubv,compParamTypeList ()<<vmValType(VTP_INT,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glColor4ubv", WrapglColor4ubv_2,compParamTypeList ()<<vmValType(VTP_INT,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glColor4ui", WrapglColor4ui,compParamTypeList () << VTP_INT << VTP_INT << VTP_INT << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glColor4uiv", WrapglColor4uiv,compParamTypeList ()<<vmValType(VTP_INT,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glColor4uiv", WrapglColor4uiv_2,compParamTypeList ()<<vmValType(VTP_INT,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glColor4us", WrapglColor4us,compParamTypeList () << VTP_INT << VTP_INT << VTP_INT << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glColor4usv", WrapglColor4usv,compParamTypeList ()<<vmValType(VTP_INT,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glColor4usv", WrapglColor4usv_2,compParamTypeList ()<<vmValType(VTP_INT,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glColorMask", WrapglColorMask,compParamTypeList () << VTP_INT << VTP_INT << VTP_INT << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glColorMaterial", WrapglColorMaterial,compParamTypeList () << VTP_INT << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glCopyPixels", WrapglCopyPixels,compParamTypeList () << VTP_INT << VTP_INT << VTP_INT << VTP_INT << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glCopyTexImage1D", WrapglCopyTexImage1D,compParamTypeList () << VTP_INT << VTP_INT << VTP_INT << VTP_INT << VTP_INT << VTP_INT << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glCopyTexImage2D", WrapglCopyTexImage2D,compParamTypeList () << VTP_INT << VTP_INT << VTP_INT << VTP_INT << VTP_INT << VTP_INT << VTP_INT << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glCopyTexSubImage1D", WrapglCopyTexSubImage1D,compParamTypeList () << VTP_INT << VTP_INT << VTP_INT << VTP_INT << VTP_INT << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glCopyTexSubImage2D", WrapglCopyTexSubImage2D,compParamTypeList () << VTP_INT << VTP_INT << VTP_INT << VTP_INT << VTP_INT << VTP_INT << VTP_INT << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glCullFace", WrapglCullFace,compParamTypeList () << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glDepthFunc", WrapglDepthFunc,compParamTypeList () << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glDepthMask", WrapglDepthMask,compParamTypeList () << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glDepthRange", WrapglDepthRange,compParamTypeList () << VTP_REAL << VTP_REAL, true, false, VTP_INT);
    comp.AddFunction("glDisable", WrapglDisable,compParamTypeList () << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glDisableClientState", WrapglDisableClientState,compParamTypeList () << VTP_INT, true, false, VTP_INT);
//    comp.AddFunction("glDrawArrays", WrapglDrawArrays,compParamTypeList () << VTP_INT << VTP_INT << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glDrawBuffer", WrapglDrawBuffer,compParamTypeList () << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glEdgeFlag", WrapglEdgeFlag,compParamTypeList () << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glEdgeFlagv", WrapglEdgeFlagv,compParamTypeList ()<<vmValType(VTP_INT,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glEdgeFlagv", WrapglEdgeFlagv_2,compParamTypeList ()<<vmValType(VTP_INT,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glEnable", WrapglEnable,compParamTypeList () << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glEnableClientState", WrapglEnableClientState,compParamTypeList () << VTP_INT, true, false, VTP_INT);
    comp.AddFunction ("glEnd", WrapglEnd, noParam, true,  false,  VTP_INT);
    comp.AddFunction("glEndList", WrapglEndList,noParam, true, false, VTP_INT);
    comp.AddFunction("glEvalCoord1d", WrapglEvalCoord1d,compParamTypeList () << VTP_REAL, true, false, VTP_INT);
    comp.AddFunction("glEvalCoord1dv", WrapglEvalCoord1dv,compParamTypeList ()<<vmValType(VTP_REAL,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glEvalCoord1dv", WrapglEvalCoord1dv_2,compParamTypeList ()<<vmValType(VTP_REAL,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glEvalCoord1f", WrapglEvalCoord1f,compParamTypeList () << VTP_REAL, true, false, VTP_INT);
    comp.AddFunction("glEvalCoord1fv", WrapglEvalCoord1fv,compParamTypeList ()<<vmValType(VTP_REAL,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glEvalCoord1fv", WrapglEvalCoord1fv_2,compParamTypeList ()<<vmValType(VTP_REAL,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glEvalCoord2d", WrapglEvalCoord2d,compParamTypeList () << VTP_REAL << VTP_REAL, true, false, VTP_INT);
    comp.AddFunction("glEvalCoord2dv", WrapglEvalCoord2dv,compParamTypeList ()<<vmValType(VTP_REAL,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glEvalCoord2dv", WrapglEvalCoord2dv_2,compParamTypeList ()<<vmValType(VTP_REAL,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glEvalCoord2f", WrapglEvalCoord2f,compParamTypeList () << VTP_REAL << VTP_REAL, true, false, VTP_INT);
    comp.AddFunction("glEvalCoord2fv", WrapglEvalCoord2fv,compParamTypeList ()<<vmValType(VTP_REAL,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glEvalCoord2fv", WrapglEvalCoord2fv_2,compParamTypeList ()<<vmValType(VTP_REAL,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glEvalMesh1", WrapglEvalMesh1,compParamTypeList () << VTP_INT << VTP_INT << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glEvalMesh2", WrapglEvalMesh2,compParamTypeList () << VTP_INT << VTP_INT << VTP_INT << VTP_INT << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glEvalPoint1", WrapglEvalPoint1,compParamTypeList () << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glEvalPoint2", WrapglEvalPoint2,compParamTypeList () << VTP_INT << VTP_INT, true, false, VTP_INT);
//    comp.AddFunction("glFeedbackBuffer", WrapglFeedbackBuffer,compParamTypeList () << VTP_INT << VTP_INT<<vmValType(VTP_REAL,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glFinish", WrapglFinish,noParam, true, false, VTP_INT);
    comp.AddFunction("glFlush", WrapglFlush,noParam, true, false, VTP_INT);
    comp.AddFunction("glFogf", WrapglFogf,compParamTypeList () << VTP_INT << VTP_REAL, true, false, VTP_INT);
    comp.AddFunction("glFogfv", WrapglFogfv,compParamTypeList () << VTP_INT<<vmValType(VTP_REAL,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glFogfv", WrapglFogfv_2,compParamTypeList () << VTP_INT<<vmValType(VTP_REAL,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glFogi", WrapglFogi,compParamTypeList () << VTP_INT << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glFogiv", WrapglFogiv,compParamTypeList () << VTP_INT<<vmValType(VTP_INT,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glFogiv", WrapglFogiv_2,compParamTypeList () << VTP_INT<<vmValType(VTP_INT,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glFrontFace", WrapglFrontFace,compParamTypeList () << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glFrustum", WrapglFrustum,compParamTypeList () << VTP_REAL << VTP_REAL << VTP_REAL << VTP_REAL << VTP_REAL << VTP_REAL, true, false, VTP_INT);
    comp.AddFunction("glGetBooleanv", WrapglGetBooleanv,compParamTypeList () << VTP_INT<<vmValType(VTP_INT,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glGetBooleanv", WrapglGetBooleanv_2,compParamTypeList () << VTP_INT<<vmValType(VTP_INT,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glGetClipPlane", WrapglGetClipPlane,compParamTypeList () << VTP_INT<<vmValType(VTP_REAL,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glGetClipPlane", WrapglGetClipPlane_2,compParamTypeList () << VTP_INT<<vmValType(VTP_REAL,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glGetDoublev", WrapglGetDoublev,compParamTypeList () << VTP_INT<<vmValType(VTP_REAL,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glGetDoublev", WrapglGetDoublev_2,compParamTypeList () << VTP_INT<<vmValType(VTP_REAL,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glGetError", WrapglGetError,noParam, true, true, VTP_INT);
    comp.AddFunction("glGetFloatv", WrapglGetFloatv,compParamTypeList () << VTP_INT<<vmValType(VTP_REAL,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glGetFloatv", WrapglGetFloatv_2,compParamTypeList () << VTP_INT<<vmValType(VTP_REAL,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glGetIntegerv", WrapglGetIntegerv,compParamTypeList () << VTP_INT<<vmValType(VTP_INT,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glGetIntegerv", WrapglGetIntegerv_2,compParamTypeList () << VTP_INT<<vmValType(VTP_INT,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glGetLightfv", WrapglGetLightfv,compParamTypeList () << VTP_INT << VTP_INT<<vmValType(VTP_REAL,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glGetLightfv", WrapglGetLightfv_2,compParamTypeList () << VTP_INT << VTP_INT<<vmValType(VTP_REAL,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glGetLightiv", WrapglGetLightiv,compParamTypeList () << VTP_INT << VTP_INT<<vmValType(VTP_INT,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glGetLightiv", WrapglGetLightiv_2,compParamTypeList () << VTP_INT << VTP_INT<<vmValType(VTP_INT,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glGetMaterialfv", WrapglGetMaterialfv,compParamTypeList () << VTP_INT << VTP_INT<<vmValType(VTP_REAL,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glGetMaterialfv", WrapglGetMaterialfv_2,compParamTypeList () << VTP_INT << VTP_INT<<vmValType(VTP_REAL,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glGetMaterialiv", WrapglGetMaterialiv,compParamTypeList () << VTP_INT << VTP_INT<<vmValType(VTP_INT,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glGetMaterialiv", WrapglGetMaterialiv_2,compParamTypeList () << VTP_INT << VTP_INT<<vmValType(VTP_INT,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glGetPixelMapuiv", WrapglGetPixelMapuiv,compParamTypeList () << VTP_INT<<vmValType(VTP_INT,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glGetPixelMapuiv", WrapglGetPixelMapuiv_2,compParamTypeList () << VTP_INT<<vmValType(VTP_INT,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glGetTexEnvfv", WrapglGetTexEnvfv,compParamTypeList () << VTP_INT << VTP_INT<<vmValType(VTP_REAL,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glGetTexEnvfv", WrapglGetTexEnvfv_2,compParamTypeList () << VTP_INT << VTP_INT<<vmValType(VTP_REAL,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glGetTexEnviv", WrapglGetTexEnviv,compParamTypeList () << VTP_INT << VTP_INT<<vmValType(VTP_INT,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glGetTexEnviv", WrapglGetTexEnviv_2,compParamTypeList () << VTP_INT << VTP_INT<<vmValType(VTP_INT,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glGetTexGendv", WrapglGetTexGendv,compParamTypeList () << VTP_INT << VTP_INT<<vmValType(VTP_REAL,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glGetTexGendv", WrapglGetTexGendv_2,compParamTypeList () << VTP_INT << VTP_INT<<vmValType(VTP_REAL,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glGetTexGenfv", WrapglGetTexGenfv,compParamTypeList () << VTP_INT << VTP_INT<<vmValType(VTP_REAL,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glGetTexGenfv", WrapglGetTexGenfv_2,compParamTypeList () << VTP_INT << VTP_INT<<vmValType(VTP_REAL,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glGetTexGeniv", WrapglGetTexGeniv,compParamTypeList () << VTP_INT << VTP_INT<<vmValType(VTP_INT,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glGetTexGeniv", WrapglGetTexGeniv_2,compParamTypeList () << VTP_INT << VTP_INT<<vmValType(VTP_INT,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glGetTexLevelParameterfv", WrapglGetTexLevelParameterfv,compParamTypeList () << VTP_INT << VTP_INT << VTP_INT<<vmValType(VTP_REAL,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glGetTexLevelParameterfv", WrapglGetTexLevelParameterfv_2,compParamTypeList () << VTP_INT << VTP_INT << VTP_INT<<vmValType(VTP_REAL,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glGetTexLevelParameteriv", WrapglGetTexLevelParameteriv,compParamTypeList () << VTP_INT << VTP_INT << VTP_INT<<vmValType(VTP_INT,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glGetTexLevelParameteriv", WrapglGetTexLevelParameteriv_2,compParamTypeList () << VTP_INT << VTP_INT << VTP_INT<<vmValType(VTP_INT,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glGetTexParameterfv", WrapglGetTexParameterfv,compParamTypeList () << VTP_INT << VTP_INT<<vmValType(VTP_REAL,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glGetTexParameterfv", WrapglGetTexParameterfv_2,compParamTypeList () << VTP_INT << VTP_INT<<vmValType(VTP_REAL,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glGetTexParameteriv", WrapglGetTexParameteriv,compParamTypeList () << VTP_INT << VTP_INT<<vmValType(VTP_INT,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glGetTexParameteriv", WrapglGetTexParameteriv_2,compParamTypeList () << VTP_INT << VTP_INT<<vmValType(VTP_INT,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glHint", WrapglHint,compParamTypeList () << VTP_INT << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glIndexMask", WrapglIndexMask,compParamTypeList () << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glIndexd", WrapglIndexd,compParamTypeList () << VTP_REAL, true, false, VTP_INT);
    comp.AddFunction("glIndexdv", WrapglIndexdv,compParamTypeList ()<<vmValType(VTP_REAL,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glIndexdv", WrapglIndexdv_2,compParamTypeList ()<<vmValType(VTP_REAL,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glIndexf", WrapglIndexf,compParamTypeList () << VTP_REAL, true, false, VTP_INT);
    comp.AddFunction("glIndexfv", WrapglIndexfv,compParamTypeList ()<<vmValType(VTP_REAL,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glIndexfv", WrapglIndexfv_2,compParamTypeList ()<<vmValType(VTP_REAL,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glIndexi", WrapglIndexi,compParamTypeList () << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glIndexiv", WrapglIndexiv,compParamTypeList ()<<vmValType(VTP_INT,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glIndexiv", WrapglIndexiv_2,compParamTypeList ()<<vmValType(VTP_INT,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glIndexs", WrapglIndexs,compParamTypeList () << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glIndexsv", WrapglIndexsv,compParamTypeList ()<<vmValType(VTP_INT,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glIndexsv", WrapglIndexsv_2,compParamTypeList ()<<vmValType(VTP_INT,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glIndexub", WrapglIndexub,compParamTypeList () << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glIndexubv", WrapglIndexubv,compParamTypeList ()<<vmValType(VTP_INT,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glIndexubv", WrapglIndexubv_2,compParamTypeList ()<<vmValType(VTP_INT,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glInitNames", WrapglInitNames,noParam, true, false, VTP_INT);
    comp.AddFunction("glIsEnabled", WrapglIsEnabled,compParamTypeList () << VTP_INT, true, true, VTP_INT);
    comp.AddFunction("glIsList", WrapglIsList,compParamTypeList () << VTP_INT, true, true, VTP_INT);
    comp.AddFunction("glIsTexture", WrapglIsTexture,compParamTypeList () << VTP_INT, true, true, VTP_INT);
    comp.AddFunction("glLightModelf", WrapglLightModelf,compParamTypeList () << VTP_INT << VTP_REAL, true, false, VTP_INT);
    comp.AddFunction("glLightModelfv", WrapglLightModelfv,compParamTypeList () << VTP_INT<<vmValType(VTP_REAL,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glLightModelfv", WrapglLightModelfv_2,compParamTypeList () << VTP_INT<<vmValType(VTP_REAL,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glLightModeli", WrapglLightModeli,compParamTypeList () << VTP_INT << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glLightModeliv", WrapglLightModeliv,compParamTypeList () << VTP_INT<<vmValType(VTP_INT,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glLightModeliv", WrapglLightModeliv_2,compParamTypeList () << VTP_INT<<vmValType(VTP_INT,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glLightf", WrapglLightf,compParamTypeList () << VTP_INT << VTP_INT << VTP_REAL, true, false, VTP_INT);
    comp.AddFunction("glLightfv", WrapglLightfv,compParamTypeList () << VTP_INT << VTP_INT<<vmValType(VTP_REAL,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glLightfv", WrapglLightfv_2,compParamTypeList () << VTP_INT << VTP_INT<<vmValType(VTP_REAL,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glLighti", WrapglLighti,compParamTypeList () << VTP_INT << VTP_INT << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glLightiv", WrapglLightiv,compParamTypeList () << VTP_INT << VTP_INT<<vmValType(VTP_INT,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glLightiv", WrapglLightiv_2,compParamTypeList () << VTP_INT << VTP_INT<<vmValType(VTP_INT,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glLineStipple", WrapglLineStipple,compParamTypeList () << VTP_INT << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glLineWidth", WrapglLineWidth,compParamTypeList () << VTP_REAL, true, false, VTP_INT);
    comp.AddFunction("glListBase", WrapglListBase,compParamTypeList () << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glLoadIdentity", WrapglLoadIdentity,noParam, true, false, VTP_INT);
    comp.AddFunction("glLoadName", WrapglLoadName,compParamTypeList () << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glLogicOp", WrapglLogicOp,compParamTypeList () << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glMapGrid1d", WrapglMapGrid1d,compParamTypeList () << VTP_INT << VTP_REAL << VTP_REAL, true, false, VTP_INT);
    comp.AddFunction("glMapGrid1f", WrapglMapGrid1f,compParamTypeList () << VTP_INT << VTP_REAL << VTP_REAL, true, false, VTP_INT);
    comp.AddFunction("glMapGrid2d", WrapglMapGrid2d,compParamTypeList () << VTP_INT << VTP_REAL << VTP_REAL << VTP_INT << VTP_REAL << VTP_REAL, true, false, VTP_INT);
    comp.AddFunction("glMapGrid2f", WrapglMapGrid2f,compParamTypeList () << VTP_INT << VTP_REAL << VTP_REAL << VTP_INT << VTP_REAL << VTP_REAL, true, false, VTP_INT);
    comp.AddFunction("glMaterialf", WrapglMaterialf,compParamTypeList () << VTP_INT << VTP_INT << VTP_REAL, true, false, VTP_INT);
    comp.AddFunction("glMaterialfv", WrapglMaterialfv,compParamTypeList () << VTP_INT << VTP_INT<<vmValType(VTP_REAL,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glMaterialfv", WrapglMaterialfv_2,compParamTypeList () << VTP_INT << VTP_INT<<vmValType(VTP_REAL,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glMateriali", WrapglMateriali,compParamTypeList () << VTP_INT << VTP_INT << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glMaterialiv", WrapglMaterialiv,compParamTypeList () << VTP_INT << VTP_INT<<vmValType(VTP_INT,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glMaterialiv", WrapglMaterialiv_2,compParamTypeList () << VTP_INT << VTP_INT<<vmValType(VTP_INT,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glMatrixMode", WrapglMatrixMode,compParamTypeList () << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glNewList", WrapglNewList,compParamTypeList () << VTP_INT << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glNormal3b", WrapglNormal3b,compParamTypeList () << VTP_INT << VTP_INT << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glNormal3bv", WrapglNormal3bv,compParamTypeList ()<<vmValType(VTP_INT,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glNormal3bv", WrapglNormal3bv_2,compParamTypeList ()<<vmValType(VTP_INT,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glNormal3d", WrapglNormal3d,compParamTypeList () << VTP_REAL << VTP_REAL << VTP_REAL, true, false, VTP_INT);
    comp.AddFunction("glNormal3dv", WrapglNormal3dv,compParamTypeList ()<<vmValType(VTP_REAL,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glNormal3dv", WrapglNormal3dv_2,compParamTypeList ()<<vmValType(VTP_REAL,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glNormal3f", WrapglNormal3f,compParamTypeList () << VTP_REAL << VTP_REAL << VTP_REAL, true, false, VTP_INT);
    comp.AddFunction("glNormal3fv", WrapglNormal3fv,compParamTypeList ()<<vmValType(VTP_REAL,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glNormal3fv", WrapglNormal3fv_2,compParamTypeList ()<<vmValType(VTP_REAL,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glNormal3i", WrapglNormal3i,compParamTypeList () << VTP_INT << VTP_INT << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glNormal3iv", WrapglNormal3iv,compParamTypeList ()<<vmValType(VTP_INT,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glNormal3iv", WrapglNormal3iv_2,compParamTypeList ()<<vmValType(VTP_INT,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glNormal3s", WrapglNormal3s,compParamTypeList () << VTP_INT << VTP_INT << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glNormal3sv", WrapglNormal3sv,compParamTypeList ()<<vmValType(VTP_INT,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glNormal3sv", WrapglNormal3sv_2,compParamTypeList ()<<vmValType(VTP_INT,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glOrtho", WrapglOrtho,compParamTypeList () << VTP_REAL << VTP_REAL << VTP_REAL << VTP_REAL << VTP_REAL << VTP_REAL, true, false, VTP_INT);
    comp.AddFunction("glPassThrough", WrapglPassThrough,compParamTypeList () << VTP_REAL, true, false, VTP_INT);
    comp.AddFunction("glPixelStoref", WrapglPixelStoref,compParamTypeList () << VTP_INT << VTP_REAL, true, false, VTP_INT);
    comp.AddFunction("glPixelStorei", WrapglPixelStorei,compParamTypeList () << VTP_INT << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glPixelTransferf", WrapglPixelTransferf,compParamTypeList () << VTP_INT << VTP_REAL, true, false, VTP_INT);
    comp.AddFunction("glPixelTransferi", WrapglPixelTransferi,compParamTypeList () << VTP_INT << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glPixelZoom", WrapglPixelZoom,compParamTypeList () << VTP_REAL << VTP_REAL, true, false, VTP_INT);
    comp.AddFunction("glPointSize", WrapglPointSize,compParamTypeList () << VTP_REAL, true, false, VTP_INT);
    comp.AddFunction("glPolygonMode", WrapglPolygonMode,compParamTypeList () << VTP_INT << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glPolygonOffset", WrapglPolygonOffset,compParamTypeList () << VTP_REAL << VTP_REAL, true, false, VTP_INT);

    comp.AddFunction("glPopAttrib", WrapglPopAttrib,noParam, true, false, VTP_INT);
    comp.AddFunction("glPopClientAttrib", WrapglPopClientAttrib,noParam, true, false, VTP_INT);
    comp.AddFunction("glPopMatrix", WrapglPopMatrix,noParam, true, false, VTP_INT);
    comp.AddFunction("glPopName", WrapglPopName,noParam, true, false, VTP_INT);
//    comp.AddFunction("glPrioritizeTextures", WrapglPrioritizeTextures,compParamTypeList () << VTP_INT<<vmValType(VTP_INT,1,1,true)<<vmValType(VTP_REAL,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glPushAttrib", WrapglPushAttrib,compParamTypeList () << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glPushClientAttrib", WrapglPushClientAttrib,compParamTypeList () << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glPushMatrix", WrapglPushMatrix,noParam, true, false, VTP_INT);
    comp.AddFunction("glPushName", WrapglPushName,compParamTypeList () << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glRasterPos2d", WrapglRasterPos2d,compParamTypeList () << VTP_REAL << VTP_REAL, true, false, VTP_INT);
    comp.AddFunction("glRasterPos2dv", WrapglRasterPos2dv,compParamTypeList ()<<vmValType(VTP_REAL,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glRasterPos2dv", WrapglRasterPos2dv_2,compParamTypeList ()<<vmValType(VTP_REAL,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glRasterPos2f", WrapglRasterPos2f,compParamTypeList () << VTP_REAL << VTP_REAL, true, false, VTP_INT);
    comp.AddFunction("glRasterPos2fv", WrapglRasterPos2fv,compParamTypeList ()<<vmValType(VTP_REAL,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glRasterPos2fv", WrapglRasterPos2fv_2,compParamTypeList ()<<vmValType(VTP_REAL,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glRasterPos2i", WrapglRasterPos2i,compParamTypeList () << VTP_INT << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glRasterPos2iv", WrapglRasterPos2iv,compParamTypeList ()<<vmValType(VTP_INT,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glRasterPos2iv", WrapglRasterPos2iv_2,compParamTypeList ()<<vmValType(VTP_INT,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glRasterPos2s", WrapglRasterPos2s,compParamTypeList () << VTP_INT << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glRasterPos2sv", WrapglRasterPos2sv,compParamTypeList ()<<vmValType(VTP_INT,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glRasterPos2sv", WrapglRasterPos2sv_2,compParamTypeList ()<<vmValType(VTP_INT,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glRasterPos3d", WrapglRasterPos3d,compParamTypeList () << VTP_REAL << VTP_REAL << VTP_REAL, true, false, VTP_INT);
    comp.AddFunction("glRasterPos3dv", WrapglRasterPos3dv,compParamTypeList ()<<vmValType(VTP_REAL,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glRasterPos3dv", WrapglRasterPos3dv_2,compParamTypeList ()<<vmValType(VTP_REAL,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glRasterPos3f", WrapglRasterPos3f,compParamTypeList () << VTP_REAL << VTP_REAL << VTP_REAL, true, false, VTP_INT);
    comp.AddFunction("glRasterPos3fv", WrapglRasterPos3fv,compParamTypeList ()<<vmValType(VTP_REAL,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glRasterPos3fv", WrapglRasterPos3fv_2,compParamTypeList ()<<vmValType(VTP_REAL,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glRasterPos3i", WrapglRasterPos3i,compParamTypeList () << VTP_INT << VTP_INT << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glRasterPos3iv", WrapglRasterPos3iv,compParamTypeList ()<<vmValType(VTP_INT,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glRasterPos3iv", WrapglRasterPos3iv_2,compParamTypeList ()<<vmValType(VTP_INT,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glRasterPos3s", WrapglRasterPos3s,compParamTypeList () << VTP_INT << VTP_INT << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glRasterPos3sv", WrapglRasterPos3sv,compParamTypeList ()<<vmValType(VTP_INT,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glRasterPos3sv", WrapglRasterPos3sv_2,compParamTypeList ()<<vmValType(VTP_INT,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glRasterPos4d", WrapglRasterPos4d,compParamTypeList () << VTP_REAL << VTP_REAL << VTP_REAL << VTP_REAL, true, false, VTP_INT);
    comp.AddFunction("glRasterPos4dv", WrapglRasterPos4dv,compParamTypeList ()<<vmValType(VTP_REAL,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glRasterPos4dv", WrapglRasterPos4dv_2,compParamTypeList ()<<vmValType(VTP_REAL,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glRasterPos4f", WrapglRasterPos4f,compParamTypeList () << VTP_REAL << VTP_REAL << VTP_REAL << VTP_REAL, true, false, VTP_INT);
    comp.AddFunction("glRasterPos4fv", WrapglRasterPos4fv,compParamTypeList ()<<vmValType(VTP_REAL,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glRasterPos4fv", WrapglRasterPos4fv_2,compParamTypeList ()<<vmValType(VTP_REAL,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glRasterPos4i", WrapglRasterPos4i,compParamTypeList () << VTP_INT << VTP_INT << VTP_INT << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glRasterPos4iv", WrapglRasterPos4iv,compParamTypeList ()<<vmValType(VTP_INT,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glRasterPos4iv", WrapglRasterPos4iv_2,compParamTypeList ()<<vmValType(VTP_INT,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glRasterPos4s", WrapglRasterPos4s,compParamTypeList () << VTP_INT << VTP_INT << VTP_INT << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glRasterPos4sv", WrapglRasterPos4sv,compParamTypeList ()<<vmValType(VTP_INT,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glRasterPos4sv", WrapglRasterPos4sv_2,compParamTypeList ()<<vmValType(VTP_INT,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glReadBuffer", WrapglReadBuffer,compParamTypeList () << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glRectd", WrapglRectd,compParamTypeList () << VTP_REAL << VTP_REAL << VTP_REAL << VTP_REAL, true, false, VTP_INT);
    comp.AddFunction("glRectdv", WrapglRectdv,compParamTypeList ()<<vmValType(VTP_REAL,1,1,true)<<vmValType(VTP_REAL,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glRectdv", WrapglRectdv_2,compParamTypeList ()<<vmValType(VTP_REAL,0,1,true)<<vmValType(VTP_REAL,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glRectdv", WrapglRectdv_3,compParamTypeList ()<<vmValType(VTP_REAL,1,1,true)<<vmValType(VTP_REAL,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glRectdv", WrapglRectdv_4,compParamTypeList ()<<vmValType(VTP_REAL,0,1,true)<<vmValType(VTP_REAL,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glRectf", WrapglRectf,compParamTypeList () << VTP_REAL << VTP_REAL << VTP_REAL << VTP_REAL, true, false, VTP_INT);
    comp.AddFunction("glRectfv", WrapglRectfv,compParamTypeList ()<<vmValType(VTP_REAL,1,1,true)<<vmValType(VTP_REAL,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glRectfv", WrapglRectfv_2,compParamTypeList ()<<vmValType(VTP_REAL,0,1,true)<<vmValType(VTP_REAL,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glRectfv", WrapglRectfv_3,compParamTypeList ()<<vmValType(VTP_REAL,1,1,true)<<vmValType(VTP_REAL,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glRectfv", WrapglRectfv_4,compParamTypeList ()<<vmValType(VTP_REAL,0,1,true)<<vmValType(VTP_REAL,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glRecti", WrapglRecti,compParamTypeList () << VTP_INT << VTP_INT << VTP_INT << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glRectiv", WrapglRectiv,compParamTypeList ()<<vmValType(VTP_INT,1,1,true)<<vmValType(VTP_INT,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glRectiv", WrapglRectiv_2,compParamTypeList ()<<vmValType(VTP_INT,0,1,true)<<vmValType(VTP_INT,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glRectiv", WrapglRectiv_3,compParamTypeList ()<<vmValType(VTP_INT,1,1,true)<<vmValType(VTP_INT,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glRectiv", WrapglRectiv_4,compParamTypeList ()<<vmValType(VTP_INT,0,1,true)<<vmValType(VTP_INT,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glRects", WrapglRects,compParamTypeList () << VTP_INT << VTP_INT << VTP_INT << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glRectsv", WrapglRectsv,compParamTypeList ()<<vmValType(VTP_INT,1,1,true)<<vmValType(VTP_INT,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glRectsv", WrapglRectsv_2,compParamTypeList ()<<vmValType(VTP_INT,0,1,true)<<vmValType(VTP_INT,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glRectsv", WrapglRectsv_3,compParamTypeList ()<<vmValType(VTP_INT,1,1,true)<<vmValType(VTP_INT,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glRectsv", WrapglRectsv_4,compParamTypeList ()<<vmValType(VTP_INT,0,1,true)<<vmValType(VTP_INT,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glRenderMode", WrapglRenderMode,compParamTypeList () << VTP_INT, true, true, VTP_INT);
    comp.AddFunction("glRotated", WrapglRotated,compParamTypeList () << VTP_REAL << VTP_REAL << VTP_REAL << VTP_REAL, true, false, VTP_INT);
    comp.AddFunction("glRotatef", WrapglRotatef,compParamTypeList () << VTP_REAL << VTP_REAL << VTP_REAL << VTP_REAL, true, false, VTP_INT);
    comp.AddFunction("glScaled", WrapglScaled,compParamTypeList () << VTP_REAL << VTP_REAL << VTP_REAL, true, false, VTP_INT);
    comp.AddFunction("glScalef", WrapglScalef,compParamTypeList () << VTP_REAL << VTP_REAL << VTP_REAL, true, false, VTP_INT);
    comp.AddFunction("glScissor", WrapglScissor,compParamTypeList () << VTP_INT << VTP_INT << VTP_INT << VTP_INT, true, false, VTP_INT);
//    comp.AddFunction("glSelectBuffer", WrapglSelectBuffer,compParamTypeList () << VTP_INT<<vmValType(VTP_INT,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glShadeModel", WrapglShadeModel,compParamTypeList () << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glStencilFunc", WrapglStencilFunc,compParamTypeList () << VTP_INT << VTP_INT << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glStencilMask", WrapglStencilMask,compParamTypeList () << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glStencilOp", WrapglStencilOp,compParamTypeList () << VTP_INT << VTP_INT << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glTexCoord1d", WrapglTexCoord1d,compParamTypeList () << VTP_REAL, true, false, VTP_INT);
    comp.AddFunction("glTexCoord1dv", WrapglTexCoord1dv,compParamTypeList ()<<vmValType(VTP_REAL,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glTexCoord1dv", WrapglTexCoord1dv_2,compParamTypeList ()<<vmValType(VTP_REAL,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glTexCoord1f", WrapglTexCoord1f,compParamTypeList () << VTP_REAL, true, false, VTP_INT);
    comp.AddFunction("glTexCoord1fv", WrapglTexCoord1fv,compParamTypeList ()<<vmValType(VTP_REAL,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glTexCoord1fv", WrapglTexCoord1fv_2,compParamTypeList ()<<vmValType(VTP_REAL,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glTexCoord1i", WrapglTexCoord1i,compParamTypeList () << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glTexCoord1iv", WrapglTexCoord1iv,compParamTypeList ()<<vmValType(VTP_INT,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glTexCoord1iv", WrapglTexCoord1iv_2,compParamTypeList ()<<vmValType(VTP_INT,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glTexCoord1s", WrapglTexCoord1s,compParamTypeList () << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glTexCoord1sv", WrapglTexCoord1sv,compParamTypeList ()<<vmValType(VTP_INT,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glTexCoord1sv", WrapglTexCoord1sv_2,compParamTypeList ()<<vmValType(VTP_INT,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glTexCoord2d", WrapglTexCoord2d,compParamTypeList () << VTP_REAL << VTP_REAL, true, false, VTP_INT);
    comp.AddFunction("glTexCoord2dv", WrapglTexCoord2dv,compParamTypeList ()<<vmValType(VTP_REAL,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glTexCoord2dv", WrapglTexCoord2dv_2,compParamTypeList ()<<vmValType(VTP_REAL,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glTexCoord2f", WrapglTexCoord2f,compParamTypeList () << VTP_REAL << VTP_REAL, true, false, VTP_INT);
    comp.AddFunction("glTexCoord2fv", WrapglTexCoord2fv,compParamTypeList ()<<vmValType(VTP_REAL,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glTexCoord2fv", WrapglTexCoord2fv_2,compParamTypeList ()<<vmValType(VTP_REAL,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glTexCoord2i", WrapglTexCoord2i,compParamTypeList () << VTP_INT << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glTexCoord2iv", WrapglTexCoord2iv,compParamTypeList ()<<vmValType(VTP_INT,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glTexCoord2iv", WrapglTexCoord2iv_2,compParamTypeList ()<<vmValType(VTP_INT,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glTexCoord2s", WrapglTexCoord2s,compParamTypeList () << VTP_INT << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glTexCoord2sv", WrapglTexCoord2sv,compParamTypeList ()<<vmValType(VTP_INT,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glTexCoord2sv", WrapglTexCoord2sv_2,compParamTypeList ()<<vmValType(VTP_INT,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glTexCoord3d", WrapglTexCoord3d,compParamTypeList () << VTP_REAL << VTP_REAL << VTP_REAL, true, false, VTP_INT);
    comp.AddFunction("glTexCoord3dv", WrapglTexCoord3dv,compParamTypeList ()<<vmValType(VTP_REAL,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glTexCoord3dv", WrapglTexCoord3dv_2,compParamTypeList ()<<vmValType(VTP_REAL,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glTexCoord3f", WrapglTexCoord3f,compParamTypeList () << VTP_REAL << VTP_REAL << VTP_REAL, true, false, VTP_INT);
    comp.AddFunction("glTexCoord3fv", WrapglTexCoord3fv,compParamTypeList ()<<vmValType(VTP_REAL,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glTexCoord3fv", WrapglTexCoord3fv_2,compParamTypeList ()<<vmValType(VTP_REAL,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glTexCoord3i", WrapglTexCoord3i,compParamTypeList () << VTP_INT << VTP_INT << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glTexCoord3iv", WrapglTexCoord3iv,compParamTypeList ()<<vmValType(VTP_INT,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glTexCoord3iv", WrapglTexCoord3iv_2,compParamTypeList ()<<vmValType(VTP_INT,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glTexCoord3s", WrapglTexCoord3s,compParamTypeList () << VTP_INT << VTP_INT << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glTexCoord3sv", WrapglTexCoord3sv,compParamTypeList ()<<vmValType(VTP_INT,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glTexCoord3sv", WrapglTexCoord3sv_2,compParamTypeList ()<<vmValType(VTP_INT,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glTexCoord4d", WrapglTexCoord4d,compParamTypeList () << VTP_REAL << VTP_REAL << VTP_REAL << VTP_REAL, true, false, VTP_INT);
    comp.AddFunction("glTexCoord4dv", WrapglTexCoord4dv,compParamTypeList ()<<vmValType(VTP_REAL,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glTexCoord4dv", WrapglTexCoord4dv_2,compParamTypeList ()<<vmValType(VTP_REAL,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glTexCoord4f", WrapglTexCoord4f,compParamTypeList () << VTP_REAL << VTP_REAL << VTP_REAL << VTP_REAL, true, false, VTP_INT);
    comp.AddFunction("glTexCoord4fv", WrapglTexCoord4fv,compParamTypeList ()<<vmValType(VTP_REAL,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glTexCoord4fv", WrapglTexCoord4fv_2,compParamTypeList ()<<vmValType(VTP_REAL,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glTexCoord4i", WrapglTexCoord4i,compParamTypeList () << VTP_INT << VTP_INT << VTP_INT << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glTexCoord4iv", WrapglTexCoord4iv,compParamTypeList ()<<vmValType(VTP_INT,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glTexCoord4iv", WrapglTexCoord4iv_2,compParamTypeList ()<<vmValType(VTP_INT,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glTexCoord4s", WrapglTexCoord4s,compParamTypeList () << VTP_INT << VTP_INT << VTP_INT << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glTexCoord4sv", WrapglTexCoord4sv,compParamTypeList ()<<vmValType(VTP_INT,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glTexCoord4sv", WrapglTexCoord4sv_2,compParamTypeList ()<<vmValType(VTP_INT,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glTexEnvf", WrapglTexEnvf,compParamTypeList () << VTP_INT << VTP_INT << VTP_REAL, true, false, VTP_INT);
    comp.AddFunction("glTexEnvfv", WrapglTexEnvfv,compParamTypeList () << VTP_INT << VTP_INT<<vmValType(VTP_REAL,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glTexEnvfv", WrapglTexEnvfv_2,compParamTypeList () << VTP_INT << VTP_INT<<vmValType(VTP_REAL,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glTexEnvi", WrapglTexEnvi,compParamTypeList () << VTP_INT << VTP_INT << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glTexEnviv", WrapglTexEnviv,compParamTypeList () << VTP_INT << VTP_INT<<vmValType(VTP_INT,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glTexEnviv", WrapglTexEnviv_2,compParamTypeList () << VTP_INT << VTP_INT<<vmValType(VTP_INT,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glTexGend", WrapglTexGend,compParamTypeList () << VTP_INT << VTP_INT << VTP_REAL, true, false, VTP_INT);
    comp.AddFunction("glTexGendv", WrapglTexGendv,compParamTypeList () << VTP_INT << VTP_INT<<vmValType(VTP_REAL,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glTexGendv", WrapglTexGendv_2,compParamTypeList () << VTP_INT << VTP_INT<<vmValType(VTP_REAL,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glTexGenf", WrapglTexGenf,compParamTypeList () << VTP_INT << VTP_INT << VTP_REAL, true, false, VTP_INT);
    comp.AddFunction("glTexGenfv", WrapglTexGenfv,compParamTypeList () << VTP_INT << VTP_INT<<vmValType(VTP_REAL,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glTexGenfv", WrapglTexGenfv_2,compParamTypeList () << VTP_INT << VTP_INT<<vmValType(VTP_REAL,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glTexGeni", WrapglTexGeni,compParamTypeList () << VTP_INT << VTP_INT << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glTexGeniv", WrapglTexGeniv,compParamTypeList () << VTP_INT << VTP_INT<<vmValType(VTP_INT,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glTexGeniv", WrapglTexGeniv_2,compParamTypeList () << VTP_INT << VTP_INT<<vmValType(VTP_INT,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glTexParameterf", WrapglTexParameterf,compParamTypeList () << VTP_INT << VTP_INT << VTP_REAL, true, false, VTP_INT);
    comp.AddFunction("glTexParameterfv", WrapglTexParameterfv,compParamTypeList () << VTP_INT << VTP_INT<<vmValType(VTP_REAL,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glTexParameterfv", WrapglTexParameterfv_2,compParamTypeList () << VTP_INT << VTP_INT<<vmValType(VTP_REAL,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glTexParameteri", WrapglTexParameteri,compParamTypeList () << VTP_INT << VTP_INT << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glTexParameteriv", WrapglTexParameteriv,compParamTypeList () << VTP_INT << VTP_INT<<vmValType(VTP_INT,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glTexParameteriv", WrapglTexParameteriv_2,compParamTypeList () << VTP_INT << VTP_INT<<vmValType(VTP_INT,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glTranslated", WrapglTranslated,compParamTypeList () << VTP_REAL << VTP_REAL << VTP_REAL, true, false, VTP_INT);
    comp.AddFunction("glTranslatef", WrapglTranslatef,compParamTypeList () << VTP_REAL << VTP_REAL << VTP_REAL, true, false, VTP_INT);
    comp.AddFunction("glVertex2d", WrapglVertex2d,compParamTypeList () << VTP_REAL << VTP_REAL, true, false, VTP_INT);
    comp.AddFunction("glVertex2dv", WrapglVertex2dv,compParamTypeList ()<<vmValType(VTP_REAL,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glVertex2dv", WrapglVertex2dv_2,compParamTypeList ()<<vmValType(VTP_REAL,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glVertex2f", WrapglVertex2f,compParamTypeList () << VTP_REAL << VTP_REAL, true, false, VTP_INT);
    comp.AddFunction("glVertex2fv", WrapglVertex2fv,compParamTypeList ()<<vmValType(VTP_REAL,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glVertex2fv", WrapglVertex2fv_2,compParamTypeList ()<<vmValType(VTP_REAL,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glVertex2i", WrapglVertex2i,compParamTypeList () << VTP_INT << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glVertex2iv", WrapglVertex2iv,compParamTypeList ()<<vmValType(VTP_INT,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glVertex2iv", WrapglVertex2iv_2,compParamTypeList ()<<vmValType(VTP_INT,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glVertex2s", WrapglVertex2s,compParamTypeList () << VTP_INT << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glVertex2sv", WrapglVertex2sv,compParamTypeList ()<<vmValType(VTP_INT,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glVertex2sv", WrapglVertex2sv_2,compParamTypeList ()<<vmValType(VTP_INT,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glVertex3d", WrapglVertex3d,compParamTypeList () << VTP_REAL << VTP_REAL << VTP_REAL, true, false, VTP_INT);
    comp.AddFunction("glVertex3dv", WrapglVertex3dv,compParamTypeList ()<<vmValType(VTP_REAL,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glVertex3dv", WrapglVertex3dv_2,compParamTypeList ()<<vmValType(VTP_REAL,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glVertex3f", WrapglVertex3f,compParamTypeList () << VTP_REAL << VTP_REAL << VTP_REAL, true, false, VTP_INT);
    comp.AddFunction("glVertex3fv", WrapglVertex3fv,compParamTypeList ()<<vmValType(VTP_REAL,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glVertex3fv", WrapglVertex3fv_2,compParamTypeList ()<<vmValType(VTP_REAL,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glVertex3i", WrapglVertex3i,compParamTypeList () << VTP_INT << VTP_INT << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glVertex3iv", WrapglVertex3iv,compParamTypeList ()<<vmValType(VTP_INT,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glVertex3iv", WrapglVertex3iv_2,compParamTypeList ()<<vmValType(VTP_INT,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glVertex3s", WrapglVertex3s,compParamTypeList () << VTP_INT << VTP_INT << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glVertex3sv", WrapglVertex3sv,compParamTypeList ()<<vmValType(VTP_INT,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glVertex3sv", WrapglVertex3sv_2,compParamTypeList ()<<vmValType(VTP_INT,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glVertex4d", WrapglVertex4d,compParamTypeList () << VTP_REAL << VTP_REAL << VTP_REAL << VTP_REAL, true, false, VTP_INT);
    comp.AddFunction("glVertex4dv", WrapglVertex4dv,compParamTypeList ()<<vmValType(VTP_REAL,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glVertex4dv", WrapglVertex4dv_2,compParamTypeList ()<<vmValType(VTP_REAL,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glVertex4f", WrapglVertex4f,compParamTypeList () << VTP_REAL << VTP_REAL << VTP_REAL << VTP_REAL, true, false, VTP_INT);
    comp.AddFunction("glVertex4fv", WrapglVertex4fv,compParamTypeList ()<<vmValType(VTP_REAL,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glVertex4fv", WrapglVertex4fv_2,compParamTypeList ()<<vmValType(VTP_REAL,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glVertex4i", WrapglVertex4i,compParamTypeList () << VTP_INT << VTP_INT << VTP_INT << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glVertex4iv", WrapglVertex4iv,compParamTypeList ()<<vmValType(VTP_INT,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glVertex4iv", WrapglVertex4iv_2,compParamTypeList ()<<vmValType(VTP_INT,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glVertex4s", WrapglVertex4s,compParamTypeList () << VTP_INT << VTP_INT << VTP_INT << VTP_INT, true, false, VTP_INT);
    comp.AddFunction("glVertex4sv", WrapglVertex4sv,compParamTypeList ()<<vmValType(VTP_INT,1,1,true), true, false, VTP_INT);
    comp.AddFunction("glVertex4sv", WrapglVertex4sv_2,compParamTypeList ()<<vmValType(VTP_INT,0,1,true), true, false, VTP_INT);
    comp.AddFunction("glViewport", WrapglViewport,compParamTypeList () << VTP_INT << VTP_INT << VTP_INT << VTP_INT, true, false, VTP_INT);
    comp.AddFunction ("glGenTextures", WrapglGenTexture, compParamTypeList () << VTP_INT << VTP_INT, true, true, VTP_INT);
}
