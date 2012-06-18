//---------------------------------------------------------------------------
// Created 23-Jun-2003: Thomas Mulgrew (tmulgrew@slingshot.co.nz)
// Copyright (C) Thomas Mulgrew
/*  OpenGL window class
*/

#ifndef glWindowH
#define glWindowH
//---------------------------------------------------------------------------
#include <windows.h>
#include <gl\gl.h>
#include <gl\glu.h>
#include <gl\glext.h>                           // If this line wont compile, see OpenGLHeaderFiles\Readme.txt                 
#include <string>
#include "HasErrorState.h"
#include "Misc.h"

#define GLWINDOWKEYBUFFER 16                    // X character key buffer

enum ResetGLModeType {  RGM_RESETSTATE = 0,         // Explicitly reset all the OpenGL state (quite rigourous. some drivers/OpenGL setups can't handle this.)
                        RGM_RECREATECONTEXT = 1,    // Reuse the window, but re-create the OpenGL context (some drivers don't like this)
                        RGM_RECREATEWINDOW = 2};    // Destroy and re-create the entire window.

////////////////////////////////////////////////////////////////////////////////
// Multitexturing
//

// IMPORTANT!:
// This code will not compile if you have an older version of glext.h (as included
// in some older compilers).
//
// The file is in:					...\include\gl
// You can get a replacement from:	www.opengl.org/resources/faq/technical/extensions.htm
extern PFNGLMULTITEXCOORD2FARBPROC glMultiTexCoord2f;
extern PFNGLMULTITEXCOORD2DARBPROC glMultiTexCoord2d;
extern PFNGLACTIVETEXTUREARBPROC   glActiveTexture;

////////////////////////////////////////////////////////////////////////////////
// glWindow
//
// Encapsulates a general purpose OpenGL window.

class glWindow : public HasErrorState {
    HDC			m_HDC;              // Device context
    HGLRC       m_HGLRC;            // OpenGL rendering context
    HWND		m_HWnd;             // Window handle
    HINSTANCE	m_HInstance;        // Instance handle
    bool		m_active;           // True if window is active
    bool        m_focused;          // True if window has focus
    bool        m_visible;          // True if window is visible
    bool		m_fullScreen;       // True if fullscreen mode
    bool        m_border;           // True if window has border (windowed mode only)
    bool        m_allowResizing;    // True if window can be dragged and resized
    bool        m_fitToWorkArea;    // True if window should be fitted to the desktop work area
    int         m_width, m_height;
    int         m_bpp;              // (Fullscreen mode only)
    bool        m_stencil;          // True to enable stencil buffer
    std::string m_title;            // Window title
    double      m_fov, m_fovX,
                m_nearClip, m_farClip;
    DEVMODE     m_screenSettings;	// Screen settings for fullscreen mode
    bool        m_closing;
    char        m_keyDown [256];                        // Tracks key states
    char        m_keyBuffer [GLWINDOWKEYBUFFER];        // Queues key presses
    char        m_scanKeyBuffer [GLWINDOWKEYBUFFER];    // Queuse scan keys
    int         m_bufStart, m_bufEnd, m_scanBufStart, m_scanBufEnd;
    bool        m_dontPaint;        // If false (default), WM_PAINT messages will cause a SwapBuffers () call. Otherwise they wont...
    bool        m_painting;
    bool        m_pausePressed;
    int         m_mouseX, m_mouseY;
    bool        m_mouseButton [3];  // 0 = Left, 1 = Right, 2 = Middle
    int         m_mouseWheel, m_mouseWheelDelta;
    bool        m_mouseCentred;
        // Used to detect the first time someone uses the MouseXD() or MouseYD() methods.
        // These methods work by placing the mouse cursor in the middle of the
        // window and measuring the distance it moves from that point.
        // On the first call they simply place the cursor in the centre and
        // return 0.
    bool        m_showingCursor;
    ResetGLModeType m_resetGLMode;

