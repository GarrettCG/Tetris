#include "nextzone.h"
#include "sdlstuff.h"

NextZone::NextZone() //constructor
{
	m_rows = 5;
	m_columns = 5;
	for (int i = 0; i < m_rows; i++)
	{
		for (int j = 0; j < m_columns; j++)
		{
			m_NextBox[i][j] = 0;
		}
	}
}
Piece NextZone::GetNextPiece() //get random next piece
{
	int randompiece = 4; //rand() % 7 + 1;
	
	if (randompiece == 1) 
	{ 
		L LPiece;
		NextPiece = LPiece;
		for (int i = 0; i < m_rows; i++)
		{
			for (int j = 0; j < m_columns; j++)
			{
				m_NextBox[i][j] = LPiece.m_PieceBox[i][j];
			}
		}
		return NextPiece;
	}

	if (randompiece == 2) 
	{ 
		ReverseL ReverseLPiece; 
		NextPiece = ReverseLPiece;
		for (int i = 0; i < m_rows; i++)
		{
			for (int j = 0; j < m_columns; j++)
			{
				m_NextBox[i][j] = ReverseLPiece.m_PieceBox[i][j];
			}
		}
		return NextPiece;
	}

	if (randompiece == 3) 
	{ 
		Square SquarePiece; 
		NextPiece = SquarePiece;
		for (int i = 0; i < m_rows; i++)
		{
			for (int j = 0; j < m_columns; j++)
			{
				m_NextBox[i][j] = SquarePiece.m_PieceBox[i][j];
			}
		}
		return NextPiece;
	}

	if (randompiece == 4) 
	{ 
		Line LinePiece;
		NextPiece = LinePiece;
		for (int i = 0; i < m_rows; i++)
		{
			for (int j = 0; j < m_columns; j++)
			{
				m_NextBox[i][j] = LinePiece.m_PieceBox[i][j];
			}
		}
		return NextPiece;
	}

	if (randompiece == 5) 
	{ 
		Z ZPiece; 
		NextPiece = ZPiece;
		for (int i = 0; i < m_rows; i++)
		{
			for (int j = 0; j < m_columns; j++)
			{
				m_NextBox[i][j] = ZPiece.m_PieceBox[i][j];
			}
		}
		return NextPiece;
	}

	if (randompiece == 6) 
	{ 
		S SPiece; 
		NextPiece = SPiece;

		for (int i = 0; i < m_rows; i++)
		{
			for (int j = 0; j < m_columns; j++)
			{
				m_NextBox[i][j] = SPiece.m_PieceBox[i][j];
			}
		}
		return NextPiece;
	}

	if (randompiece == 7) 
	{ 
		T TPiece; 
		NextPiece = TPiece;
		for (int i = 0; i < m_rows; i++)
		{
			for (int j = 0; j < m_columns; j++)
			{
				m_NextBox[i][j] = TPiece.m_PieceBox[i][j];
			}
		}
		return NextPiece;
	}
}


void NextZone::DrawNext() //display next piece area
{
	int x = 60;
	int y = 80;
	for (int i = 0; i < m_rows; i++)
	{
		for (int j = 0; j < m_columns; j++)
		{
			if (m_NextBox[i][j] == NOBLOCK) { BlitImage(x, y, NOBLOCKHolder, Screen); }
			else if (m_NextBox[i][j] == BLUEBLOCK) { BlitImage(x, y, BLUEBLOCKHolder, Screen); }
			else if (m_NextBox[i][j] == GREENBLOCK) { BlitImage(x, y, GREENBLOCKHolder, Screen); }
			else if (m_NextBox[i][j] == PURPLEBLOCK) { BlitImage(x, y, PURPLEBLOCKHolder, Screen); }
			else if (m_NextBox[i][j] == REDBLOCK) { BlitImage(x, y, REDBLOCKHolder, Screen); }
			else if (m_NextBox[i][j] == TEALBLOCK) { BlitImage(x, y, TEALBLOCKHolder, Screen); }
			else if (m_NextBox[i][j] == WHITEBLOCK) { BlitImage(x, y, WHITEBLOCKHolder, Screen); }
			else if (m_NextBox[i][j] == YELLOWBLOCK) { BlitImage(x, y, YELLOWBLOCKHolder, Screen); }
		x += 20;
		}
	x = 60;
	y += 20;
	}
}
