#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include "TextureManager.h"
class Engine {
public:
	Engine();
	~Engine();

	/*TODO: remove these*/
	int counter;
	SDL_Rect dest;

	void Initialise(const char* title, int x, int y, int width, int height, bool fullscreen);
	void HandleEvents();
	void Render();
	bool Running();
	void ExitGame();
	void Update();

private:
	SDL_Window *window;
	SDL_Renderer *renderer;
	bool IsRunning;
	TextureManager texManager;
};