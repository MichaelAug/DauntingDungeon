#include "Engine.h"
#include "GameObject.h"
#include "GameMap.h"

SDL_Renderer* Engine::renderer = nullptr;

Engine::Engine() : window(nullptr, SDL_DestroyWindow) {
	//don't need to initialise unique_ptr because it's null by default
}

void Engine::Initialise(const char * title, int x, int y, int width, int height, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING)) {
		isRunning = false;

		std::cout << "Error Initialising Game!" << std::endl;
		return;
	}

	std::cout << "Game Initialised Successfully!" << std::endl;

	window.reset(SDL_CreateWindow(title, x, y, width, height, fullscreen));
	if (window) {
		std::cout << "Window Created Successfully!" << std::endl;
	}

	renderer = SDL_CreateRenderer(window.get(), -1, 0);
	if (renderer) {
		std::cout << "Renderer Created Successfully!" << std::endl;
	}

	SDL_RenderSetLogicalSize(renderer, 960, 640);

	isRunning = true;

	objManager = std::make_unique<ObjectManager>();
	map = std::make_unique<GameMap>();
	player = std::make_unique<PlayerObject>("Assets/man.png", 32, 48);
	collider = std::make_unique<CollisionManager>(player->destRect, map->GetCollidableTiles());
	inputManager = std::make_unique<InputManager>();
}

void Engine::HandleEvents()
{
	inputManager->HandleInput(isRunning, player->velocity); 

	collider->HandlePlayerMapCollision(player->hitbox, player->destRect);

	//std::cout << "Player center point: x=" << player->centerPoint.x << " y="<<player->centerPoint.y<< std::endl;
}

void Engine::Update()
{
	collider->UpdatePreviousPlayerPos(player->destRect, player->hitbox); //get previous player pos

	player->Update(); //update player pos
}

void Engine::Render()
{
	SDL_RenderClear(renderer);
	map->DrawMap();
	SDL_SetRenderDrawColor(renderer, 25, 0, 25, 255);

	player->Render();
	SDL_RenderPresent(renderer);
}

bool Engine::Running()
{
	return isRunning;
}

void Engine::ExitGame()
{
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Exited" << std::endl;
}


