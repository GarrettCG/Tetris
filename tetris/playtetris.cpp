#include "playtetris.h"
#include "timestepper.h"
#include "globals.h"
//event queue

void PlayTetris(PlayZone &GamePlace,Timestepper &TimeStep)
{
while (SDL_PollEvent(&event))
{
	GamePlace.EventHandler(); //handle keypress
	//refresh screen
	GamePlace.DrawScreen();
	GamePlace.PrintScreen();
	SDL_Flip(Screen);
}
		
//game logic
if (GamePlace.Tick() == 0) //if current piece collides
{
	//check for game over
	if (GamePlace.CheckLose() == 1)
	{
		NOTQUIT=false;
		return;
	}
	//check for full lines
	GamePlace.CheckLines();
	//increment time
	TimeStep.ChangeFrequency(TimeStep.GetFrequency()-TIMEINTERVAL);
}
//refresh screen
GamePlace.DrawScreen();
GamePlace.PrintScreen();
SDL_Flip(Screen);
}
void TitleScreen(PlayZone &GamePlace,Timestepper &TimeStep)
{
	while (SDL_PollEvent(&event))
	{
		GamePlace.EventHandler(); //handle keypress
		SDL_Flip(Screen);
	}
	//game logic
		
	SDL_Flip(Screen);
}
