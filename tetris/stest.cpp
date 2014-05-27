#include "scorelist.h"
int main()
{
	scorelist s;
	s.retrieveScores();
	score score1;
	score1.numscore=10;
	score1.namescore="greatness";
	s.insertScore(score1);
	return 0;
}
