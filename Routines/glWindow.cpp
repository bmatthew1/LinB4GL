//---------------------------------------------------------------------------
// Created 27-Sep-2003: Thomas Mulgrew (tmulgrew@slingshot.co.nz)
// Copyright (C) Thomas Mulgrew
#pragma hdrstop

#include "glWindow.h"
#include <map>
#include <math.h>
#include "misc.h"

//added this to destruct the Joystick
//#ifndef _NO_SDL
//#include "SDL_Joystick.h"
//#endif
//---------------------------------------------------------------------------

#ifndef _MSC_VER
#pragma package(smart_init)
#endif

#ifndef M_PI
#define M_PI 3.1415926535897932384626433832795
#endif

#ifndef WM_MOUSEWHEEL
#define WM_MOUSEWHEEL                   0x020A
#endif
#ifndef WHEEL_DELTA
#define WHEEL_DELTA                     120
#endif


////////////////////////////////////////////////////////////////////////////////
// Multitexturing

PFNGLMULTITEXCOORD2FARBPROC glMultiTexCoord2f	= NULL;
PFNGLMULTITEXCOORD2DARBPROC glMultiTexCoord2d	= NULL;
PFNGLACTIVETEXTUREARBPROC	glActiveTexture		= NULL;

////////////////////////////////////////////////////////////////////////////////
// glWindow

std::map<HWND, glWindow*> glWindows;                      // glWindow index. Used by window procedure

LRESULT CALLBACK WndProc(   HWND	hWnd,		    // Handle For This Window
							UINT	uMsg,			// Message For This Window
							WPARAM	wParam,			// Additional Message Information
							LPARAM	lParam);		// Additional Message Information

glWindow::glWindow (bool fullScreen,
                    bool border,
                    int width,
                    int height,
                    int bpp,
                    bool stencil,
                    std::string title,
                    bool allowResizing,
                    bool fitToWorkArea,
                    ResetGLModeType resetGLMode) {

    m_resetGLMode   = resetGLMode;

    // Null default values
    // If constructor is aborted, then destructor wont try to deallocate garbage handles.
    m_HDC       = 0;
    m_HGLRC     = 0;
    m_HWnd      = 0;
    m_HInstance = 0;
    m_active    = false;
    m_focused   = false;
    m_visible   = false;
    m_closing   = false;
    m_bufStart  = 0;
    m_bufEnd    = 0;
    m_scanBufStart  = 0;
    m_scanBufEnd    = 0;
    m_showingCursor = true;

    // Clear key buffers
    ClearKeyBuffers ();

    // Defaults
    m_fov               = 60;
    m_nearClip          = 1;
    m_farClip           = 1000;
    m_painting          = false;
    m_dontPaint         = false;
    m_pausePressed      = false;
    m_mouseX            = 0;
    m_mouseY            = 0;
    m_mouseButton [0]   = 0;
    m_mouseButton [1]   = 0;
    m_mouseButton [2]   = 0;
    m_mouseWheel        = 0;
    m_mouseWheelDelta   = 0;
    m_mouseCentred      = false;

   	m_HInstance		    = GetModuleHandle(NULL);				// Grab An Instance For Our Window

    // Create open GL window.
    // Note:    Caller should check error state after construction. If error set,
    //          then the window is probably unusable
	WNDCLASS	wc;						// Windows Class Structure
	wc.style			= CS_HREDRAW | CS_VREDRAW | CS_OWNDC;	// Redraw On Size, And Own DC For Window.
	wc.lpfnWndProc		= (WNDPROC) ::WndProc;					// WndProc Handles Messages
	wc.cbClsExtra		= 0;									// No Extra Window Data
	wc.cbWndExtra		= 0;									// No Extra Window Data
	wc.hInstance		= m_HInstance;							// Set The Instance
	wc.hIcon			= LoadIcon(NULL, IDI_WINLOGO);			// Load The Default Icon
	wc.hCursor			= LoadCursor(NULL, IDC_ARROW);			// Load The Arrow Pointer
	wc.hbrBackground	= NULL;									// No Background Required For GL
	wc.lpszMenuName		= NULL;									// We Don't Want A Menu
	wc.lpszClassName	= "gbOpenGL";   						// Set The Class Name

	if (!RegisterClass(&wc))									// Attempt To Register The Window Class
	{
		SetError ("Window class registration failed");
        return;
	}

    RecreateWindow (fullScreen, border, width, height, bpp, stencil, title, allowResizing, fitToWorkArea);
}

glWindow::~glWindow () {
    Hide ();

    // Destroy window contexts, handles e.t.c
    KillWindow ();
/*    if (m_HGLRC)
	{
		wglMakeCurrent(NULL,NULL);
		wglDeleteContext(m_HGLRC);
	}

	if (m_HDC)
        ReleaseDC(m_HWnd,m_HDC);

	if (m_HWnd)
        DestroyWindow(m_HWnd);*/

	UnregisterClass("gbOpenGL",m_HInstance);

	//added to Destruct the Joystick
//#ifndef _NO_SDL
//	Free_Joystick();
//#endif
}

