#ifndef PIECE_H
#define PIECE_H

/*node-----------*/
typedef struct node{
	int rotation[5][5];
	node *prev;
	node *next;
}node;
class Piece //base class for pieces
{
public:
	//constructor
	Piece(int colores);
	Piece();
	//accessors
	int GetColor();
	node* GetCurrentPtr();
	node* GetOriginalPtr();
	void SetCurrentPtr(node* nod);
	void originize();
private:
	//member data
	node *original;
	node *current;
	int color;
};
#endif
