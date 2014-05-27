#include "globals.h"

int TIMEINTERVAL=0;
bool NOTQUIT=false;
//surfaces
//SDL_Surface *Screen = 0;
SDL_Surface *NOBLOCKHolder = 0;
SDL_Surface *BLUEBLOCKHolder = 0;
SDL_Surface *GREENBLOCKHolder = 0;
SDL_Surface *PURPLEBLOCKHolder = 0;
SDL_Surface *REDBLOCKHolder = 0;
SDL_Surface *TEALBLOCKHolder = 0;
SDL_Surface *WHITEBLOCKHolder = 0;
SDL_Surface *YELLOWBLOCKHolder = 0;
SDL_Surface *BACKGROUNDHolder = 0;

//screen size
const int SCREENWIDTH = 720;
const int SCREENHEIGHT = 580;
const int InitialX=5;
const int InitialY=0;
//blocks
const int NOBLOCK = 0;
const int BLUEBLOCK = 1;
const int GREENBLOCK = 2;
const int PURPLEBLOCK = 3;
const int REDBLOCK = 4;
const int TEALBLOCK = 5;
const int WHITEBLOCK = 6;
const int YELLOWBLOCK = 7;
const int BACKGROUND = 8;
const int TEMP = 9;

//events
//SDL_Event event;

//rotations
int Rotation = 2;

//row for line check
int row;
