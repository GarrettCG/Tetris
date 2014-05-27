//general purpose timer

#ifndef TIMER_H
#define TIMER_H

#include "globals.h"

class Timer
{
public:
//member functions
	Timer(); //constructor

	void Start(); //start the timer
	void Stop(); //stop the timer
	int GetTime(); //get current time

private:
//member data
	int m_starttime; //time when timer starts
	bool m_started; //sets timer on/off
};

#endif

/*
EXAMPLE USAGE

int main()
{
	Timer timecheck; //instantiation
	int time = 0; //variable to hold time

	timecheck.Start(); //begin timing

	//do some code here

	time = timecheck.GetTime(); //stores time elapsed in time variable
	timecheck.Stop(); //this can be used to then restart the timer

	cout << time; //display the time to see how long your code took

	return 0;
}
*/