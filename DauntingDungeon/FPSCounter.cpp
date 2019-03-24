#include "FPSCounter.h"
#include <iostream>

FPSCounter::FPSCounter() : frames(0) {}

void FPSCounter::Init()
{
	frameEnd = 0;
	fps = 0;
	secondStart = SDL_GetTicks();
	frameStart = 0;
}

void FPSCounter::Limit()
{
	frameTime = SDL_GetTicks() - frameStart;
	if (FRAME_DELAY >= frameTime) {
		SDL_Delay(FRAME_DELAY - frameTime);
	}
}

void FPSCounter::Count()
{
	if ((SDL_GetTicks() - secondStart) >= 1000) {
		secondStart = SDL_GetTicks();
		fps = frames;
		frames = 0;
	}
	frames++;
}

void FPSCounter::FrameStart()
{
	frameStart = SDL_GetTicks();
}

int FPSCounter::GetFPS()
{
	return fps;
}

void FPSCounter::FrameEnd()
{
	frameEnd = SDL_GetTicks() - frameStart;
}

Uint32 FPSCounter::GetDeltaTime()
{
	return frameEnd;
}
