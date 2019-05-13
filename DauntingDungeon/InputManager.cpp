#include "InputManager.h"
#include "Projectile.h"


InputManager::InputManager()
{
}

void InputManager::HandleInput(bool &isRunning, GameManager &g)
{
	SDL_PollEvent(&event);

	const Uint8* keyState = SDL_GetKeyboardState(NULL);


	float x = static_cast<float>(keyState[SDL_SCANCODE_D] - keyState[SDL_SCANCODE_A]);
	float y = static_cast<float>(keyState[SDL_SCANCODE_S] - keyState[SDL_SCANCODE_W]);

	Vector2 direction = Vector2(x, y);
	direction.normalise();
	g.GetPlayer().AddForce(Vector2(x, y)*6);

	if (direction.x < 0) {
		g.GetPlayer().spriteFlip = SDL_FLIP_HORIZONTAL;
	}
	if (direction.x > 0) {
		g.GetPlayer().spriteFlip = SDL_FLIP_NONE;
	}

	if (direction != Vector2(0, 0)) {
		g.GetPlayer().SetMoving();
		g.GetPlayer().UpdateDirection(direction);
	}
	else {
		g.GetPlayer().SetIdle();
	}

	if (event.type == SDL_KEYDOWN) {
		switch (event.key.keysym.sym) {
		case SDLK_ESCAPE:
			isRunning = false;
			break;
		case SDLK_SPACE:
			g.AddProjectile(g.GetPlayer().GetDirection());
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
