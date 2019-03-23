#include "FPSCounter.h"
#include <iostream>

FPSCounter::FPSCounter() : frames(0) {}

void FPSCounter::Init()
{
	secondStart = SDL_GetTicks();
}

void FPSCounter::Limit()
{
	frameTime = SDL_GetTicks() - frameStart;
	if (FRAME_DELAY > frameTime) {
		SDL_Delay(FRAME_DELAY - frameTime);
	}
}

void FPSCounter::Count()
{
	if ((SDL_GetTicks() - secondStart) >= 1000) {
		std::cout << "FPS: " << frames << std::endl;
		frames = 0;
		secondStart = SDL_GetTicks();
	}
	frames++;
}

void FPSCounter::FrameStart()
{
	frameStart = SDL_GetTicks();
}
