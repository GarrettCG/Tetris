#include "sdlstuff.h"
void Initialize() //start up routine
{
	//initialize sdl and submodules
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1) { std::cout << "error initializing SDL\n"; }

	//create window
	Screen = SDL_SetVideoMode(SCREENWIDTH, SCREENHEIGHT, 32, SDL_SWSURFACE);
	if (Screen == 0) { std::cout << "error creating main window\n"; }
	SDL_WM_SetCaption("GBTetrisP", 0);
}




