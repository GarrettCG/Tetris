
#ifndef ENGINE_H
#define ENGINE_H

#include "SDL/SDL.h"
#include <string>
#include <vector>
//using namespace std;

class GameState;

class Engine
{
public:

	void Init(const char* title, int width=640, int height=480, 
		      int bpp=0, bool fullscreen=false);
	void Cleanup();

	void ChangeState(GameState* state);
	void PushState(GameState* state);
	void PopState();

	void HandleEvents();
	void Update();
	void Draw();

	bool Running() { return m_running; }
	void Quit() { m_running = false; }

	SDL_Surface* screen;
	std::string tempname;
	int tempnum;
	bool george;
private:
	// the stack of states
	std::vector<GameState*> states;
	
	bool m_running;
	bool m_fullscreen;
};

#endif

