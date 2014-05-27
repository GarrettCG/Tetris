#include "titlescreen1.h"
#include "playzone.h"
#include "listscores.h"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <sstream>
using namespace std;
listscores listscores::m_listscores;

void listscores::Init()
{
	std::stringstream out;
	font = NULL;
	message=NULL;
	thelist=NULL;
	background  = LoadImage("images/listscores.bmp");
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
	txtColor = { 20, 255, 2 };
}
void listscores::BlitImage(int startx, int starty, SDL_Surface *source, SDL_Surface *destination) //blit an image to screen
{
	//for starting position
	SDL_Rect offsets;
	offsets.x = startx;
	offsets.y = starty;
	SDL_BlitSurface(source, 0, destination, &offsets);
}
bool listscores::load_files()
{
	font = TTF_OpenFont( "fonts/lazy.ttf", 20 );
	if( font == NULL )
	{
		std::cout<<"error background is null";
	        return false;
	}
	//If everything loaded fine
	return true;
}
void listscores::Cleanup()
{
	TTF_CloseFont(font);
	SDL_FreeSurface(Screen);
	SDL_FreeSurface(background);

	return;
}
void listscores::Pause()
{
	return;
}
void listscores::Resume()
{
	return;
}
void listscores::HandleEvents(Engine* game)
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_KEYDOWN) //if a key is pressed
		{
			//Escape---------------------------------------------------------------------
			if (event.key.keysym.sym == SDLK_SPACE)
			{
				game->ChangeState( TitleScreen1::Instance());
			}
		}
	}
}
void listscores::Update(Engine* game)
{
	if (thelist==NULL)
	{
		thelist=new scorelist;
		thelist->retrieveScores();
	}
	return;
}
void listscores::Draw(Engine* game)
{
	BlitImage( 0, 0, background, Screen );
	
	for (int h=0;h<10;h++)
	{
		message = TTF_RenderText_Solid(font, thelist->scores[h].namescore.c_str(),txtColor);
		out << thelist->scores[h].numscore;
		message2 = TTF_RenderText_Solid(font, out.str().c_str(),txtColor);
		BlitImage(200, 260+h*25, message, Screen );
		BlitImage(400, 260+h*25, message2, Screen );
		SDL_FreeSurface(message);
		SDL_FreeSurface(message2);
		out.str("");
	}

	if( SDL_Flip( Screen ) == -1 )
	{
		std::cout<< "faied at flip";
	        exit(0);
	}
}
SDL_Surface *listscores::LoadImage(std::string filename)
{
	SDL_Surface *image = 0;
	image = IMG_Load(filename.c_str());
	if (image == 0) { exit(0); }
	return image;
}
