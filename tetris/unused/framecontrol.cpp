#include <sstream>
#include "timer.h"
#include "framecontrol.h"

FrameControl::FrameControl(int fpscap)
{
	m_fpscap = fpscap; //fps limit
	m_framecount = 1; //frame count
	m_currentfps = 0; //frames/sec
	m_beginningframe = 1; //start frame for frames/sec
	m_framestate = false; //frame state switch for frames/sec

	m_pdisplayfont = TTF_OpenFont("fonts/lazy.ttf", 14); //font
	SDL_Color m_displaytextcolor = {255, 255, 255}; //set font color

	m_currentframesecond.Start(); //start display refresh counter
}

void FrameControl::LimitFPS(int time)
{
	if (time < (1000 / m_fpscap)) //if this frame went faster than the fps cap
	{
		//sleep until time syncs
		SDL_Delay((1000 / m_fpscap) - time);
	}
	m_framecount++; //move to next frame
}

void FrameControl::UpdateDisplay(int time, SDL_Surface *screen)
{
	if (m_framestate == true)
	{
		m_currentfps = (m_framecount - m_beginningframe);
		m_beginningframe = m_framecount;
		m_framestate = false;
	}
	
	if (m_currentframesecond.GetTime() > 1000) //every second
	{
		//feed fps to stringstream
		std::stringstream fpstext;
		fpstext << "current: " << m_currentfps << " average: " << (m_framecount / (time / 1000));

		//blit stringstream to surface
		m_pdisplaytext = TTF_RenderText_Solid(m_pdisplayfont, fpstext.str().c_str(), m_displaytextcolor);

		m_framestate = true; //reset frames/sec state
		m_currentframesecond.Start(); //restart frames/sec timer
	}

	if (m_averagefps.GetTime() > 1000)
	{
		SDL_BlitSurface(m_pdisplaytext, 0, screen, 0);
	}
}
