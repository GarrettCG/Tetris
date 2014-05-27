#include "titlescreen1.h"
#include "playzone.h"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <sstream>
#include "listscores.h"
using namespace std;
TitleScreen1 TitleScreen1::m_TitleScreen1;

void TitleScreen1::Init()
{
	font = NULL;
	state=0;
	text = new stringstream;
	text2 = new stringstream;
	text3 = new stringstream;
	text4 = new stringstream;
	*text << "Play Game";
	*text2 << "High Score List";
	*text3 << "Options";
	*text4 << "PRESS SPACE KEY";
	//The color of the font



	background  = LoadImage("images/Titlescreen.bmp");
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
	textColor = { 20, 255, 2 };
	highlightedColor = { 255, 0, 100 };
	initialmessage = TTF_RenderText_Solid(font, text4->str().c_str(),textColor);
	hmessage1 = TTF_RenderText_Solid(font, text->str().c_str(),highlightedColor);
	message1 = TTF_RenderText_Solid(font, text->str().c_str(),textColor);
	hmessage2 = TTF_RenderText_Solid(font, text2->str().c_str(),highlightedColor);
	message2 = TTF_RenderText_Solid(font, text2->str().c_str(),textColor);
	hmessage3 = TTF_RenderText_Solid(font, text3->str().c_str(),highlightedColor);
	message3 = TTF_RenderText_Solid(font, text3->str().c_str(),textColor);
	//Render the text
	//message = TTF_RenderText_Solid( font, "Level", textColor );
	//If there was an error in rendering the text
	//if( message == NULL )
	//{
	//	std::cout<<"failed at message"<<std::endl;
        //	exit(0);
	//}
}
void TitleScreen1::BlitImage(int startx, int starty, SDL_Surface *source, SDL_Surface *destination) //blit an image to screen
{
	//for starting position
	SDL_Rect offsets;
	offsets.x = startx;
	offsets.y = starty;

	SDL_BlitSurface(source, 0, destination, &offsets);
}
bool TitleScreen1::load_files()
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
void TitleScreen1::Cleanup()
{
	TTF_CloseFont(font);
	SDL_FreeSurface(Screen);
	SDL_FreeSurface(background);
	SDL_FreeSurface(message1);
	SDL_FreeSurface(message2);
	SDL_FreeSurface(message3);
	SDL_FreeSurface(hmessage1);
	SDL_FreeSurface(hmessage2);
	SDL_FreeSurface(hmessage3);
	SDL_FreeSurface(initialmessage);
	delete text;
	delete text2;
	delete text3;
	delete text4;
	delete TimeStep;
	return;
}
void TitleScreen1::Pause()
{
	return;
}
void TitleScreen1::Resume()
{
	return;
}
void TitleScreen1::HandleEvents(Engine* game)
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_KEYDOWN) //if a key is pressed
		{
			//Escape---------------------------------------------------------------------
			if (event.key.keysym.sym == SDLK_SPACE)
			{
				if (state==0)
				{
					state=1;
					return;
				}
				else if (state==1)
				{
					game->Cleanup();
					game->ChangeState( PlayZone::Instance() );
					return;
				}
				else if (state==2)
				{
					game->Cleanup();					
					game->ChangeState( listscores::Instance() );
					return;
				}
				else if (state==3)
				{
					game->Cleanup();
					game->ChangeState( PlayZone::Instance() );
					return;
				}
			}
			if (event.key.keysym.sym == SDLK_DOWN)
			{
				if (state==0)
				{
					return;
				}
				else if (state==1)
				{
					state=2;
					return;
				}
				else if (state==2)
				{
					state=3;
					return;
				}
				else if (state==3)
				{
					state=1;
					return;
				}
			}
			if (event.key.keysym.sym == SDLK_UP)
			{
				if (state==0)
				{
					return;
				}
				else if (state==1)
				{
					state=3;
					return;
				}
				else if (state==2)
				{
					state=1;
					return;
				}
				else if (state==3)
				{
					state=2;
					return;
				}
			}
		}
	}
}
void TitleScreen1::Update(Engine* game)
{
	return;
}
void TitleScreen1::Draw(Engine* game)
{
	BlitImage( 0, 0, background, Screen );
	if (state!=0)
	{
		if (state==1)
		{
			BlitImage( 300, 420, hmessage1, Screen );
			BlitImage( 300, 460, message2, Screen );
			BlitImage( 300, 500, message3, Screen );
		}
		if (state==2)
		{
			BlitImage( 300, 420, message1, Screen );
			BlitImage( 300, 460, hmessage2, Screen );
			BlitImage( 300, 500, message3, Screen );
		}
		if (state==3)
		{
			BlitImage( 300, 420, message1, Screen );
			BlitImage( 300, 460, message2, Screen );
			BlitImage( 300, 500, hmessage3, Screen );
		}

	}
	else
	{
		BlitImage( 300, 460, initialmessage, Screen );
	}

	if( SDL_Flip( Screen ) == -1 )
	{
		std::cout<< "faied at flip";
	        exit(0);
	}
}
SDL_Surface *TitleScreen1::LoadImage(std::string filename)
{
	SDL_Surface *image = 0;
	image = IMG_Load(filename.c_str());
	if (image == 0) { exit(0); }
	return image;
}
