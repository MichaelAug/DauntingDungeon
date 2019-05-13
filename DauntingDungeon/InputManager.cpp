#include "InputManager.h"
#include "Projectile.h"


InputManager::InputManager()
{
	shootSpeed = 300;
	shotTime = SDL_GetTicks();
}

void InputManager::HandleInput(bool& isRunning, GameManager& g)
{
	SDL_PollEvent(&event);

	const Uint8* keyState = SDL_GetKeyboardState(NULL);

	if (!g.GetPaused()) {
		float x = static_cast<float>(keyState[SDL_SCANCODE_D] - keyState[SDL_SCANCODE_A]);
		float y = static_cast<float>(keyState[SDL_SCANCODE_S] - keyState[SDL_SCANCODE_W]);
		Vector2 direction = Vector2(x, y);
		direction.normalise();

		g.GetPlayer().AddForce(Vector2(x, y) * 6);


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
	}
	if (event.type == SDL_KEYDOWN) {
		switch (event.key.keysym.sym) {
		case SDLK_ESCAPE:
			isRunning = false;
			break;
		case SDLK_SPACE:
			if (!g.GetPaused()) {
				if (SDL_GetTicks() - shotTime > shootSpeed) {
					g.AddProjectile(g.GetPlayer().GetDirection());
					shotTime = SDL_GetTicks();
				}
			}
			break;
		case SDLK_p:
			g.TogglePause();
			break;
		case SDLK_r:
			if (g.died) {
				g.RestartGame();
			}
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