bool glWindow::Show () {

    if (m_visible)
        return true;

    // Attempt to set fullscreen mode
    bool result = true;

    if (m_fullScreen) {
        result = ChangeDisplaySettings(&m_screenSettings,CDS_FULLSCREEN)==DISP_CHANGE_SUCCESSFUL;
        if (result)
            DoHideCursor ();
    }
    if (result) {
      	ShowWindow(m_HWnd,SW_RESTORE);	    			    // Show the window
        SetForegroundWindow(m_HWnd);						// Slightly Higher Priority
        SetFocus(m_HWnd);									// Sets Keyboard Focus To The Window
        m_visible = true;
    }
    return result;
}

void glWindow::Activate () {
    if (!m_visible)
        Show ();
    else {
        SetForegroundWindow(m_HWnd);						// Slightly Higher Priority
        SetFocus(m_HWnd);									// Sets Keyboard Focus To The Window
    }
}

void glWindow::Hide () {
    DoShowCursor ();
    if (!m_visible)
        return;
  	ShowWindow(m_HWnd,SW_HIDE); 		    			    // Hide the window
    ProcessWindowsMessages ();
    m_visible = false;
   	if (m_fullScreen)									// Are We In Fullscreen Mode?
		ChangeDisplaySettings(NULL,0);					// If So Switch Back To The Desktop
}

void glWindow::ResizeGLScene (int width, int height) {

    // Sanity checks
    if (height < 10)
        height = 10;
    if (width < 10)
        width = 10;

    m_width = width;
    m_height = height;

	if (height==0)										// Prevent A Divide By Zero By
	{
		height=1;										// Making Height Equal One
	}

	// Calculate the field of view on the XZ plane
	m_fovX = (180 / M_PI) * 2 * atan (((double) width / height) * tan (m_fov / 2 * (M_PI / 180)));

/*    m_width = width;
    m_height = height;
	glViewport(0,0,m_width,m_height);  					// Reset The Current Viewport
	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix

	// Calculate The Aspect Ratio Of The Window
	gluPerspective(m_fov,(GLfloat)m_width/(GLfloat)m_height, m_nearClip, m_farClip);

	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glLoadIdentity();									// Reset The Modelview Matrix*/
}

void ClearGLMatrix () {

    // Clear the matrix stack by popping a lot of matrices
    for (int i = 0; i < 256; i++)
        glPopMatrix ();

    // Reset the matrix itself
    glLoadIdentity ();
}

