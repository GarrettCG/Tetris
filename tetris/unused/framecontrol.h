#ifndef FRAMECONTROL_H
#define FRAMECONTROL_H

#include "timer.h"

class FrameControl
{
public:
//member functions
	FrameControl(int fpscap); //constructor
	void LimitFPS(int time); //sleep if frames are moving too fast
	void UpdateDisplay(int time, SDL_Surface *screen); //draw display
	Timer m_fpslimiter; //timer for fps cap
	Timer m_averagefps; //timer for average fps
	Timer m_currentframesecond; //timer for frames/sec

private:
//member data
	int m_fpscap; //sets fps limit
	int m_framecount; //keeps frame count
	int m_currentfps; //current fps
	int m_beginningframe; //start of sec frame for frames/sec
	bool m_framestate; //switch for frames/sec
	TTF_Font *m_pdisplayfont; //font for fps display text
	SDL_Color m_displaytextcolor; //font color for fps display text
	SDL_Surface *m_pdisplaytext; //surface for fps display text
};

#endif

/*
EXAMPLE USAGE
NOTE: lazy.ttf needs to be in ../fonts/ and UpdateDisplay() requires SDL

int main()
{
	FrameControl FrameController(30); //instantiation, parameter is desired fps cap
	FrameController.m_averagefps.Start(); //starts timer required to calculate average fps

	while (true) //main loop
	{
		FrameController.m_fpslimiter.Start(); //starts timer required for fps cap
//events
//logic
//rendering
		FrameController.UpdateDisplay(FrameController.m_averagefps.GetTime(), Screen); //first parameter is timer for average fps, second is a pointer to your SDL surface screen
//fps
		FrameController.LimitFPS(FrameController.m_fpslimiter.GetTime()); //function to limit fps to defined cap, parameter is timer for fps cap
	}

	return 0;
}
*/
