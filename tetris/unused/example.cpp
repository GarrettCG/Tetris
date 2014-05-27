#include "titlescreen1.h"
#include "example.h"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string>
#include <iostream>
example example::m_example;

void example::Init()
{
//Screen = SDL_SetVideoMode( 720, 580, 32, SDL_SWSURFACE ); 
font = NULL;
//The color of the font
textColor = { 255, 255, 255 };
if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
{
	std::cout<<"failed at sdliniteverything"<<std::endl;
        exit(0);
}

//If there was an error in setting up the screen
if( screen == NULL )
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
//Render the text
message = TTF_RenderText_Solid( font, "Level", textColor );
//If there was an error in rendering the text
if( message == NULL )
{
	std::cout<<"failed at message"<<std::endl;
        exit(0);
}
//If everything initialized fine
return;
}
bool example::load_files()
{
    //Load the background image
    background = load_image( "images/background.png" );

    //Open the font
    font = TTF_OpenFont( "fonts/lazy.ttf", 28 );

    //If there was a problem in loading the background
    if( background == NULL )
    {
	std::cout<<"failed at background"<<std::endl;
        exit(0);
    }

    //If there was an error in loading the font
    if( font == NULL )
    {
	std::cout<<"failed at font"<<std::endl;
        exit(0);
    }

    //If everything loaded fine
    return true;
}
SDL_Surface *example::load_image( std::string filename )
{
    //The image that's loaded
    SDL_Surface* loadedImage = NULL;
    //The optimized surface that will be used
    SDL_Surface* optimizedImage = NULL;
    //Load the image
    loadedImage = IMG_Load( filename.c_str() );
    //If the image loaded
    if( loadedImage != NULL )
    {
        //Create an optimized surface
        optimizedImage = SDL_DisplayFormat( loadedImage );
        //Free the old surface
        SDL_FreeSurface( loadedImage );
        //If the surface was optimized
        if( optimizedImage != NULL )
        {
            //Color key surface
            SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, SDL_MapRGB( optimizedImage->format, 0, 0xFF, 0xFF ) );
        }
    }

    //Return the optimized surface
    return optimizedImage;
}
void example::apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL )
{
    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = x;
    offset.y = y;

    //Blit
    SDL_BlitSurface( source, clip, destination, &offset );
}
void example::Cleanup()
{
	return;
}
void example::Pause()
{
	return;
}
void example::Resume()
{
	return;
}
void example::HandleEvents(Engine* game)
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_KEYDOWN) //if a key is pressed
		{
			//Escape---------------------------------------------------------------------
			if (event.key.keysym.sym == SDLK_SPACE)
			{
				game->ChangeState( TitleScreen1::Instance() );	
				return;
			}
		}
	}
}
void example::Update(Engine* game)
{
	return;
}
void example::Draw(Engine* game)
{   
    //Apply the images to the screen
  //  apply_surface( 0, 0, background, screen );
    apply_surface( 0, 150, message, screen );

    //Update the screen
    if( SDL_Flip( screen ) == -1 )
    {
	std::cout<<"failed at flip"<<std::endl;
        exit(0);
    }
	return;
}


