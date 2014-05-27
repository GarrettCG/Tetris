#include "timestepper.h"
#include "SDL/SDL.h"
Timestepper::Timestepper()//default constructor
{
	frequency=1;
	timer = SDL_GetTicks();
} 
Timestepper::Timestepper(int freq)//constructor
{
	frequency=freq;
	timer = SDL_GetTicks();
	nextstep=freq;
}
bool Timestepper::update()
{
	if (timer>=nextstep)
	{
		nextstep=nextstep+frequency;
		return true;
	}
	else
	{
		timer=SDL_GetTicks();
		return false;
	}
}
void Timestepper::ChangeFrequency(int freq)
{
	frequency=freq;
}
int Timestepper::GetFrequency()
{
	return frequency;
}
void Timestepper::reset()
{
	timer=SDL_GetTicks();
	nextstep=timer+frequency;
}
void Timestepper::Pause()
{
	timer=SDL_GetTicks();
	paused = nextstep-timer;//this could be negative but that's ok since it's an int
}
void Timestepper::UnPause()//you should call update immediately after calling this
{
	timer=SDL_GetTicks();
	nextstep=timer+paused;
}
