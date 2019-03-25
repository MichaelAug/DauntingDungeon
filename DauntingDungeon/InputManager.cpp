#include "InputManager.h"
#include "Projectile.h"


InputManager::InputManager()
{
}

void InputManager::HandleInput(bool &isRunning, PlayerObject &player, GameManager &g)
{
	SDL_PollEvent(&event);

	const Uint8* keyState = SDL_GetKeyboardState(NULL);


	float x = static_cast<float>(keyState[SDL_SCANCODE_D] - keyState[SDL_SCANCODE_A]);
	float y = static_cast<float>(keyState[SDL_SCANCODE_S] - keyState[SDL_SCANCODE_W]);

	Vector2 direction = Vector2(x, y);

	player.AddForce(Vector2(x, y));

	if (event.type == SDL_KEYDOWN) {
		switch (event.key.keysym.sym) {
		case SDLK_ESCAPE:
			isRunning = false;
			break;
		case SDLK_SPACE:
			Projectile *p = new Projectile("Assets/projectile.png", player.position, direction);
			g.AddProjectile(direction, p);
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
