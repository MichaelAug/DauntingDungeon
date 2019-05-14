#pragma once
#include "SDL.h"
#include "ObjectManager.h"
#include "GameManager.h"
class AudioManager;
class InputManager {
public:
	InputManager();
	void HandleInput(bool &isRunning, GameManager &g, AudioManager& audio);
private:
	SDL_Event event;
	Uint32 shotTime;
	float shootSpeed;
};