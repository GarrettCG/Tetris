#ifndef example_H
#define example_H

#include <iostream>
#include "gamestate.h"
#include "SDL/SDL_ttf.h"


class example : public GameState
{
public:
	//member data
	static example* Instance()
	{
		return &m_example;
	}

protected:
	example() { }
private:
	bool load_files();
	SDL_Surface * load_image( std::string filename );
	SDL_Surface *background;
	SDL_Surface *message;
	SDL_Surface *screen;
	SDL_Color textColor;
	TTF_Font *font;
	void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip);
	void Init();
	void Cleanup();

	void Pause();
	void Resume();

	void HandleEvents(Engine* game);
	void Update(Engine* game);
	void Draw(Engine* game);

	static example m_example;
};

#endif
