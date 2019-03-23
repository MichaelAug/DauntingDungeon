#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include "TextureManager.h"
#include "ObjectManager.h"
#include "GameMap.h"
#include "InputManager.h"
#include "CollisionManager.h"
#include <memory>
#include "UIManager.h"

class Engine {
public:
	Engine();

	void Initialise(std::string title, int x, int y, int width, int height, bool fullscreen);
	void HandleEvents();
	void Render();
	bool Running();
	void ExitGame();
	void Update(std::string fps);
	static SDL_Renderer* renderer;
private:
	std::unique_ptr<SDL_Window, void(*)(SDL_Window*)> window; // need to pass in a custom deleter because need to call SDL_DestroyWindow
	bool isRunning;

	std::unique_ptr<ObjectManager> objManager;
	std::unique_ptr<PlayerObject> player; 
	std::unique_ptr<GameMap> map;
	std::unique_ptr<InputManager> inputManager;
	std::unique_ptr<CollisionManager> collider;
	std::unique_ptr<UIManager> ui;
};