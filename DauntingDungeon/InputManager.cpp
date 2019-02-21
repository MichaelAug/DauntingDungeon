#include "InputManager.h"


InputManager::InputManager()
{
}

void InputManager::HandleInput(bool &isRunning, Vector2 &playerVel)
{
	SDL_PollEvent(&event);

	const Uint8* keyState = SDL_GetKeyboardState(NULL);
	playerVel.x = keyState[SDL_SCANCODE_D] - keyState[SDL_SCANCODE_A];
	playerVel.y = keyState[SDL_SCANCODE_S] - keyState[SDL_SCANCODE_W];

	if (event.type == SDL_KEYDOWN) {
		switch (event.key.keysym.sym) {
		case SDLK_ESCAPE:
			isRunning = false;
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
