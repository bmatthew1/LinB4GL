#include "GLBasicLib_glu.h"
#include <GL/glut.h>
// Function wrappers

void WrapgluOrtho2D(TomVM& vm) { gluOrtho2D(vm.GetRealParam (4), vm.GetRealParam (3), vm.GetRealParam (2), vm.GetRealParam (1));};
void WrapgluPerspective(TomVM& vm) { gluPerspective(vm.GetRealParam (4), vm.GetRealParam (3), vm.GetRealParam (2), vm.GetRealParam (1));};
void WrapgluLookAt(TomVM& vm) { gluLookAt(vm.GetRealParam (9), vm.GetRealParam (8), vm.GetRealParam (7), vm.GetRealParam (6), vm.GetRealParam (5), vm.GetRealParam (4), vm.GetRealParam (3), vm.GetRealParam (2), vm.GetRealParam (1));};

// Initialisation

void InitGLBasicLib_glu(TomBasicCompiler& comp) {

    // Constants

    comp.AddConstant("GLU_VERSION_1_1", GLU_VERSION_1_1);
    comp.AddConstant("GLU_VERSION_1_2", GLU_VERSION_1_2);
    comp.AddConstant("GLU_INVALID_ENUM", GLU_INVALID_ENUM);
    comp.AddConstant("GLU_INVALID_VALUE", GLU_INVALID_VALUE);
    comp.AddConstant("GLU_OUT_OF_MEMORY", GLU_OUT_OF_MEMORY);
    comp.AddConstant("GLU_INCOMPATIBLE_GL_VERSION", GLU_INCOMPATIBLE_GL_VERSION);
    comp.AddConstant("GLU_VERSION", GLU_VERSION);
    comp.AddConstant("GLU_EXTENSIONS", GLU_EXTENSIONS);
    comp.AddConstant("GLU_TRUE", GLU_TRUE);
    comp.AddConstant("GLU_FALSE", GLU_FALSE);
    comp.AddConstant("GLU_SMOOTH", GLU_SMOOTH);
    comp.AddConstant("GLU_FLAT", GLU_FLAT);
    comp.AddConstant("GLU_NONE", GLU_NONE);
    comp.AddConstant("GLU_POINT", GLU_POINT);
    comp.AddConstant("GLU_LINE", GLU_LINE);
    comp.AddConstant("GLU_FILL", GLU_FILL);
    comp.AddConstant("GLU_SILHOUETTE", GLU_SILHOUETTE);
    comp.AddConstant("GLU_OUTSIDE", GLU_OUTSIDE);
    comp.AddConstant("GLU_INSIDE", GLU_INSIDE);
    comp.AddConstant("GLU_TESS_WINDING_RULE", GLU_TESS_WINDING_RULE);
    comp.AddConstant("GLU_TESS_BOUNDARY_ONLY", GLU_TESS_BOUNDARY_ONLY);
    comp.AddConstant("GLU_TESS_TOLERANCE", GLU_TESS_TOLERANCE);
    comp.AddConstant("GLU_TESS_WINDING_ODD", GLU_TESS_WINDING_ODD);
    comp.AddConstant("GLU_TESS_WINDING_NONZERO", GLU_TESS_WINDING_NONZERO);
    comp.AddConstant("GLU_TESS_WINDING_POSITIVE", GLU_TESS_WINDING_POSITIVE);
    comp.AddConstant("GLU_TESS_WINDING_NEGATIVE", GLU_TESS_WINDING_NEGATIVE);
    comp.AddConstant("GLU_TESS_WINDING_ABS_GEQ_TWO", GLU_TESS_WINDING_ABS_GEQ_TWO);
    comp.AddConstant("GLU_TESS_BEGIN", GLU_TESS_BEGIN);
    comp.AddConstant("GLU_TESS_VERTEX", GLU_TESS_VERTEX);
    comp.AddConstant("GLU_TESS_END", GLU_TESS_END);
    comp.AddConstant("GLU_TESS_ERROR", GLU_TESS_ERROR);
    comp.AddConstant("GLU_TESS_EDGE_FLAG", GLU_TESS_EDGE_FLAG);
    comp.AddConstant("GLU_TESS_COMBINE", GLU_TESS_COMBINE);
    comp.AddConstant("GLU_TESS_BEGIN_DATA", GLU_TESS_BEGIN_DATA);
    comp.AddConstant("GLU_TESS_VERTEX_DATA", GLU_TESS_VERTEX_DATA);
    comp.AddConstant("GLU_TESS_END_DATA", GLU_TESS_END_DATA);
    comp.AddConstant("GLU_TESS_ERROR_DATA", GLU_TESS_ERROR_DATA);
    comp.AddConstant("GLU_TESS_EDGE_FLAG_DATA", GLU_TESS_EDGE_FLAG_DATA);
    comp.AddConstant("GLU_TESS_COMBINE_DATA", GLU_TESS_COMBINE_DATA);
    comp.AddConstant("GLU_TESS_ERROR1", GLU_TESS_ERROR1);
    comp.AddConstant("GLU_TESS_ERROR2", GLU_TESS_ERROR2);
    comp.AddConstant("GLU_TESS_ERROR3", GLU_TESS_ERROR3);
    comp.AddConstant("GLU_TESS_ERROR4", GLU_TESS_ERROR4);
    comp.AddConstant("GLU_TESS_ERROR5", GLU_TESS_ERROR5);
    comp.AddConstant("GLU_TESS_ERROR6", GLU_TESS_ERROR6);
    comp.AddConstant("GLU_TESS_ERROR7", GLU_TESS_ERROR7);
    comp.AddConstant("GLU_TESS_ERROR8", GLU_TESS_ERROR8);
    comp.AddConstant("GLU_TESS_MISSING_BEGIN_POLYGON", GLU_TESS_MISSING_BEGIN_POLYGON);
    comp.AddConstant("GLU_TESS_MISSING_BEGIN_CONTOUR", GLU_TESS_MISSING_BEGIN_CONTOUR);
    comp.AddConstant("GLU_TESS_MISSING_END_POLYGON", GLU_TESS_MISSING_END_POLYGON);
    comp.AddConstant("GLU_TESS_MISSING_END_CONTOUR", GLU_TESS_MISSING_END_CONTOUR);
    comp.AddConstant("GLU_TESS_COORD_TOO_LARGE", GLU_TESS_COORD_TOO_LARGE);
    comp.AddConstant("GLU_TESS_NEED_COMBINE_CALLBACK", GLU_TESS_NEED_COMBINE_CALLBACK);
    comp.AddConstant("GLU_AUTO_LOAD_MATRIX", GLU_AUTO_LOAD_MATRIX);
    comp.AddConstant("GLU_CULLING", GLU_CULLING);
    comp.AddConstant("GLU_SAMPLING_TOLERANCE", GLU_SAMPLING_TOLERANCE);
    comp.AddConstant("GLU_DISPLAY_MODE", GLU_DISPLAY_MODE);
    comp.AddConstant("GLU_PARAMETRIC_TOLERANCE", GLU_PARAMETRIC_TOLERANCE);
    comp.AddConstant("GLU_SAMPLING_METHOD", GLU_SAMPLING_METHOD);
    comp.AddConstant("GLU_U_STEP", GLU_U_STEP);
    comp.AddConstant("GLU_V_STEP", GLU_V_STEP);
    comp.AddConstant("GLU_PATH_LENGTH", GLU_PATH_LENGTH);
    comp.AddConstant("GLU_PARAMETRIC_ERROR", GLU_PARAMETRIC_ERROR);
    comp.AddConstant("GLU_DOMAIN_DISTANCE", GLU_DOMAIN_DISTANCE);
    comp.AddConstant("GLU_MAP1_TRIM_2", GLU_MAP1_TRIM_2);
    comp.AddConstant("GLU_MAP1_TRIM_3", GLU_MAP1_TRIM_3);
    comp.AddConstant("GLU_OUTLINE_POLYGON", GLU_OUTLINE_POLYGON);
    comp.AddConstant("GLU_OUTLINE_PATCH", GLU_OUTLINE_PATCH);
    comp.AddConstant("GLU_NURBS_ERROR1", GLU_NURBS_ERROR1);
    comp.AddConstant("GLU_NURBS_ERROR2", GLU_NURBS_ERROR2);
    comp.AddConstant("GLU_NURBS_ERROR3", GLU_NURBS_ERROR3);
    comp.AddConstant("GLU_NURBS_ERROR4", GLU_NURBS_ERROR4);
    comp.AddConstant("GLU_NURBS_ERROR5", GLU_NURBS_ERROR5);
    comp.AddConstant("GLU_NURBS_ERROR6", GLU_NURBS_ERROR6);
    comp.AddConstant("GLU_NURBS_ERROR7", GLU_NURBS_ERROR7);
    comp.AddConstant("GLU_NURBS_ERROR8", GLU_NURBS_ERROR8);
    comp.AddConstant("GLU_NURBS_ERROR9", GLU_NURBS_ERROR9);
    comp.AddConstant("GLU_NURBS_ERROR10", GLU_NURBS_ERROR10);
    comp.AddConstant("GLU_NURBS_ERROR11", GLU_NURBS_ERROR11);
    comp.AddConstant("GLU_NURBS_ERROR12", GLU_NURBS_ERROR12);
    comp.AddConstant("GLU_NURBS_ERROR13", GLU_NURBS_ERROR13);
    comp.AddConstant("GLU_NURBS_ERROR14", GLU_NURBS_ERROR14);
    comp.AddConstant("GLU_NURBS_ERROR15", GLU_NURBS_ERROR15);
    comp.AddConstant("GLU_NURBS_ERROR16", GLU_NURBS_ERROR16);
    comp.AddConstant("GLU_NURBS_ERROR17", GLU_NURBS_ERROR17);
    comp.AddConstant("GLU_NURBS_ERROR18", GLU_NURBS_ERROR18);
    comp.AddConstant("GLU_NURBS_ERROR19", GLU_NURBS_ERROR19);
    comp.AddConstant("GLU_NURBS_ERROR20", GLU_NURBS_ERROR20);
    comp.AddConstant("GLU_NURBS_ERROR21", GLU_NURBS_ERROR21);
    comp.AddConstant("GLU_NURBS_ERROR22", GLU_NURBS_ERROR22);
    comp.AddConstant("GLU_NURBS_ERROR23", GLU_NURBS_ERROR23);
    comp.AddConstant("GLU_NURBS_ERROR24", GLU_NURBS_ERROR24);
    comp.AddConstant("GLU_NURBS_ERROR25", GLU_NURBS_ERROR25);
    comp.AddConstant("GLU_NURBS_ERROR26", GLU_NURBS_ERROR26);
    comp.AddConstant("GLU_NURBS_ERROR27", GLU_NURBS_ERROR27);
    comp.AddConstant("GLU_NURBS_ERROR28", GLU_NURBS_ERROR28);
    comp.AddConstant("GLU_NURBS_ERROR29", GLU_NURBS_ERROR29);
    comp.AddConstant("GLU_NURBS_ERROR30", GLU_NURBS_ERROR30);
    comp.AddConstant("GLU_NURBS_ERROR31", GLU_NURBS_ERROR31);
    comp.AddConstant("GLU_NURBS_ERROR32", GLU_NURBS_ERROR32);
    comp.AddConstant("GLU_NURBS_ERROR33", GLU_NURBS_ERROR33);
    comp.AddConstant("GLU_NURBS_ERROR34", GLU_NURBS_ERROR34);
    comp.AddConstant("GLU_NURBS_ERROR35", GLU_NURBS_ERROR35);
    comp.AddConstant("GLU_NURBS_ERROR36", GLU_NURBS_ERROR36);
    comp.AddConstant("GLU_NURBS_ERROR37", GLU_NURBS_ERROR37);
    comp.AddConstant("GLU_CW", GLU_CW);
    comp.AddConstant("GLU_CCW", GLU_CCW);
    comp.AddConstant("GLU_INTERIOR", GLU_INTERIOR);
    comp.AddConstant("GLU_EXTERIOR", GLU_EXTERIOR);
    comp.AddConstant("GLU_UNKNOWN", GLU_UNKNOWN);
    comp.AddConstant("GLU_BEGIN", GLU_BEGIN);
    comp.AddConstant("GLU_VERTEX", GLU_VERTEX);
    comp.AddConstant("GLU_END", GLU_END);
    comp.AddConstant("GLU_ERROR", GLU_ERROR);
    comp.AddConstant("GLU_EDGE_FLAG", GLU_EDGE_FLAG);

    // Register functions

    comp.AddFunction ("gluOrtho2D", WrapgluOrtho2D, compParamTypeList () << VTP_REAL << VTP_REAL << VTP_REAL << VTP_REAL, true, false, VTP_INT);
    comp.AddFunction ("gluPerspective", WrapgluPerspective, compParamTypeList () << VTP_REAL << VTP_REAL << VTP_REAL << VTP_REAL, true, false, VTP_INT);
    comp.AddFunction ("gluLookAt", WrapgluLookAt, compParamTypeList () << VTP_REAL << VTP_REAL << VTP_REAL << VTP_REAL << VTP_REAL << VTP_REAL << VTP_REAL << VTP_REAL << VTP_REAL, true, false, VTP_INT);

}
