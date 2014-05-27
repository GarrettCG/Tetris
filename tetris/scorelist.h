#ifndef SCORELIST_H
#define SCORELIST_H

#include <iostream>
#include <string>
#include <vector>
typedef struct score
{
	int numscore;
	std::string namescore;
}score;
class scorelist
{
	public:
		scorelist();
		bool insertScore(score newscore);//want to know if it actually inserted anything, score could be too low to insert
		void retrieveScores();//populates the string array with the scorelist sets isCurrent to true
		bool IsCurrent();
		void writeScores();
		void printScores();
		int rturnTenth();
	//private:
		bool isCurrent;
		std::vector<score> scores;
		std::vector <score>::iterator Iter;

};
#endif