bool glWindow::ResetGL () {

    if (m_resetGLMode == RGM_RECREATEWINDOW) {
        RecreateWindow (m_fullScreen, m_border, m_width, m_height, m_bpp, m_stencil, m_title, m_allowResizing, m_fitToWorkArea);
        return true;
    }
    else if (m_resetGLMode == RGM_RECREATECONTEXT) {
        RecreateGLContext ();
        return true;
    }

    // Setup OpenGL defaults.
    // This should reset as much as possible back to the initial state of OpenGL.

    // Exceptions:
    //      * Projection matrix is initialised to a perspective transform

    // End current gl block
    try { glEnd ();                                                             } catch (...) { ; }    
    m_dontPaint = false;

    // Intialise matrices
    try { glMatrixMode (GL_PROJECTION);   ClearGLMatrix ();                     } catch (...) { ; }
    try { glMatrixMode (GL_TEXTURE);      ClearGLMatrix ();                     } catch (...) { ; }
    try { glMatrixMode (GL_MODELVIEW);    ClearGLMatrix ();                     } catch (...) { ; }

    // Initialise state
    int i;
    try { glColor4f (1, 1, 1, 1);                                               } catch (...) { ; }
    try { glIndexi (1);                                                         } catch (...) { ; }
    try { glTexCoord4f (0, 0, 0, 1);                                            } catch (...) { ; }
    try { glNormal3f (0, 0, 1);                                                 } catch (...) { ; }
//    try { glRasterPos4f (0, 0, 0, 1);                                           } catch (...) { ; }
    try { glEdgeFlag (GL_TRUE);                                                 } catch (...) { ; }
    try { glDisable (GL_VERTEX_ARRAY);                                          } catch (...) { ; }
    try { glDisable (GL_NORMAL_ARRAY);                                          } catch (...) { ; }
    try { glDisable (GL_COLOR_ARRAY);                                           } catch (...) { ; }
    try { glDisable (GL_INDEX_ARRAY);                                           } catch (...) { ; }
    try { glDisable (GL_TEXTURE_COORD_ARRAY);                                   } catch (...) { ; }
    try { glDisable (GL_EDGE_FLAG_ARRAY);                                       } catch (...) { ; }
    try { glDepthRange (0, 1);                                                  } catch (...) { ; }
    try { glDisable (GL_NORMALIZE);                                             } catch (...) { ; }
    for (i = 0; i < GL_MAX_CLIP_PLANES; i++)
        try { glDisable (GL_CLIP_PLANE0 + i);                                   } catch (...) { ; }
    GLfloat fog[] = {0, 0, 0, 0};
    try { glFogfv (GL_FOG_COLOR, fog);                                          } catch (...) { ; }
    try { glFogi (GL_FOG_INDEX, 0);                                             } catch (...) { ; }
    try { glFogf (GL_FOG_DENSITY, 1.0);                                         } catch (...) { ; }
    try { glFogf (GL_FOG_START, 0.0);                                           } catch (...) { ; }
    try { glFogf (GL_FOG_END, 1.0);                                             } catch (...) { ; }
    try { glFogi (GL_FOG_MODE, GL_EXP);                                         } catch (...) { ; }
    try { glDisable (GL_FOG);                                                   } catch (...) { ; }
    try { glShadeModel (GL_SMOOTH);                                             } catch (...) { ; }
    try { glDisable (GL_LIGHTING);                                              } catch (...) { ; }
    try { glDisable (GL_COLOR_MATERIAL);                                        } catch (...) { ; }
    try { glColorMaterial (GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);          } catch (...) { ; }

    GLfloat ambient[]   = { 0.2, 0.2, 0.2, 1.0 },
            diffuse[]   = { 0.8, 0.8, 0.8, 1.0 },
            specular[]  = { 0.0, 0.0, 0.0, 1.0 },
            emission[]  = { 0.0, 0.0, 0.0, 1.0 },
            shininess[] = { 0.0 };
    try { glMaterialfv (GL_FRONT_AND_BACK, GL_AMBIENT,    ambient);             } catch (...) { ; }
    try { glMaterialfv (GL_FRONT_AND_BACK, GL_DIFFUSE,    diffuse);             } catch (...) { ; }
    try { glMaterialfv (GL_FRONT_AND_BACK, GL_SPECULAR,  specular);             } catch (...) { ; }
    try { glMaterialfv (GL_FRONT_AND_BACK, GL_EMISSION,   emission);            } catch (...) { ; }
    try { glMaterialfv (GL_FRONT_AND_BACK, GL_SHININESS,  shininess);           } catch (...) { ; }
    try { glLightModelfv (GL_LIGHT_MODEL_AMBIENT, ambient);                     } catch (...) { ; }
    try { glLightModeli (GL_LIGHT_MODEL_LOCAL_VIEWER, GL_FALSE);                } catch (...) { ; }
    try { glLightModeli (GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);                    } catch (...) { ; }
    GLfloat lambient[]      = { 0.0, 0.0, 0.0, 1.0 },
            ldiffuse0[]     = { 1.0, 1.0, 1.0, 1.0 },
            ldiffuse1[]     = { 0.0, 0.0, 0.0, 1.0 },
            lspecular0[]    = { 1.0, 1.0, 1.0, 1.0 },
            lspecular1[]    = { 0.0, 0.0, 0.0, 1.0 },
            lposition[]     = { 0.0, 0.0, 1.0, 0.0 };
    for (i = 0; i < 8; i++) {
        try { glLightfv (GL_LIGHT0 + i, GL_AMBIENT, lambient);                              } catch (...) { ; }
        try { glLightfv (GL_LIGHT0 + i, GL_DIFFUSE, i == 0 ? ldiffuse0 : ldiffuse1);        } catch (...) { ; }
        try { glLightfv (GL_LIGHT0 + i, GL_SPECULAR, i == 0 ? lspecular0 : lspecular1);     } catch (...) { ; }
        try { glLightfv (GL_LIGHT0 + i, GL_POSITION, lposition);                            } catch (...) { ; }
        try { glLightf (GL_LIGHT0 + i, GL_SPOT_EXPONENT, 0.0);                              } catch (...) { ; }
        try { glLightf (GL_LIGHT0 + i, GL_CONSTANT_ATTENUATION, 1.0);                       } catch (...) { ; }
        try { glLightf (GL_LIGHT0 + i, GL_LINEAR_ATTENUATION, 0.0);                         } catch (...) { ; }
        try { glLightf (GL_LIGHT0 + i, GL_QUADRATIC_ATTENUATION, 0.0);                      } catch (...) { ; }
        try { glDisable (GL_LIGHT0 + i);                                                    } catch (...) { ; }
    }

    try { glPointSize (1.0);                                                    } catch (...) { ; }
    try { glDisable (GL_POINT_SMOOTH);                                          } catch (...) { ; }
    try { glLineWidth (1.0);                                                    } catch (...) { ; }
    try { glDisable (GL_LINE_SMOOTH);                                           } catch (...) { ; }
    try { glLineStipple (1, 0xffff);                                            } catch (...) { ; }
    try { glDisable (GL_LINE_STIPPLE);                                          } catch (...) { ; }
    try { glDisable (GL_CULL_FACE);                                             } catch (...) { ; }
    try { glCullFace (GL_BACK);                                                 } catch (...) { ; }
    try { glFrontFace (GL_CCW);                                                 } catch (...) { ; }
    try { glDisable (GL_POLYGON_SMOOTH);                                        } catch (...) { ; }
    try { glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);                           } catch (...) { ; }
    try { glDisable (GL_TEXTURE_1D);                                            } catch (...) { ; }
    try { glDisable (GL_TEXTURE_2D);                                            } catch (...) { ; }

    try { glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST); } catch (...) { ; }
    try { glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);                } catch (...) { ; }
    try { glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);                    } catch (...) { ; }
    try { glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);                    } catch (...) { ; }
    GLfloat texBorder[] = {0, 0, 0, 0};
    try { glTexParameterfv (GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, texBorder);             } catch (...) { ; }
    try { glDisable (GL_TEXTURE_GEN_T);                                                     } catch (...) { ; }
    try { glDisable (GL_TEXTURE_GEN_S);                                                     } catch (...) { ; }
    try { glDisable (GL_TEXTURE_GEN_R);                                                     } catch (...) { ; }
    try { glDisable (GL_TEXTURE_GEN_Q);                                                     } catch (...) { ; }
    for (i = 0; i < 4; i++) {
        GLenum coord;
        switch (i) {
        case 0: coord = GL_T; break;
        case 1: coord = GL_S; break;
        case 2: coord = GL_R; break;
        case 3: coord = GL_Q; break;
        }
        try { glTexGeni (coord, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR);            } catch (...) { ; }
    }

    try { glDisable (GL_SCISSOR_TEST);                                          } catch (...) { ; }
    try { glDisable (GL_ALPHA_TEST);                                            } catch (...) { ; }
    try { glAlphaFunc (GL_ALWAYS, 0);                                           } catch (...) { ; }
    try { glDisable (GL_STENCIL_TEST);                                          } catch (...) { ; }
    try { glStencilFunc (GL_ALWAYS, 0, 0xffffffff);                             } catch (...) { ; }
    try { glStencilOp (GL_KEEP, GL_KEEP, GL_KEEP);                              } catch (...) { ; }
    try { glDisable (GL_DEPTH_TEST);                                            } catch (...) { ; }
    try { glDepthFunc (GL_LESS);                                                } catch (...) { ; }
    try { glDisable (GL_BLEND);                                                 } catch (...) { ; }
    try { glBlendFunc (GL_ONE, GL_ZERO);                                        } catch (...) { ; }
    try { glDrawBuffer (GL_BACK);                                               } catch (...) { ; }
    try { glColorMask (GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);                     } catch (...) { ; }
    try { glDepthMask (GL_TRUE);                                                } catch (...) { ; }
    try { glClearAccum (0, 0, 0, 0);                                            } catch (...) { ; }
    try { glClearColor (0, 0, 0, 0);                                            } catch (...) { ; }
    try { glClearDepth (1);                                                     } catch (...) { ; }
    try { glClearIndex (0);                                                     } catch (...) { ; }
    try { glClearStencil (0);                                                   } catch (...) { ; }

    try { glPixelStorei (GL_PACK_SWAP_BYTES, GL_FALSE);                         } catch (...) { ; }
    try { glPixelStorei (GL_PACK_LSB_FIRST, GL_FALSE);                          } catch (...) { ; }
    try { glPixelStoref (GL_PACK_ROW_LENGTH, 0);                                } catch (...) { ; }
    try { glPixelStoref (GL_PACK_SKIP_PIXELS, 0);                               } catch (...) { ; }
    try { glPixelStorei (GL_PACK_ALIGNMENT, 4);                                 } catch (...) { ; }
    try { glPixelStorei (GL_UNPACK_SWAP_BYTES, GL_FALSE);                       } catch (...) { ; }
    try { glPixelStorei (GL_UNPACK_LSB_FIRST, GL_FALSE);                        } catch (...) { ; }
    try { glPixelStoref (GL_UNPACK_ROW_LENGTH, 0);                              } catch (...) { ; }
    try { glPixelStoref (GL_UNPACK_SKIP_PIXELS, 0);                             } catch (...) { ; }
    try { glPixelStorei (GL_UNPACK_ALIGNMENT, 4);                               } catch (...) { ; }
    try { glPixelTransferi (GL_MAP_COLOR, GL_FALSE);                            } catch (...) { ; }
    try { glPixelTransferi (GL_MAP_STENCIL, GL_FALSE);                          } catch (...) { ; }
    try { glPixelTransferi (GL_INDEX_SHIFT, 0);                                 } catch (...) { ; }
    try { glPixelTransferi (GL_INDEX_OFFSET, 0);                                } catch (...) { ; }
    try { glPixelTransferf (GL_RED_SCALE, 1.0);                                 } catch (...) { ; }
    try { glPixelTransferf (GL_GREEN_SCALE, 1.0);                               } catch (...) { ; }
    try { glPixelTransferf (GL_BLUE_SCALE, 1.0);                                } catch (...) { ; }
    try { glPixelTransferf (GL_ALPHA_SCALE, 1.0);                               } catch (...) { ; }
    try { glPixelTransferf (GL_DEPTH_SCALE, 1.0);                               } catch (...) { ; }
    try { glPixelTransferf (GL_RED_BIAS, 0.0);                                  } catch (...) { ; }
    try { glPixelTransferf (GL_GREEN_BIAS, 0.0);                                } catch (...) { ; }
    try { glPixelTransferf (GL_BLUE_BIAS, 0.0);                                 } catch (...) { ; }
    try { glPixelTransferf (GL_ALPHA_BIAS, 0.0);                                } catch (...) { ; }
    try { glPixelTransferf (GL_DEPTH_BIAS, 0.0);                                } catch (...) { ; }

    try { glHint (GL_PERSPECTIVE_CORRECTION_HINT, GL_DONT_CARE);                } catch (...) { ; }
    try { glHint (GL_POINT_SMOOTH_HINT, GL_DONT_CARE);                          } catch (...) { ; }
    try { glHint (GL_LINE_SMOOTH_HINT, GL_DONT_CARE);                           } catch (...) { ; }
    try { glHint (GL_POLYGON_SMOOTH_HINT, GL_DONT_CARE);                        } catch (...) { ; }
    try { glHint (GL_FOG_HINT, GL_DONT_CARE);                                   } catch (...) { ; }

    // Multitexturing
    if (ExtensionSupported ("GL_ARB_multitexture")) {

        // Disable texturing for all texture units
        int units;
        try { glGetIntegerv (GL_MAX_TEXTURE_UNITS_ARB, &units);                 } catch (...) { ; }
        for (int i = 0; i < units; i++) {
            if (glActiveTexture != NULL)
                glActiveTexture (GL_TEXTURE0_ARB + i);
            try { glDisable (GL_TEXTURE_2D);                                    } catch (...) { ; }
            try { glDisable (GL_TEXTURE_1D);                                    } catch (...) { ; }
            if (i == 0) try { glTexEnvi (GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); } catch (...) { ; }
            else        try { glTexEnvi (GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_BLEND);    } catch (...) { ; }
        }

        if (glActiveTexture != NULL)
            try { glActiveTexture (GL_TEXTURE0_ARB);                            } catch (...) { ; }
    }

    // Setup OpenGL defaults
    OpenGLDefaults ();

	return TRUE;									// Initialization Went OK
}

