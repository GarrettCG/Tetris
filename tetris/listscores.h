#ifndef LISTSCORES_H
#define LISTSCORES_H
#include "SDL/SDL_ttf.h"
#include <iostream>
#include "gamestate.h"
#include "timestepper.h"
#include "SDL/SDL_image.h"
#include "scorelist.h"
#include <sstream>
#include "stringinput.h"

class listscores : public GameState
{
public:
	//member data
	static listscores* Instance()
	{
		return &m_listscores;
	}
protected:
	listscores() { }
private:
	void BlitImage(int startx, int starty, SDL_Surface *source, SDL_Surface *destination);
	bool load_files();
	SDL_Surface *LoadImage(std::string filename);
	SDL_Surface* Screen;
	SDL_Color txtColor;
	TTF_Font *font;
	SDL_Surface *background;
	SDL_Surface *message;
	SDL_Surface *message2;
	scorelist * thelist;
	//Timestepper *TimeStep;
	SDL_Event event;
	std::stringstream out;
	void Init();
	void Cleanup();

	void Pause();
	void Resume();

	void HandleEvents(Engine* game);
	void Update(Engine* game);
	void Draw(Engine* game);

	static listscores m_listscores;
};

#endif
