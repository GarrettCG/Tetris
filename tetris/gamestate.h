
#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "engine.h"

class GameState
{
public:
	virtual void Init() = 0;
	virtual void Cleanup() = 0;

	virtual void Pause() = 0;
	virtual void Resume() = 0;

	virtual void HandleEvents(Engine* game) = 0;
	virtual void Update(Engine* game) = 0;
	virtual void Draw(Engine* game) = 0;

	void ChangeState(Engine* game, GameState* state) 
	{
		game->ChangeState(state);
	}

protected:
	GameState() { }
};

#endif

