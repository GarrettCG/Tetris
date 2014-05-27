#include "stringinput.h"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <iostream>
#include "timestepper.h"
void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL )
{
    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = x;
    offset.y = y;

    //Blit
    SDL_BlitSurface( source, clip, destination, &offset );
}
std::string StringInput::getString()
{
	return str;
}
StringInput::StringInput()
{
    done=false;
    tag=0;
    tag2=0;
    timestep=new Timestepper(700);
    //Initialize the string
    str = "";

    //Initialize the surface
    text = NULL;

    //Enable Unicode
    SDL_EnableUNICODE( SDL_ENABLE );
}

StringInput::~StringInput()
{
    //Free text surface
    SDL_FreeSurface( text );

    //Disable Unicode
    SDL_EnableUNICODE( SDL_DISABLE );
}
void StringInput::show_centered(SDL_Surface* screen,TTF_Font *font,SDL_Color textColor)
{
    //If the surface isn't blank
//	std::cout<<"in string input before text check "<<text<<std::endl;
	if (timestep->update())//if appropriate, add a pipe to the beginning of the string
	{
		if (tag==false)
		{
			str2=str+"|";
           		SDL_FreeSurface( text );
            		//Render a new text surface
            		text = TTF_RenderText_Solid( font, str2.c_str(), textColor );
			tag=true;
		}
		else
		{
			str2=str+" ";
			SDL_FreeSurface( text );
            		//Render a new text surface
            		text = TTF_RenderText_Solid( font, str2.c_str(), textColor );
			tag=false;
			
		}	
	}
	else
	{
		SDL_FreeSurface( text );
            	//Render a new text surface
            	text = TTF_RenderText_Solid( font, str2.c_str(), textColor );
	}
    if( text != NULL )
    {
        //Show the name
	std::cout<<"in string input"<<std::endl;
        apply_surface( ( 500 ) / 2, ( 1050 - text->h ) / 2, text, screen );
    }
}
bool StringInput::getDone()
{
	return done;
}
void StringInput::handle_input(SDL_Event event,TTF_Font *font,SDL_Color textColor)
{
while (SDL_PollEvent(&event))
{	

	SDL_EnableUNICODE( SDL_ENABLE );
    //If a key was pressed
    if( event.type == SDL_KEYDOWN )
    {
	std::cout<<"in stringinput 1"<<std::endl;
        //Keep a copy of the current version of the string
        std::string temp = str;

        //If the string less than maximum size
        if( str.length() <= 16 )
        {
            //If the key is a space
            if( event.key.keysym.unicode == (Uint16)' ' )
            {
		std::cout<<"in stringinput space"<<std::endl;
                //Append the character
                str += (char)event.key.keysym.unicode;
            }
            //If the key is a number
            else if( ( event.key.keysym.unicode >= (Uint16)'0' ) && ( event.key.keysym.unicode <= (Uint16)'9' ) )
            {
                //Append the character
                str += (char)event.key.keysym.unicode;
		std::cout<<"in stringinput 09"<<std::endl;
            }
            //If the key is a uppercase letter
            else if( ( event.key.keysym.unicode >= (Uint16)'A' ) && ( event.key.keysym.unicode <= (Uint16)'Z' ) )
            {
                //Append the character
		std::cout<<"in stringinput AZ"<<std::endl;
                str += (char)event.key.keysym.unicode;
            }
            //If the key is a lowercase letter
            else if( ( event.key.keysym.unicode >= (Uint16)'a' ) && ( event.key.keysym.unicode <= (Uint16)'z' ) )
            {
		std::cout<<"in stringinput az"<<std::endl;
                //Append the character
                str += (char)event.key.keysym.unicode;
            }
		if (event.key.keysym.sym == SDLK_RETURN)
		{
			done=true;
			return;
		}
        }

        //If backspace was pressed and the string isn't blank
        if( ( event.key.keysym.sym == SDLK_BACKSPACE ) && ( str.length() != 0 ) )
        {
            //Remove a character from the end
            str.erase( str.length() - 1 );
        }
//	if (tag==true)
		str2=str+"|";
		timestep->reset();
//	else
//		str2=str+" ";
        //If the string was changed
    }
}
}

