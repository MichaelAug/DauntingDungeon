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
	static SDL_Renderer* renderer;
private:
	SDL_Window *window;
	bool IsRunning;
};