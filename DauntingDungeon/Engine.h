#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include "TextureManager.h"
#include "GameMap.h"
#include "InputManager.h"
#include <memory>
#include "UIManager.h"
#include "GameManager.h"

class Engine {
public:
	Engine();

	void Initialise(std::string title, int x, int y, int width, int height, bool fullscreen);
	void Render();
	bool Running();
	void ExitGame();
	void Update(std::string fps, Uint32 dt);
	static SDL_Renderer* renderer;
private:
	bool isRunning;
	std::unique_ptr<SDL_Window, void(*)(SDL_Window*)> window; // need to pass in a custom deleter because need to call SDL_DestroyWindow
	std::unique_ptr<GameMap> map;
	std::unique_ptr<InputManager> inputManager;
	std::unique_ptr<UIManager> ui;
	std::unique_ptr<GameManager> gameManager;
};