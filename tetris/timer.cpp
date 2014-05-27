#include "timer.h"
#include "SDL/SDL.h"
Timer::Timer()
{
	m_starttime = 0;
	m_started = false;
}

void Timer::Start()
{
	//change state flag
	m_started = true;

	//set start time
	m_starttime = SDL_GetTicks();
}

void Timer::Stop()
{
	//change state flag
	m_started = false;
}

int Timer::GetTime()
{
	if (m_started) //if timer is running
	{
		return (SDL_GetTicks() - m_starttime); //return current time
	}
	else
	{
		return 0;
	}
}
