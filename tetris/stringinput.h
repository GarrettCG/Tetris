#ifndef STRINGINPUT_H
#define STRINGINPUT_H
#include <string>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "timestepper.h"
class StringInput
{
    private:
    //The storage string
    std::string str;
    std::string str2;
    //The text surface
    SDL_Surface *text;

    Timestepper * timestep;
    bool tag;
    bool tag2;
    bool done;
    public:
    bool getDone();
    //Initializes variables
    StringInput();
    std::string getString();
    //Does clean up
    ~StringInput();

    //Handles input
    void handle_input(SDL_Event event,TTF_Font *font,SDL_Color textColor);
    
    //Shows the message on screen
    void show_centered(SDL_Surface* screen,TTF_Font *font,SDL_Color textColor);
};
#endif
