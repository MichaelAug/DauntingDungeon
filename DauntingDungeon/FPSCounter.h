#pragma once
#include "SDL.h"

class FPSCounter {
public:
	FPSCounter();
	void Init();
	void Limit();
	void Count();
	void FrameStart();

private:
	Uint32 frameStart, frameTime, secondStart;
	const int FPS = 60;
	const int FRAME_DELAY = 1000 / FPS;
	int frames;
};