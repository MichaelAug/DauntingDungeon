#pragma once
#include "SDL.h"
#include "ObjectManager.h"
#include "GameManager.h"

class InputManager {
public:
	InputManager();
	void HandleInput(bool &isRunning, GameManager &g);
private:
	SDL_Event event;
	Uint32 shotTime;
	float shootSpeed;
};