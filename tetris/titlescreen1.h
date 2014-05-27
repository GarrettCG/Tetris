#ifndef TITLESCREEN1_H
#define TITLESCREEN1_H
#include "SDL/SDL_ttf.h"
#include <iostream>
#include "gamestate.h"
#include "timestepper.h"
#include "SDL/SDL_image.h"
#include <sstream>
class TitleScreen1 : public GameState
{
public:
	//member data
	static TitleScreen1* Instance()
	{
		return &m_TitleScreen1;
	}
protected:
	TitleScreen1() { }
private:
	std::stringstream *text;
	std::stringstream *text2;
	std::stringstream *text3;
	std::stringstream *text4;
	void BlitImage(int startx, int starty, SDL_Surface *source, SDL_Surface *destination);
	bool load_files();
	SDL_Surface *LoadImage(std::string filename);
	SDL_Surface* Screen;
	SDL_Color textColor;
	SDL_Color highlightedColor;
	TTF_Font *font;
	SDL_Surface *background;
	SDL_Surface *message1;
	SDL_Surface *message2;
	SDL_Surface *message3;
	SDL_Surface *hmessage1;
	SDL_Surface *hmessage2;
	SDL_Surface *hmessage3;
	SDL_Surface *initialmessage;
	Timestepper *TimeStep;
	int state;
	void Init();
	void Cleanup();

	void Pause();
	void Resume();

	void HandleEvents(Engine* game);
	void Update(Engine* game);
	void Draw(Engine* game);

	static TitleScreen1 m_TitleScreen1;
};

#endif
