#ifndef _JoshSDLLibH

#include "tomcomp.h"
#include "tomvm.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include <GL/Glext.h>
#include <GL/corona.h>

#define BYTE  unsigned char
#define DWORD  unsigned int
#define WORD  unsigned short int
#include <SDL/SDL.h>

long TickCount();
void Sleep(long ms);

void endProgram(int code);
void keyDown(SDL_keysym* keysym);
void processEvents();
void InitGL(int width, int height);
void InitSDL(int width, int height, char title[]);
void InitJoshSDLLib(TomBasicCompiler& comp);

#endif
