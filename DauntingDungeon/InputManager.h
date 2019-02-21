#pragma once
#include "SDL.h"
#include "ObjectManager.h"

class InputManager {
public:
	InputManager();
	void HandleInput(bool &isRunning, Vector2 &playerVel);
private:
	SDL_Event event;
};