
#include <stdio.h>
#include "gamestate.h"
#include "SDL/SDL.h"
#include "engine.h"


void Engine::Init(const char* title, int width, int height, 
						 int bpp, bool fullscreen)
{
	int flags = 0;

	// initialize SDL
	SDL_Init(SDL_INIT_VIDEO);

	// set the title bar text
	SDL_WM_SetCaption(title, title);

	if ( fullscreen ) {
		flags = SDL_FULLSCREEN;
	}

	// create the screen surface
	screen = SDL_SetVideoMode(width, height, bpp, flags);

	m_fullscreen = fullscreen;
	m_running = true;

	printf("CGameEngine Init\n");
}

void Engine::Cleanup()
{
	// cleanup the all states
	while ( !states.empty() ) {
		states.back()->Cleanup();
		states.pop_back();
	}

	// switch back to windowed mode so other 
	// programs won't get accidentally resized
	if ( m_fullscreen ) {
		screen = SDL_SetVideoMode(640, 480, 0, 0);
	}

	printf("CGameEngine Cleanup\n");

	// shutdown SDL
	SDL_Quit();
}

void Engine::ChangeState(GameState* state) 
{
	// cleanup the current state
	if ( !states.empty() ) {
		states.back()->Cleanup();
		states.pop_back();
	}

	// store and init the new state
	states.push_back(state);
	states.back()->Init();
}

void Engine::PushState(GameState* state)
{
	// pause current state
	if ( !states.empty() ) {
		states.back()->Pause();
	}

	// store and init the new state
	states.push_back(state);
	states.back()->Init();
}

void Engine::PopState()
{
	// cleanup the current state
	if ( !states.empty() ) {
		states.back()->Cleanup();
		states.pop_back();
	}

	// resume previous state
	if ( !states.empty() ) {
		states.back()->Resume();
	}
}


void Engine::HandleEvents() 
{
	// let the state handle events
	states.back()->HandleEvents(this);//this apparantly calls engine
}

void Engine::Update() 
{
	// let the state update the game
	states.back()->Update(this);
}

void Engine::Draw() 
{
	// let the state draw the screen
	states.back()->Draw(this);
}