    void        IncStart ()     { m_bufStart        = (++m_bufStart)    % GLWINDOWKEYBUFFER; }
    void        IncEnd ()       { m_bufEnd          = (++m_bufEnd)      % GLWINDOWKEYBUFFER; }
    void        IncScanStart () { m_scanBufStart    = (++m_scanBufStart)% GLWINDOWKEYBUFFER; }
    void        IncScanEnd ()   { m_scanBufEnd      = (++m_scanBufEnd)  % GLWINDOWKEYBUFFER; }
    void        PositionMouse ();
    void        BufferScanKey (unsigned char key);

protected:
    void ResizeGLScene (int width, int height); // Resize the scene in response to a window resize
    void KillWindow ();
    void KillGLContext ();
    void DoShowCursor () {
        if (!m_showingCursor) {
            ShowCursor (true);
            m_showingCursor = true;
        }
    }
    void DoHideCursor () {
        if (m_showingCursor && (m_fullScreen || m_mouseCentred)) {
            ShowCursor (false);
            m_showingCursor = false;
        }
    }

public:
    glWindow (  bool fullScreen,
                bool border,
                int width,          // Note: If width = 0, will use screen width
                int height,
                int bpp,
                bool stencil,
                std::string title,
                bool allowResizing,
                bool fitToWorkArea,
                ResetGLModeType resetGLMode = RGM_RECREATEWINDOW);
    ~glWindow ();

    bool            ResetGL ();
    void            OpenGLDefaults ();
    bool            ProcessWindowsMessages ();
    void            RecreateWindow (bool fullScreen, bool border, int width, int height, int bpp, bool stencil, std::string title, bool allowResizing, bool fitToWorkArea);
    virtual void    RecreateGLContext ();

    // Settings
    int             Width ()        { return m_width; }
    int             Height ()       { return m_height; }
    int             Bpp ()          { return m_bpp; }
    bool            FullScreen ()   { return m_fullScreen; }
    double&         FOV ()          { return m_fov; }
    double          FOVX ()         { return m_fovX; }
    double&         NearClip ()     { return m_nearClip; }
    double&         FarClip ()      { return m_farClip; }
    std::string     Title ()        { return m_title; }
    ResetGLModeType& ResetGLMode () { return m_resetGLMode; }

    // Resources

    // (At least some of these handles are recreated when the OpenGL settings are
    // initialised. Calling code shouldn't rely on them staying constant.)
    HDC         GetHDC ()       { return m_HDC; }
    HGLRC       GetHGLRC ()     { return m_HGLRC; }
    HWND        GetHWND ()      { return m_HWnd; }
    HINSTANCE   GetHINSTANCE () { return m_HInstance; }

    // Active state
    bool        Active ()       { return m_active; }
    void        Activate ();
    bool        Focused ()      { return m_focused; }
    bool        Show ();            // Show window. Will switch to window if in fullscreen mode
    void        Hide ();            // Hide window. Switch back from fullscreen (if fullscreen mode)
    bool        Visible ()      { return m_visible; }
    bool        Closing ()      { return m_closing; }
    void        SetClosing (bool value) { m_closing = value; }


    // Keyboard handling
    char        GetKey ();          // Pulls a key from the keyboard buffer. Returns 0 if none waiting.
    char        GetScanKey ();
    void        ClearKeyBuffers ();
    bool        KeyDown (char i) {
        ProcessWindowsMessages ();
        return m_keyDown [(unsigned char) i];
    }
    void        FakeScanKey (char scanCode, char bitmask, bool down);

    // Display screen
    void        SwapBuffers ()  { ::SwapBuffers (m_HDC); }

    virtual LRESULT CALLBACK WndProc(   HWND    hWnd,
                                        UINT    uMsg,
                                        WPARAM  wParam,
                                        LPARAM  lParam);

    // Multitexturing extension
    bool ExtensionSupported (std::string extension);
    void InitMultitexture ();

    // Mouse
    int MouseX ()   { ProcessWindowsMessages (); return m_mouseX; }
    int MouseY ()   { ProcessWindowsMessages (); return m_mouseY; }
    int MouseXD ();
    int MouseYD ();
    int MouseButton (int index) {
        assert (index >= 0);
        assert (index < 3);
        ProcessWindowsMessages ();
        return m_mouseButton [index];
    }
    int MouseWheel ()   { int result = m_mouseWheel; m_mouseWheel = 0; return result; }

    // Misc
    bool DontPaint ()                   { return m_dontPaint; }
    void SetDontPaint (bool dontPaint)  { m_dontPaint = dontPaint; }
    bool PausePressed () {
        bool result = m_pausePressed;
        m_pausePressed = false;
        return result;
    }
};

#endif
