#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include "TextureManager.h"
#include "ObjectManager.h"
#include "GameMap.h"

class Engine {
public:
	Engine();
	~Engine();

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
	ObjectManager* objManager;
	GameMap* map;
};