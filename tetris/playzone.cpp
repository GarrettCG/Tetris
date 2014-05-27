#include "playzone.h"
#include "globals.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "highscore.h"
#include "titlescreen1.h"
#include "scorelist.h"
PlayZone PlayZone::m_PlayZone;
void PlayZone::DrawBlock(int block,int x, int y)
{
	if (block == NOBLOCK) { BlitImage(x, y, NOBLOCKHolder, Screen); }
	else if (block == BLUEBLOCK) { BlitImage(x, y, BLUEBLOCKHolder, Screen); }
	else if (block == GREENBLOCK) { BlitImage(x, y, GREENBLOCKHolder, Screen); }
	else if (block == PURPLEBLOCK) { BlitImage(x, y, PURPLEBLOCKHolder, Screen); }
	else if (block == REDBLOCK) { BlitImage(x, y, REDBLOCKHolder, Screen); }
	else if (block == TEALBLOCK) { BlitImage(x, y, TEALBLOCKHolder, Screen); }
	else if (block == WHITEBLOCK) { BlitImage(x, y, WHITEBLOCKHolder, Screen); }
	else if (block == YELLOWBLOCK) { BlitImage(x, y, YELLOWBLOCKHolder, Screen); }
}

void PlayZone::Init()
{
	s.retrieveScores();
	//SDL_Init( SDL_INIT_EVERYTHING ); 
	level=1;
	font = NULL;
	//now we set the level and score text
	text << "Level: " << level;
	text2 << "Score: " << score;
	//The color of the font
	textColor = { 255, 255, 255 };
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
	//Render the text
	message = TTF_RenderText_Solid(font, text.str().c_str(),textColor);
	message2 = TTF_RenderText_Solid(font, text2.str().c_str(),textColor);
	//If there was an error in rendering the text
	if( message == NULL )
	{
		std::cout<<"failed at message"<<std::endl;
        	exit(0);
	}
	NOBLOCKHolder = LoadImage("images/NOBLOCK.bmp");
	BLUEBLOCKHolder = LoadImage("images/BLUEBLOCK.bmp");
	GREENBLOCKHolder = LoadImage("images/GREENBLOCK.bmp");
	PURPLEBLOCKHolder = LoadImage("images/PURPLEBLOCK.bmp");
	REDBLOCKHolder = LoadImage("images/REDBLOCK.bmp");
	TEALBLOCKHolder = LoadImage("images/TEALBLOCK.bmp");
	WHITEBLOCKHolder = LoadImage("images/WHITEBLOCK.bmp");
	YELLOWBLOCKHolder = LoadImage("images/YELLOWBLOCK.bmp");
	BACKGROUNDHolder = LoadImage("images/BACKGROUND.bmp");
	TimeStep=new Timestepper(1000);
	TimeStep->reset();
	m_rows = 29;
	m_columns = 20;
	currX=InitialX;
	currY=InitialY;
	srand(time(0));
	int random1=rand()%7;
	int random2=rand()%7;
	NextPiece=random1;
	CurrentPiece=random2;
	Piece p1(1);PieceArray[0]=p1;
	Piece p2(2);PieceArray[1]=p2;
	Piece p3(3);PieceArray[2]=p3;
	Piece p4(4);PieceArray[3]=p4;
	Piece p5(5);PieceArray[4]=p5;
	Piece p6(6);PieceArray[5]=p6;
	Piece p7(7);PieceArray[6]=p7;
	for (int i = 0; i < m_rows; i++)
	{
		for (int j = 0; j < m_columns; j++)
		{
			m_PlayBox[i][j] = 0;
		}
	}
	for (int i = 3; i < 25; i++)
	{
		m_PlayBox[i][4] = 8;
	}
	for (int i = 3; i < 25; i++)
	{
		m_PlayBox[i][15] = 8;
	}
	for (int j = 4; j < 15; j++)
	{
		m_PlayBox[24][j] = 8;
	}
}
void PlayZone::Cleanup()
{
	//write destructor here
	//delete Screen;
	delete TimeStep;
	SDL_FreeSurface (background);
	SDL_FreeSurface (message);
	SDL_FreeSurface (message2);
	//delete font;
	SDL_FreeSurface (NOBLOCKHolder);
	SDL_FreeSurface (BLUEBLOCKHolder);
	SDL_FreeSurface (GREENBLOCKHolder);
	SDL_FreeSurface (PURPLEBLOCKHolder);
	SDL_FreeSurface (REDBLOCKHolder);
	SDL_FreeSurface (TEALBLOCKHolder);
	SDL_FreeSurface (WHITEBLOCKHolder);
	SDL_FreeSurface (YELLOWBLOCKHolder);
	SDL_FreeSurface (BACKGROUNDHolder);
	
	level = 0;
	score = 0;
	text << "Level: " << level;
	text2 << "Score: " << score;

}
void PlayZone::Pause()
{
}
void PlayZone::Resume()
{
}
void PlayZone::insert()
{
	for (int i=0;i<5;i++)
	{
		for (int j=0;j<5;j++)
		{
			if(PieceArray[CurrentPiece].GetCurrentPtr()->rotation[i][j]!=0)
				m_PlayBox[i+currY][j+currX]=PieceArray[CurrentPiece].GetCurrentPtr()->rotation[i][j];
		}
	}
}
bool PlayZone::isColision(int xoffset,int yoffset)//should be 1,0 for down 0,1 for right 0,-1 for left
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
		if ( (PieceArray[CurrentPiece].GetCurrentPtr()->rotation[i][j]!=0) && (m_PlayBox[i+currY+xoffset][j+currX+yoffset]!=0) )//the plus one here is specific to the downwards collision check, this must be changed later when we implement left and right )
			return true;
		}
	}
	return false;
}
bool PlayZone::isRotColision(node * temp)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if ( (temp->rotation[i][j]!=0) && (m_PlayBox[i+currY][j+currX]!=0) )//the plus one here is specific to the downwards collision check, this must be changed later when we implement left and right )
			return true;
		}
	}
	return false;
}
void PlayZone::SetNextPiece(int NextP)
{
	NextPiece=NextP;
}
void PlayZone::SetCurrentPiece(int CurrentP)
{
	CurrentPiece=CurrentP;
}
void PlayZone::PrintScreen()
{
	std::cout<<std::endl;
	for (int i = 0; i < m_rows; i++)
	{
		for (int j = 0; j < m_columns; j++)
		{
			std::cout<<m_PlayBox[i][j];
		}
		std::cout<<std::endl;
	}
}
void PlayZone::Draw(Engine* game) //refresh game area
{
	//PrintScreen();
	for (int y = 0; y < SCREENHEIGHT;)
	{
		for (int x = 0; x < SCREENWIDTH;)
		{
			BlitImage(x, y, BACKGROUNDHolder, Screen);
			x += 20;
		}
	y += 20;
	}
	int x,y;

	//draw the main board
	x = 160;
	y = 0;
	for (int i = 0; i < m_rows; i++)
	{
		for (int j = 0; j < m_columns; j++)
		{
			DrawBlock(m_PlayBox[i][j],x,y);
		x += 20;
		}
	x = 160;
	y += 20;
	}
	//we draw the piece second
	x = 160+20*currX;
	y = 20*currY;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if((PieceArray[CurrentPiece].GetCurrentPtr()->rotation[i][j])!=0 )
				DrawBlock(PieceArray[CurrentPiece].GetCurrentPtr()->rotation[i][j],x,y);
			x += 20;
		}
	x = 160+20*currX;
	y += 20;
	}
	//draw some in between areas
	for (int y = 0; y < 80;)
	{
		for (int x = 160; x < 560;)
		{
			BlitImage(x, y, BACKGROUNDHolder, Screen);
			x += 20;
		}
	y += 20;
	}
	for (int y = 80; y < SCREENHEIGHT;)
	{
		for (int x = 160; x < 260;)
		{
			BlitImage(x, y, BACKGROUNDHolder, Screen);
			x += 20;
		}
	y += 20;
	}
	for (int y = 80; y < SCREENHEIGHT;)
	{
		for (int x = 460; x < 560;)
		{
			BlitImage(x, y, BACKGROUNDHolder, Screen);
			x += 20;
		}
	y += 20;
	}
	for (int y = 480; y < SCREENHEIGHT;)
	{
		for (int x = 160; x < 560;)
		{
			BlitImage(x, y, BACKGROUNDHolder, Screen);
			x += 20;
		}
	y += 20;
	}
	//now we draw nextzone
	x = 60;
	y = 80;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
		DrawBlock(PieceArray[NextPiece].GetOriginalPtr()->rotation[i][j],x,y);
		x += 20;
		}
	x = 60;
	y += 20;
	}
		


	for (int y = 21; y < 24;y++)
	{
		for (int x = 3; x < 9;x++)
		{
			BlitImage(x*20, y*20, NOBLOCKHolder, Screen);

		}

	}

	//blit stringstream to surface
	level=(score-(score%10))/10;
	text.str("");
	text2.str("");
	text << "Level: " << level;
	text2 << "Score: " << score;
	message = TTF_RenderText_Solid(font, text.str().c_str(),textColor);
	message2 = TTF_RenderText_Solid(font, text2.str().c_str(),textColor);
	BlitImage( 60, 420, message, Screen );
	BlitImage( 60, 460, message2, Screen );
	if( SDL_Flip( Screen ) == -1 )
	{
		std::cout<< "faied at flip";
	        exit(0);
	}

}
bool PlayZone::load_files()
{
    //Open the font
    font = TTF_OpenFont( "fonts/lazy.ttf", 20 );
    //If there was an error in loading the font
    if( font == NULL )
    {
        return false;
    }
    //If everything loaded fine
    return true;
}
SDL_Surface *PlayZone::LoadImage(std::string filename) //this code works just like the sdl one
{
	SDL_Surface *image = 0;
	image = IMG_Load(filename.c_str());
	if (image == 0) { exit(0); }

	return image;
}
void PlayZone::BlitImage(int startx, int starty, SDL_Surface *source, SDL_Surface *destination) //blit an image to screen
{
	//for starting position
	SDL_Rect offsets;
	offsets.x = startx;
	offsets.y = starty;

	SDL_BlitSurface(source, 0, destination, &offsets);
}

