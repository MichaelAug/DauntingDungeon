#pragma once
#include "SDL.h"
#include <iostream>
class Engine {
public:
	Engine();
	~Engine();

	void Initialise(const char* title, int x, int y, int width, int height, bool fullscreen);
	void HandleEvents();
	void Render();
	bool Running();
	void ExitGame();

private:
	SDL_Window *window;
	SDL_Renderer *renderer;
	bool IsRunning;
};