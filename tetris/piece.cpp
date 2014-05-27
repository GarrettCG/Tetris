#include "piece.h"
//constructor
Piece::Piece()
{
}
Piece::Piece(int colores)//constructs based on color, not shape
{
	//starting stuff
	color = colores;//the color is the main identifier
	node *rotation1=new node;
	node *rotation2=new node;
	node *rotation3=new node;
	node *rotation4=new node;
	current =rotation1;
	original=rotation1;
	//All matrices are filled with 0s
	for (int row=0;row<5;row++)
	{
		for (int col=0;col<5;col++)
		{
			rotation1->rotation[row][col]=0;
			rotation2->rotation[row][col]=0;
			rotation3->rotation[row][col]=0;
			rotation4->rotation[row][col]=0;
		}
	}
	//now we linke up the blank rotation matrices
	rotation1->next=rotation2;
	rotation1->prev=rotation4;
	rotation2->next=rotation3;
	rotation2->prev=rotation1;
	rotation3->next=rotation4;
	rotation3->prev=rotation2;
	rotation4->next=rotation1;
	rotation4->prev=rotation3;
	//now we create the rotation boxes for everything based on the color
	switch(color)//could also use colores
	{
		case 1://bitches when i use blueblock etc.
			rotation1->rotation[2][1] = color;
			rotation1->rotation[3][1] = color;
			rotation1->rotation[4][1] = color;
			rotation1->rotation[4][2] = color;
			//rotation2
			rotation2->rotation[3][0] = color;
			rotation2->rotation[3][1] = color;
			rotation2->rotation[3][2] = color;
			rotation2->rotation[4][0] = color;
			//rotation3
			rotation3->rotation[2][0] = color;
			rotation3->rotation[2][1] = color;
			rotation3->rotation[3][1] = color;
			rotation3->rotation[4][1] = color;
			//rotation4
			rotation4->rotation[3][0] = color;
			rotation4->rotation[3][1] = color;
			rotation4->rotation[3][2] = color;
			rotation4->rotation[2][2] = color;
			break;
		case 2:
			rotation1->rotation[4][0] = color;
			rotation1->rotation[4][1] = color;
			rotation1->rotation[3][1] = color;
			rotation1->rotation[2][1] = color;
			//rotation2
			rotation2->rotation[2][0] = color;
			rotation2->rotation[3][0] = color;
			rotation2->rotation[3][1] = color;
			rotation2->rotation[3][2] = color;
			//rotation3
			rotation3->rotation[2][1] = color;
			rotation3->rotation[2][2] = color;
			rotation3->rotation[3][1] = color;
			rotation3->rotation[4][1] = color;
			//rotation4
			rotation4->rotation[3][0] = color;
			rotation4->rotation[3][1] = color;
			rotation4->rotation[3][2] = color;
			rotation4->rotation[4][2] = color;
			break;
		case 3:
			rotation1->rotation[3][1] = color;
			rotation1->rotation[3][2] = color;
			rotation1->rotation[4][1] = color;
			rotation1->rotation[4][2] = color;
			//rotation2
			rotation2->rotation[3][1] = color;
			rotation2->rotation[3][2] = color;
			rotation2->rotation[4][1] = color;
			rotation2->rotation[4][2] = color;
			//rotation3
			rotation3->rotation[3][1] = color;
			rotation3->rotation[3][2] = color;
			rotation3->rotation[4][1] = color;
			rotation3->rotation[4][2] = color;
			//rotation4
			rotation4->rotation[3][1] = color;
			rotation4->rotation[3][2] = color;
			rotation4->rotation[4][1] = color;
			rotation4->rotation[4][2] = color;
			break;
		case 4:
			rotation1->rotation[1][1] = color;
			rotation1->rotation[2][1] = color;
			rotation1->rotation[3][1] = color;
			rotation1->rotation[4][1] = color;
			//rotation2
			rotation2->rotation[3][0] = color;
			rotation2->rotation[3][1] = color;
			rotation2->rotation[3][2] = color;
			rotation2->rotation[3][3] = color;
			//rotation3
			rotation3->rotation[1][1] = color;
			rotation3->rotation[2][1] = color;
			rotation3->rotation[3][1] = color;
			rotation3->rotation[4][1] = color;
			//rotation4
			rotation4->rotation[3][0] = color;
			rotation4->rotation[3][1] = color;
			rotation4->rotation[3][2] = color;
			rotation4->rotation[3][3] = color;
			break;
		case 5:
			rotation1->rotation[3][0] = color;
			rotation1->rotation[3][1] = color;
			rotation1->rotation[4][1] = color;
			rotation1->rotation[4][2] = color;
			//rotation2
			rotation2->rotation[3][0] = color;
			rotation2->rotation[4][0] = color;
			rotation2->rotation[2][1] = color;
			rotation2->rotation[3][1] = color;
			//rotation3
			rotation3->rotation[3][0] = color;
			rotation3->rotation[3][1] = color;
			rotation3->rotation[4][1] = color;
			rotation3->rotation[4][2] = color;
			//rotation4
			rotation4->rotation[3][0] = color;
			rotation4->rotation[4][0] = color;
			rotation4->rotation[2][1] = color;
			rotation4->rotation[3][1] = color;
			break;
		case 6:
			rotation1->rotation[4][0] = color;
			rotation1->rotation[3][1] = color;
			rotation1->rotation[4][1] = color;
			rotation1->rotation[3][2] = color;
			//rotation2
			rotation2->rotation[2][0] = color;
			rotation2->rotation[3][0] = color;
			rotation2->rotation[3][1] = color;
			rotation2->rotation[4][1] = color;
			//rotation3
			rotation3->rotation[4][0] = color;
			rotation3->rotation[3][1] = color;
			rotation3->rotation[4][1] = color;
			rotation3->rotation[3][2] = color;
			//rotation4
			rotation4->rotation[2][0] = color;
			rotation4->rotation[3][0] = color;
			rotation4->rotation[3][1] = color;
			rotation4->rotation[4][1] = color;
			break;
		case 7:
			rotation1->rotation[3][0] = color;
			rotation1->rotation[3][1] = color;
			rotation1->rotation[3][2] = color;
			rotation1->rotation[2][1] = color;
			//rotation2
			rotation2->rotation[2][1] = color;
			rotation2->rotation[3][1] = color;
			rotation2->rotation[4][1] = color;
			rotation2->rotation[3][2] = color;
			//rotation3
			rotation3->rotation[3][0] = color;
			rotation3->rotation[3][1] = color;
			rotation3->rotation[3][2] = color;
			rotation3->rotation[4][1] = color;
			//rotation4
			rotation4->rotation[2][1] = color;
			rotation4->rotation[3][1] = color;
			rotation4->rotation[4][1] = color;
			rotation4->rotation[3][0] = color;
			break;
	}
}
//accessors
void Piece::originize()
{
	current=original;
}
int Piece::GetColor()
{
	return color;
}
node* Piece::GetCurrentPtr()
{
	return current;
}
node* Piece::GetOriginalPtr()
{
	return original;
}
void Piece::SetCurrentPtr(node* nod)
{
	current=nod;
}

