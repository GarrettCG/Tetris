#include "scorelist.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <stdlib.h> 
using namespace std;
scorelist::scorelist()
{
	scores.resize(10);
	std::cout<<"scores.size() is :"<<scores.size()<<std::endl;
	isCurrent=false;	
}
void scorelist::printScores()
{
	std::cout<<"about to print scores vector"<<std::endl;
	for (int i=0;i<10;i++)
		std::cout<<scores[i].namescore<<std::endl;
	std::cout<<"finished printing scores vector"<<std::endl;
}
int scorelist::rturnTenth()
{
	return scores[9].numscore;
}
bool scorelist::insertScore(score newscore)//want to know if it actually inserted anything, score could be too low to insert
{
	if (isCurrent)
	{
		std::cout<<"inside iscurrent if"<<std::endl;
		printScores();
		if (scores.empty())
			{
				std::cout<<"inside scores.empty if"<<std::endl;
				scores.push_back(newscore);
				writeScores();
				return true;
			}
		//insert score into list
		for (int i=0; i<scores.size(); i++)
		{
			if (newscore.numscore>scores[i].numscore)
			{
				std::cout<<"about to insert";
				scores.insert( scores.begin()+i, newscore );
				if (scores.size()>10)
					scores.erase(scores.end());//delete the 11th score
				//missing code; right here i need to write out to the file
				writeScores();
				return true;
			}
		}
		std::cout<<"failed to find highest value";
	}
	else
		return false;
}
void scorelist::writeScores()
{	
	ofstream myfile;
	myfile.open ("scorelist.gbtp");//open file for output, if file exists, overwrite it
	if (scores.empty())
	{
		myfile.close();
		return;
	}	
	for (int i=0;i<scores.size();i++)
		myfile <<scores[i].numscore<<","<<scores[i].namescore<<"\n";
	myfile.close();
}
void scorelist::retrieveScores()//populates the string array with the scorelist; sets isCurrent to true
{
	ifstream myfile;
	string line;
	string::size_type position;
	string name;
	string num;
	myfile.open ("scorelist.gbtp");
	//myfile.open ("scorelist.gbtp",ios::in);
	if (myfile.is_open())
	{
		int i=0;
		while (! myfile.eof() )
		{
			if (i>9)
			{
				std::cout<<"error: list is trying to be read in past 10. scores.size() is :"<<scores.size()<<std::endl<<"i is: "<<i<<std::endl;
				isCurrent=true;
				myfile.close();
				return;
			}
			getline (myfile,line);
			std::cout<<"line is :"<<line<<std::endl;
			position= line.find(",");
			if ((int)position!=-1)
			{
				std::cout<<"position is :"<<(int)position<<std::endl;
				num=line.substr(0, (int)position);
				std::cout<<"num is :"<<num<<std::endl;
				name=line.substr((int)position+1);
				std::cout<<"position is :"<<name<<std::endl;
				scores[i].namescore=name;
				scores[i].numscore=atoi(num.c_str());
			}
			else
			{
				scores[i].numscore=0;
				scores[i].namescore="nobody";
			}
			i++;
		}
		for (int j=i;j<10;j++)
		{
			scores[j].numscore=0;
			scores[j].namescore="nobody";
		}
	}
	myfile.close();
	isCurrent=true;//this doesn't seem to do anything
	return;
}
bool scorelist::IsCurrent()
{
	return isCurrent;
}

