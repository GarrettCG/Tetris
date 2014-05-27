#ifndef GLOBALS_H
#define GLOBALS_H
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
extern int TIMEINTERVAL;
extern bool NOTQUIT;
//surfaces
//extern SDL_Surface *Screen;
extern SDL_Surface *NOBLOCKHolder;
extern SDL_Surface *BLUEBLOCKHolder;
extern SDL_Surface *GREENBLOCKHolder;
extern SDL_Surface *PURPLEBLOCKHolder;
extern SDL_Surface *REDBLOCKHolder;
extern SDL_Surface *TEALBLOCKHolder ;
extern SDL_Surface *WHITEBLOCKHolder;
extern SDL_Surface *YELLOWBLOCKHolder;
extern SDL_Surface *BACKGROUNDHolder;

//screen size
extern const int SCREENWIDTH;
extern const int SCREENHEIGHT;
extern const int InitialX;
extern const int InitialY;
//extern const int SCREENWIDTH = 720;
//extern const int SCREENHEIGHT = 580;

//blocks
extern const int NOBLOCK;
extern const int BLUEBLOCK;
extern const int GREENBLOCK;
extern const int PURPLEBLOCK;
extern const int REDBLOCK;
extern const int TEALBLOCK;
extern const int WHITEBLOCK;
extern const int YELLOWBLOCK;
extern const int BACKGROUND;
extern const int TEMP;

//events
//extern SDL_Event event;

//rotations
extern int Rotation;

//row for line check
extern int row;
#endif
