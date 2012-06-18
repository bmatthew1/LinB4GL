//Josh SDL library copyright Josh koert (darkjester) 2012

#include "JoshSDLLib.h"
#include "iostream"

using namespace std;

void endProgram(int code) {SDL_Quit();	exit(code);}

void WrapTickCount (TomVM& vm) {
    vm.Reg ().IntVal () = SDL_GetTicks();
}

void WrapSleep(TomVM &vm){
    int msec = vm.GetIntParam (1);
    if (msec > 5000)
        msec = 5000;
    if (msec > 0)
        SDL_Delay(msec);
}

// Process keypresses
void keyDown(SDL_keysym* keysym) {
	switch(keysym->sym) {
		case SDLK_ESCAPE:
			endProgram(0);
			break;
	}
}

// Process events
void processEvents() {
	SDL_Event event;
	while(SDL_PollEvent(&event)) {
		switch(event.type) {
			case SDL_KEYDOWN:	keyDown(&event.key.keysym);	break;
			case SDL_QUIT: endProgram(0);	break;
		}
	}
}

// Set initial perspective
void InitGL(int width, int height) {
	glClearColor(0, 0, 0, 0);
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glEnable(GL_DEPTH_TEST);
	gluPerspective(60.0, (float)width/height, 1.0, 1024.0);
	glMatrixMode(GL_MODELVIEW);
}

// Setup SDL window
void InitSDL(int width, int height, char title[]){
	const SDL_VideoInfo* info = NULL;
	int bpp = 0;
	if(SDL_Init(SDL_INIT_VIDEO)< 0){cout << "Video initialization failed!" << endl;	endProgram(1);}
	info = SDL_GetVideoInfo();
	if(!info) {cout << "Video query failed!" << endl; endProgram(1);}
	bpp = info->vfmt->BitsPerPixel;
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, true);
	if(SDL_SetVideoMode(width, height, bpp, SDL_OPENGL)==0) {cout << "Video mode set failed!" << endl; endProgram(1);}
	SDL_WM_SetCaption(title,"linB4GL");
}

// SwapBuffers
void WrapSwapBuffers(TomVM& vm) {
	SDL_GL_SwapBuffers();
}

void InitJoshSDLLib(TomBasicCompiler& comp) {
    compParamTypeList noParam;
    comp.AddFunction ("swapbuffers", WrapSwapBuffers, noParam, true,  false,  VTP_INT);
    comp.AddFunction ("sleep",      WrapSleep,      compParamTypeList () << VTP_INT, true,   false,   VTP_INT, true);
    comp.AddFunction ("tickcount",  WrapTickCount,  noParam, true,   true,    VTP_INT);
}


