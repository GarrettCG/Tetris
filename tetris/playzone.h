#ifndef PLAYZONE_H
#define PLAYZONE_H
#include "piece.h"
#include <iostream>
#include <sstream>
#include "timestepper.h"
#include "gamestate.h"
#include "scorelist.h"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
class PlayZone : public GameState
{
public:
	//member data
	
	int m_PlayBox[29][20];
	int m_rows;
	int m_columns;

	//PlayZone(); //constructor
	//member functions
	void SetNextPiece(int NextP);
	void SetCurrentPiece(int CurrentP);
	//void Tick(); //drop current piece

	void CheckLines(); //check for full lines to remove
	bool CheckLose(); //check for full screen to end game
	void DrawScreen(); //refresh game area
	void PrintScreen();
	static PlayZone* Instance()
	{
		return &m_PlayZone;
	}

protected:
	PlayZone() { }
private:
	SDL_Surface *LoadImage(std::string filename);
	std::stringstream text;
	std::stringstream text2;
	scorelist s;
	void BlitImage(int startx, int starty, SDL_Surface *source, SDL_Surface *destination); //blit an image to screen
	bool StartupMap(); //initialize empty screen for game start
	SDL_Surface* Screen;
	void DoLotsOfStuff();
	Timestepper *TimeStep;
	Piece PieceArray[7];
	bool isColision(int xoffset,int yoffset);
	int CurrentPiece;
	int NextPiece;
	int currX;
	int currY;
	void insert();
	bool isRotColision(node * temp);
	int level;
	int score;
	bool load_files();
	SDL_Surface *background;
	SDL_Surface *message;
	SDL_Surface *message2;
	//SDL_Surface *screen;
	SDL_Color textColor;
	TTF_Font *font;
	SDL_Surface *NOBLOCKHolder;
	SDL_Surface *BLUEBLOCKHolder;
	SDL_Surface *GREENBLOCKHolder;
	SDL_Surface *PURPLEBLOCKHolder;
	SDL_Surface *REDBLOCKHolder;
	SDL_Surface *TEALBLOCKHolder;
	SDL_Surface *WHITEBLOCKHolder;
	SDL_Surface *YELLOWBLOCKHolder;
	SDL_Surface *BACKGROUNDHolder;
	void Init();
	void Cleanup();

	void Pause();
	void Resume();

	void HandleEvents(Engine* game);
	void Update(Engine* game);
	void Draw(Engine* game);

	void DrawBlock(int block,int x,int y);

	static PlayZone m_PlayZone;
};

#endif
