#ifndef HIGHSCORE_H
#define HIGHSCORE_H
#include "SDL/SDL_ttf.h"
#include <iostream>
#include "gamestate.h"
#include "timestepper.h"
#include "SDL/SDL_image.h"
#include <sstream>
#include "stringinput.h"

class highscore : public GameState
{
public:
	//member data
	static highscore* Instance()
	{
		return &m_highscore;
	}
protected:
	highscore() { }
private:
	void BlitImage(int startx, int starty, SDL_Surface *source, SDL_Surface *destination);
	bool load_files();
	SDL_Surface *load_image(std::string filename);
	SDL_Surface* Screen;
	SDL_Color textColor;
	TTF_Font *font;
	SDL_Surface *background;
	StringInput *name;
	//Timestepper *TimeStep;
	SDL_Event event;

	void Init();
	void Cleanup();

	void Pause();
	void Resume();

	void HandleEvents(Engine* game);
	void Update(Engine* game);
	void Draw(Engine* game);

	static highscore m_highscore;
};

#endif
