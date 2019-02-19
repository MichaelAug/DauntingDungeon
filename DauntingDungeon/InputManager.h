#pragma once
#include "SDL.h"
#include "ObjectManager.h"

class InputManager {
public:
	InputManager();
	void HandleInput(bool &isRunning, PlayerObject *player);
private:
	SDL_Event event;
};