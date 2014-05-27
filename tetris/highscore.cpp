#include "highscore.h"
#include "playzone.h"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <sstream>
#include "scorelist.h"
#include "engine.h"
#include "titlescreen1.h"
#include "globals.h"
highscore highscore::m_highscore;

void highscore::Init()
{
	name=new StringInput;

	if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
	{
		std::cout<<"failed at sdliniteverything"<<std::endl;
        	exit(0);
	}
	Screen = SDL_SetVideoMode( 720, 580, 32, SDL_SWSURFACE ); 
	//If there was an error in setting up the screen
	if( Screen == NULL )
	{
		std::cout<<"failed at screen"<<std::endl;
        	exit(0);
	}
	//Initialize SDL_ttf
	if( TTF_Init() == -1 )
	{
		std::cout<<"failed at ttfinit"<<std::endl;
        	exit(0);
	}
	//Set the window caption
	SDL_WM_SetCaption( "TTF Test", NULL );
	//Load the files
	if( load_files() == false )
	{
		std::cout<<"failed at load_files"<<std::endl;
        	exit(0);
	}

}
void highscore::BlitImage(int startx, int starty, SDL_Surface *source, SDL_Surface *destination) //blit an image to screen
{
	//for starting position
	SDL_Rect offsets;
	offsets.x = startx;
	offsets.y = starty;
	SDL_BlitSurface(source, 0, destination, &offsets);
}
bool highscore::load_files()
{
	background  = load_image("images/highscore.bmp");
	//Open the font
	font = TTF_OpenFont( "fonts/lazy.ttf", 42 );
	//If there was a problem in loading the background
	if( background == NULL )
	{
		return false;
	}
	//If there was an error in loading the font
	if( font == NULL )
	{
	    return false;
	}
	//If everything loaded fine
	return true;
}
void highscore::Cleanup()
{
	return;
}
void highscore::Pause()
{
	delete name;
	TTF_CloseFont(font);
	SDL_FreeSurface(background);
	SDL_FreeSurface(Screen); 

	return;
}
void highscore::Resume()
{
	return;
}
void highscore::HandleEvents(Engine* game)
{
	name->handle_input(event,font,textColor);
}
void highscore::Update(Engine* game)
{
	if (name->getDone())
	{
		game->tempname=name->getString();
		scorelist s;
		s.retrieveScores();
		score scor;
		scor.numscore=game->tempnum;
		scor.namescore=game->tempname;
		s.insertScore(scor);
		
		game->ChangeState(TitleScreen1::Instance());
	}
	return;
}
void highscore::Draw(Engine* game)
{
	BlitImage( 0, 0, background, Screen );
	name->show_centered(Screen,font,textColor);
	if( SDL_Flip( Screen ) == -1 )
	{
		std::cout<< "faied at flip";
	        exit(0);
	}
}
SDL_Surface *highscore::load_image(std::string filename)
{
	SDL_Surface *image = 0;
	image = IMG_Load(filename.c_str());
	if (image == 0) { std::cout<<"failsause";exit(0); }
	return image;
}