LRESULT CALLBACK WndProc(   HWND	hWnd,		    // Handle For This Window
							UINT	uMsg,			// Message For This Window
							WPARAM	wParam,			// Additional Message Information
							LPARAM	lParam)	{		// Additional Message Information

    // Find window object
    glWindow* win = glWindows [hWnd];

    // Pass call to window object
    if (win != NULL)
        return win->WndProc (hWnd, uMsg, wParam, lParam);
    else
    	return DefWindowProc(hWnd,uMsg,wParam,lParam);   // No window object found. Use default handler.

}

void glWindow::OpenGLDefaults () {

    // Setup some 'nice' defaults
    ResizeGLScene (m_width, m_height);                  // Projection matrix

    // Setup a default viewport
	glViewport(0,0,m_width,m_height);  					// Reset The Current Viewport

    // Set some default OpenGL matrices. Basic 3D perspective projection
	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix
	gluPerspective(m_fov,(GLfloat)m_width/(GLfloat)m_height, m_nearClip, m_farClip);

	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glLoadIdentity();									// Reset The Modelview Matrix
	try { glShadeModel(GL_SMOOTH);												} catch (...) { ; }
	try { glClearColor(0.0f, 0.0f, 0.0f, 0.5f);									} catch (...) { ; }
	try { glClearDepth(1.0f);													} catch (...) { ; }
    try { glEnable (GL_DEPTH_TEST);                                             } catch (...) { ; }
    try { glDepthFunc (GL_LEQUAL);                                              } catch (...) { ; }
    try { glHint (GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);                   } catch (...) { ; }
	try { glDisable (GL_TEXTURE_2D);											} catch (...) { ; }

    glClear (GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    SwapBuffers ();
    glClear (GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
}

void glWindow::BufferScanKey (unsigned char key) {
    int end = m_scanBufEnd;
    IncScanEnd ();
    if (m_scanBufEnd != m_scanBufStart)
        m_scanKeyBuffer [end] = key;
    else
        m_scanBufEnd = end;
}

LRESULT CALLBACK glWindow::WndProc( HWND    hWnd,
                                    UINT    uMsg,
                                    WPARAM  wParam,
                                    LPARAM  lParam) {
	switch (uMsg)									// Check For Windows Messages
	{
		case WM_ACTIVATE:							// Watch For Window Activate Message
		{
			if (!HIWORD(wParam))				    // Check minimized state
			{
				m_active=TRUE;	 				    // Program Is Active
			}
			else
			{
				m_active=FALSE; 				    // Program Is No Longer Active
			}
            m_focused = LOWORD(wParam);
            if (!m_focused) {
                m_mouseCentred = false;
                if (!m_fullScreen)
                    DoShowCursor ();
            }
			return 0;								// Return To The Message Loop
		}

		case WM_SYSCOMMAND:							// Intercept System Commands
		{
			switch (wParam)							// Check System Calls
			{
				case SC_SCREENSAVE:					// Screensaver Trying To Start?
				case SC_MONITORPOWER:				// Monitor Trying To Enter Powersave?
				return 0;							// Prevent From Happening
			}
			break;									// Exit
		}

		case WM_CLOSE:								// Did We Receive A Close Message?
		{
            m_closing = true;
            BufferScanKey (VK_ESCAPE);				// Generate an escape keypress
            return 0;
        }

		case WM_SIZE:								// Resize The OpenGL Window
		{
			ResizeGLScene(LOWORD(lParam),HIWORD(lParam));  // LoWord=Width, HiWord=Height
			return 0;								// Jump Back
		}

        case WM_KEYDOWN:
        {
            if (wParam == VK_PAUSE)
                m_pausePressed = true;
            else {
                m_keyDown [wParam & 0xff] |= 1;
                BufferScanKey (wParam & 0xff);
            }
            return 0;
        }

        case WM_KEYUP:
        {
            m_keyDown [wParam & 0xff] &= ~1;
            return 0;
        }

        case WM_CHAR:
        {
            if (wParam == 27)               // Esc closes window
                m_closing = true;

            int end = m_bufEnd;
            IncEnd ();                    // Check for room in buffer
            if (m_bufEnd != m_bufStart)
                m_keyBuffer [end] = wParam;
            else
                m_bufEnd = end;           // No room. Restore buffer pointers
            return 0;
        }
		case WM_PAINT:
		{
            if (!m_painting && !FullScreen () && !m_dontPaint) {
                m_painting = true;
                SwapBuffers ();
                m_painting = false;
            }
            break;
        }
        case WM_MOUSEMOVE:
        {
            m_mouseX = lParam & 0xffff;
            m_mouseY = lParam >> 16;
            break;
        }
        case WM_LBUTTONDOWN:    m_mouseButton [0] = true;   break;
        case WM_LBUTTONUP:      m_mouseButton [0] = false;  break;
        case WM_RBUTTONDOWN:    m_mouseButton [1] = true;   break;
        case WM_RBUTTONUP:      m_mouseButton [1] = false;  break;
        case WM_MBUTTONDOWN:    m_mouseButton [2] = true;   break;
        case WM_MBUTTONUP:      m_mouseButton [2] = false;  break;
        case WM_MOUSEWHEEL: {
            m_mouseWheelDelta += ((long)wParam) >> 16;
            while (m_mouseWheelDelta >= WHEEL_DELTA) {
                m_mouseWheelDelta -= WHEEL_DELTA;
                m_mouseWheel++;
            }
            while (m_mouseWheelDelta < 0) {
                m_mouseWheelDelta += WHEEL_DELTA;
                m_mouseWheel--;
            }
            break;
        }
	}

	// Pass All Unhandled Messages To DefWindowProc
	return DefWindowProc(hWnd,uMsg,wParam,lParam);
}

bool glWindow::ProcessWindowsMessages () {
	MSG		msg;								// Windows Message Structure
	while 	(PeekMessage (&msg, NULL, 0, 0, PM_REMOVE)) {
		if (msg.message==WM_QUIT)				// Have We Received A Quit Message?
		{
			return true;
		}
		else									// If Not, Deal With Window Messages
		{
			TranslateMessage(&msg);				// Translate The Message
			DispatchMessage(&msg);				// Dispatch The Message
		}
	}
	return false;
}

void glWindow::ClearKeyBuffers () {

    // Clear key states
    for (int i = 0; i < 256; i++)
        m_keyDown [i] = false;

    // Clear key buffer
    m_bufStart  = 0;
    m_bufEnd    = 0;
    m_scanBufStart  = 0;
    m_scanBufEnd    = 0;    
}

char glWindow::GetKey () {

    // Flush any keypress messages
    ProcessWindowsMessages ();

    // Check for buffered keypress
    if (m_bufStart == m_bufEnd)
        return 0;

    // Extract and return it
    char result = m_keyBuffer [m_bufStart];
    IncStart ();
    return result;
}

char glWindow::GetScanKey () {

    // Flush any keypress messages
    ProcessWindowsMessages ();

    // Check for buffered keypress
    if (m_scanBufStart == m_scanBufEnd)
        return 0;

    // Extract and return it
    char result = m_scanKeyBuffer [m_scanBufStart];
    IncScanStart ();
    return result;
}

void glWindow::FakeScanKey (char scanCode, char bitmask, bool down) {
    assert (bitmask != 0);

    // Fake a key press/release
    unsigned char code = (unsigned char) scanCode;
    bool wasDown = (m_keyDown [code] & bitmask) != 0;

    // Add a keypress to buffer (if necessary)
    if (down && !wasDown)
        BufferScanKey (code);

    // Toggle key bitmask
    if (down)
        m_keyDown [code] |= bitmask;
    else
        m_keyDown [code] &= ~bitmask;
}

bool glWindow::ExtensionSupported (std::string extension) {
    std::string extensions = (char *) glGetString (GL_EXTENSIONS);
    extensions = (std::string) " " + extensions + " ";
    extension = " " + extension + " ";
    return extensions.find (extension) != std::string::npos;
}

void glWindow::InitMultitexture () {
    if (ExtensionSupported ("GL_ARB_multitexture")) {
		glMultiTexCoord2f = (PFNGLMULTITEXCOORD2FARBPROC) wglGetProcAddress ("glMultiTexCoord2fARB");
		glMultiTexCoord2d = (PFNGLMULTITEXCOORD2DARBPROC) wglGetProcAddress ("glMultiTexCoord2dARB");
		glActiveTexture = (PFNGLACTIVETEXTUREARBPROC) wglGetProcAddress ("glActiveTextureARB");
    }
    else {
		glMultiTexCoord2f = NULL;
		glMultiTexCoord2d = NULL;
		glActiveTexture = NULL;
    }
}

void glWindow::PositionMouse () {
    POINT pos = { m_mouseX, m_mouseY };
    ClientToScreen (m_HWnd, &pos);
    SetCursorPos (pos.x, pos.y);
}

int glWindow::MouseXD ()  {

    // Read any pending windows messages
    ProcessWindowsMessages ();

    if (!m_focused)
        return 0;

    if (!m_mouseCentred) {
        m_mouseX = m_width / 2;
        m_mouseY = m_height / 2;
        PositionMouse ();
        m_mouseCentred = true;
        DoHideCursor ();
        return 0;
    }

    // Calculate how far mouse has moved from centre
    int centre = m_width / 2;
    int result = m_mouseX - centre;

    // Recentre cursor x
    m_mouseX = centre;
    PositionMouse ();

    // Return result
    return result;
}
int glWindow::MouseYD () {

    // Read any pending windows messages
    ProcessWindowsMessages ();

    if (!m_focused)
        return  0;

    if (!m_mouseCentred) {
        m_mouseX = m_width / 2;
        m_mouseY = m_height / 2;
        PositionMouse ();
        m_mouseCentred = true;
        DoHideCursor ();
        return 0;
    }

    // Calculate how far mouse has moved from centre
    int centre = m_height / 2;
    int result = m_mouseY - centre;

    // Recentre cursor y
    m_mouseY = centre;
    PositionMouse ();

    // Return result
    return result;
}

void glWindow::RecreateWindow (
    bool fullScreen,
    bool border,
    int width,
    int height,
    int bpp,
    bool stencil,
    std::string title,
    bool allowResizing,
    bool fitToWorkArea) {

    // Save window settings
    m_fullScreen    = fullScreen;
    m_border        = border;
    m_width         = width;
    m_height        = height;
    m_bpp           = bpp;
    m_title         = title;
    m_allowResizing = allowResizing;
    m_fitToWorkArea = fitToWorkArea;
    m_stencil       = stencil;

    // Delete existing window
    KillWindow ();

    // Create new one
	GLuint		PixelFormat;			// Holds The Results After Searching For A Match
	DWORD		dwExStyle;				// Window Extended Style
	DWORD		dwStyle;				// Window Style
	RECT		WindowRect;				// Grabs Rectangle Upper Left / Lower Right Values
	WindowRect.left     =(long)0;			// Set Left Value To 0
	WindowRect.right    =(long)m_width;		// Set Right Value To Requested Width
	WindowRect.top      =(long)0;			// Set Top Value To 0
	WindowRect.bottom   =(long)m_height;	// Set Bottom Value To Requested Height

	if (m_fullScreen)												// Attempt Fullscreen Mode?
	{
		memset(&m_screenSettings,0,sizeof(m_screenSettings));	// Makes Sure Memory's Cleared
		m_screenSettings.dmSize=sizeof(m_screenSettings);		// Size Of The Devmode Structure
		m_screenSettings.dmPelsWidth	= m_width;				// Selected Screen Width
		m_screenSettings.dmPelsHeight	= m_height;				// Selected Screen Height
		m_screenSettings.dmBitsPerPel	= m_bpp;				// Selected Bits Per Pixel
  		m_screenSettings.dmFields=DM_PELSWIDTH|DM_PELSHEIGHT;
        if (m_bpp)
            m_screenSettings.dmFields |= DM_BITSPERPEL;
	}

	if (m_fullScreen || !m_border)									// Are We Still In Fullscreen Mode?
	{
        // Borderless window
		dwExStyle=WS_EX_APPWINDOW;
		dwStyle=WS_POPUP;
	}
	else {
        // Standard window
        dwExStyle=WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;			        // Window Extended Style
        if (allowResizing)
            dwStyle = WS_OVERLAPPEDWINDOW;
        else
            dwStyle = WS_OVERLAPPEDWINDOW & ~(WS_SIZEBOX | WS_MAXIMIZEBOX);	    // Windows Style
        if (m_fitToWorkArea)
            dwStyle |= WS_MAXIMIZE;
	}

    if (!m_fullScreen && !m_fitToWorkArea) {

        // Get the screen resolution
        HWND desktop = GetDesktopWindow ();
        RECT desktopRect;
        GetWindowRect (desktop, &desktopRect);
        int xoffs, yoffs;
        if (WindowRect.right > desktopRect.right)
            xoffs = -WindowRect.left;
        else
            xoffs = (desktopRect.right  - WindowRect.right)  / 2;
        if (WindowRect.bottom > desktopRect.bottom)
            yoffs = -WindowRect.top;
        else
            yoffs = (desktopRect.bottom - WindowRect.bottom) / 2;
        WindowRect.left     += xoffs;
        WindowRect.right    += xoffs;
        WindowRect.top      += yoffs;
        WindowRect.bottom   += yoffs;

        // Adjust window size to allow for border
        if (m_border)
            AdjustWindowRectEx(&WindowRect, dwStyle, false, dwExStyle);
    }

    // Fitting to work area?
    if (m_fitToWorkArea) {
        SystemParametersInfo(SPI_GETWORKAREA, 0, &WindowRect, 0);    // Gets the desktop work area
        m_width = WindowRect.right - WindowRect.left;
        m_height = WindowRect.bottom - WindowRect.top;
    }

	// Create The Window
	if (!(m_HWnd=CreateWindowEx(	dwExStyle,				    		// Extended Style For The Window
								    "gbOpenGL",			    			// Class Name
    								m_title.c_str (),   				// Window Title
	    							dwStyle |							// Defined Window Style
		    						WS_CLIPSIBLINGS |					// Required Window Style
			    					WS_CLIPCHILDREN,					// Required Window Style
				    				WindowRect.left, WindowRect.top,	// Window Position
					    			WindowRect.right-WindowRect.left,	// Calculate Window Width
						    		WindowRect.bottom-WindowRect.top,	// Calculate Window Height
							    	NULL,								// No Parent Window
								    NULL,								// No Menu
								    m_HInstance,						// Instance
								    NULL)))								// Dont Pass Anything To WM_CREATE
	{
        SetError ("Window creation error");
        return;
	}

    // Register window (for window procedure)
    glWindows [m_HWnd] = this;

    // Stencil buffer depth
    GLint stencilBits = m_stencil ? 8 : 0;

	static	PIXELFORMATDESCRIPTOR pfd=				// pfd Tells Windows How We Want Things To Be
	{
		sizeof(PIXELFORMATDESCRIPTOR),				// Size Of This Pixel Format Descriptor
		1,											// Version Number
		PFD_DRAW_TO_WINDOW |						// Format Must Support Window
		PFD_SUPPORT_OPENGL |						// Format Must Support OpenGL
		PFD_DOUBLEBUFFER,
		PFD_TYPE_RGBA,								// Request An RGBA Format
		m_bpp,										// Select Our Color Depth
		0, 0, 0, 0, 0, 0,							// Color Bits Ignored
		0,											// No Alpha Buffer
		0,											// Shift Bit Ignored
		0,											// No Accumulation Buffer
		0, 0, 0, 0,									// Accumulation Bits Ignored
		16,											// 16Bit Z-Buffer (Depth Buffer)
		stencilBits, 								// No Stencil Buffer
		0,											// No Auxiliary Buffer
		PFD_MAIN_PLANE,								// Main Drawing Layer
		0,											// Reserved
		0, 0, 0										// Layer Masks Ignored
	};

	if (!(m_HDC=GetDC(m_HWnd)))					 	// Did We Get A Device Context?
	{
        SetError ("Failed to get window device context");
        return;
	}

	if (!(PixelFormat=ChoosePixelFormat(m_HDC,&pfd)))	// Did Windows Find A Matching Pixel Format?
	{
        SetError ("Could not find a suitable pixel format");
        return;
	}

	// Determine whether pixel format will be hardware accellerated.

	PIXELFORMATDESCRIPTOR pfd_new;
    DescribePixelFormat (m_HDC, PixelFormat, sizeof (PIXELFORMATDESCRIPTOR), &pfd_new);

	if ((pfd_new.dwFlags & PFD_GENERIC_FORMAT) != 0					// Generic
	&&  (pfd_new.dwFlags & PFD_GENERIC_ACCELERATED) == 0) {			// Non accellerated

		// Warn user that OpenGL will proceed in software mode!
		if (MessageBox(NULL, "Hardware 3D acceleration is not available for this display mode.\nProceed in software mode?","Warning",MB_YESNO|MB_ICONEXCLAMATION)==IDNO) {
			SetError ("Aborted");
            return;
		}
	}

	if(!SetPixelFormat(m_HDC,PixelFormat,&pfd))		// Are We Able To Set The Pixel Format?
	{
        SetError ("Set pixel format failed");
        return;
	}

    // Setup OpenGL
    RecreateGLContext ();
}

void glWindow::RecreateGLContext () {

    // Delete existing context
    KillGLContext ();

    // Create main context
	if (!(m_HGLRC=wglCreateContext(m_HDC)))				// Are We Able To Get A Rendering Context?
	{
        SetError ("Could not create OpenGL rendering context");
        return;
	}
	if(!wglMakeCurrent(m_HDC,m_HGLRC))					// Try To Activate The Rendering Context
	{
        SetError ("Could not activate OpenGL rendering context");
        return;
	}

    // Multitexture extension pointers may not be valid anymore, so re-fetch them
    InitMultitexture ();

    // Setup OpenGL defaults
    OpenGLDefaults ();
}

void glWindow::KillWindow () {

    // Close the window
    Hide ();

    // Must destroy OpenGL context first
    KillGLContext ();

    // Delete the window
    glWindows.erase (m_HWnd);           // Remove from window list
	if (m_HDC) {
        ReleaseDC(m_HWnd,m_HDC);
        m_HDC = 0;
    }
	if (m_HWnd) {
        DestroyWindow(m_HWnd);
        m_HWnd = 0;
    }
}

void glWindow::KillGLContext () {

    // Destroy the OpenGL context
    if (m_HGLRC)
	{
		wglMakeCurrent(NULL,NULL);
		wglDeleteContext(m_HGLRC);
        m_HGLRC = 0;
	}
}