bool PlayZone::StartupMap() //initialize empty screen for game start
{
	return 1;
}

bool PlayZone::CheckLose() //check for full screen to end game
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 5; j < 15; j++)
		{
			//if there is a block in the top area
			if (m_PlayBox[i][j] != 0)
			{
				//you lose
				return 1;
			}
		}
	}
	return 0;
}
void PlayZone::Update(Engine *game) //drop current piece
{

	//timestep check
	if (TimeStep->update())		
	{
		//exit(0);
		//put temp array into playbox
		if(isColision(1,0))
		{
			//need to enter the piece into the m_piecebox here
			DoLotsOfStuff();//this moves the next piece to current piece and enters the piece into the matrix, also resets currY,currX
			if (CheckLose())
			{
				if (score>s.rturnTenth())
				{
					game->tempnum=score;
					game->ChangeState( highscore::Instance());
				}
				else
				{
					game->Cleanup();
					game->ChangeState( TitleScreen1::Instance());
				}
			}
		}
		else
		{
			currY++;
			return;
		}
	}
}
void PlayZone::DoLotsOfStuff()
{
	insert();
	currX=InitialX;
	currY=InitialY;
	CurrentPiece=NextPiece;
	PieceArray[CurrentPiece].originize();
	srand(time(0));
	int random=rand()%7;
	NextPiece=random;
	//check for full lines
	CheckLines();
	return;
}
void PlayZone::CheckLines() //check for full lines to remove
{
	for (int i = 4; i < 24; i++)
	{
		//if this row is full
		if ((m_PlayBox[i][5] != 0) && (m_PlayBox[i][6] != 0) && (m_PlayBox[i][7] != 0) && (m_PlayBox[i][8] != 0) && (m_PlayBox[i][9] != 0) 
		&& (m_PlayBox[i][10] != 0) && (m_PlayBox[i][11] != 0) && (m_PlayBox[i][12] != 0) && (m_PlayBox[i][13] != 0) && (m_PlayBox[i][14] != 0))
		{	
			score++;
			if (score%10==0)
				TimeStep->ChangeFrequency(700-(5*(score-(score%10))/10));
			//remove the line
			m_PlayBox[i][5] = 0;
			m_PlayBox[i][6] = 0;
			m_PlayBox[i][7] = 0;
			m_PlayBox[i][8] = 0;
			m_PlayBox[i][9] = 0;
			m_PlayBox[i][10] = 0;						
			m_PlayBox[i][11] = 0;
			m_PlayBox[i][12] = 0;
			m_PlayBox[i][13] = 0;
			m_PlayBox[i][14] = 0;
			row = i;
			//move everything above the line down
			for (int y = row; y > 3; y--)
			{
				for (int x = 5; x < 15; x++)
				{
					m_PlayBox[y][x] = m_PlayBox[(y - 1)][x];
				}
			}
		}
	}			
}
void PlayZone::HandleEvents(Engine * game) //handle keystrokes
{
SDL_Event event;
while (SDL_PollEvent(&event))
{
	if (event.type == SDL_KEYDOWN) //if a key is pressed
	{
		//Escape---------------------------------------------------------------------
		if (event.key.keysym.sym == SDLK_ESCAPE)
		{
			game->Quit();	
			return;
		}
		//down arrow---------------------------------------------------------------------
		if (event.key.keysym.sym == SDLK_DOWN)
		{
			if(!isColision(1,0))
			{
				TimeStep->reset();
				currY++;
				return;
			}
			else
			{
				DoLotsOfStuff();
				if (CheckLose())
				{
					if (score>s.rturnTenth())
					{
						game->tempnum=score;
						game->ChangeState( highscore::Instance());
					}
					else
					{
						//game->Cleanup();
						game->ChangeState( TitleScreen1::Instance());
					}
				}
			}
		}
		//left arrow---------------------------------------------------------------------
		if (event.key.keysym.sym == SDLK_LEFT)
		{
			if(!isColision(0,-1))
			{
				currX--;
				return;
			}
		}
		//right arrow--------------------------------------------------------------------
		if (event.key.keysym.sym == SDLK_RIGHT)
		{
			if(!isColision(0,1))
			{
				currX++;
				return ;
			}
		}
		//right arrow--------------------------------------------------------------------
		if (event.key.keysym.sym == SDLK_UP)
		{
			while(!isColision(1,0))
			{
				TimeStep->reset();
				currY++;
			}
			return;
		}
		//UP arrow--------------------------------------------------------------------
		if (event.key.keysym.sym == SDLK_RSHIFT)
		{
			if(!isRotColision(PieceArray[CurrentPiece].GetCurrentPtr()->next))
			{
				PieceArray[CurrentPiece].SetCurrentPtr((PieceArray[CurrentPiece].GetCurrentPtr()->next));
				return;
			}
		}
		//SPACE --------------------------------------------------------------------
		if (event.key.keysym.sym == SDLK_SPACE)
		{
			if(!isRotColision(PieceArray[CurrentPiece].GetCurrentPtr()->prev))
			{
				PieceArray[CurrentPiece].SetCurrentPtr((PieceArray[CurrentPiece].GetCurrentPtr()->prev));
				return;
			}
		}
	}
}
}
