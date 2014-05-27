#ifndef TIMESTEPPER_H
#define TIMESTEPPER_H
#include <iostream>
#include <ctime>

class Timestepper
{
public:
	Timestepper();//default constructor
	Timestepper(int freq);//constructor
	bool update();
	void ChangeFrequency(int freq);
	int GetFrequency();
	void Pause();
	void UnPause();//you should call update immediately after calling this
	void reset();
	
private:
	clock_t timer;
	int frequency;
	clock_t nextstep;
	int paused;//paused is the difference between the timer and the nextstep
};

#endif

