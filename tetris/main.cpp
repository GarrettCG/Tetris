//GB TETRIS P
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "timestepper.h"
#include "piece.h"
#include "globals.h"

#include "playzone.h"
#include "titlescreen1.h"

#include "highscore.h"

using namespace std;
int main(int argc, char *argv[])
{
	Engine Tetris;
	Tetris.Init( "GBTetrisP" );
	Tetris.ChangeState( TitleScreen1::Instance() );
	//FrameControl FrameController(60);
	while (Tetris.Running())
	{
		Tetris.HandleEvents(); 
		Tetris.Update();
		Tetris.Draw();
	//	FrameController.LimitFPS(FrameController.m_fpslimiter.GetTime());
	}
	Tetris.Cleanup();
	return 0;
}
