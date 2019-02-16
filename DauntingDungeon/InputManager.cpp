#include "InputManager.h"


InputManager::InputManager()
{
}

void InputManager::HandleInput(bool &isRunning, ObjectManager *objManager)
{
	SDL_PollEvent(&event);

	if (event.type == SDL_KEYDOWN) {
		switch (event.key.keysym.sym) {
		case SDLK_ESCAPE:
			isRunning = false;
			break;
		case SDLK_w:
			objManager->UpdatePlayerVelY(-1);
			break;
		case SDLK_a:
			objManager->UpdatePlayerVelX(-1);
			break;
		case SDLK_s:
			objManager->UpdatePlayerVelY(1);
			break;
		case SDLK_d:
			objManager->UpdatePlayerVelX(1);
			break;
		}
	}
	if (event.type == SDL_KEYUP) {
		switch (event.key.keysym.sym) {
		case SDLK_ESCAPE:
			isRunning = false;
			break;
		case SDLK_w:
			objManager->UpdatePlayerVelY(0);
			break;
		case SDLK_a:
			objManager->UpdatePlayerVelX(0);
			break;
		case SDLK_s:
			objManager->UpdatePlayerVelY(0);
			break;
		case SDLK_d:
			objManager->UpdatePlayerVelX(0);
			break;
		}
	}

	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}
