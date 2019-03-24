#include "Engine.h"
#include "GameObject.h"
#include "GameMap.h"

SDL_Renderer* Engine::renderer = nullptr;

Engine::Engine() : window(nullptr, SDL_DestroyWindow) {
	//don't need to initialise unique_ptr because it's null by default
}

void Engine::Initialise(std::string title, int x, int y, int width, int height, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING)) {
		isRunning = false;

		std::cout << "Error Initialising Game!" << std::endl;
		return;
	}
	else { std::cout << "Game Initialised Successfully!" << std::endl; }
	
	if (TTF_Init() == -1) { printf("Unable to initialise TTF! SDL_ttf Error: %s\n", TTF_GetError()); }
	else { printf("TTF_Initialised!\n"); }

	window.reset(SDL_CreateWindow(title.c_str(), x, y, width, height, fullscreen));
	if (window) { std::cout << "Window Created Successfully!" << std::endl; }

	renderer = SDL_CreateRenderer(window.get(), -1, 0);
	if (renderer) { std::cout << "Renderer Created Successfully!" << std::endl; }

	SDL_RenderSetLogicalSize(renderer, 960, 640);

	isRunning = true;

	objManager = std::make_unique<ObjectManager>();
	map = std::make_unique<GameMap>();
	player = std::make_unique<PlayerObject>("Assets/man.png", Vector2(32, 48));
	collider = std::make_unique<CollisionManager>(player->destRect);
	map->LoadMap(*collider);
	inputManager = std::make_unique<InputManager>();
	ui = std::make_unique<UIManager>();
}

void Engine::HandleEvents()
{
	inputManager->HandleInput(isRunning, player->velocity); 

	//std::cout << "Player center point: x=" << player->centerPoint.x << " y="<<player->centerPoint.y<< std::endl;
}

void Engine::Update(std::string fps)
{
	ui->UpdateFPS(fps);
	player->Update(); //update player pos
}

void Engine::Render()
{
	SDL_RenderClear(renderer);
	map->DrawMap();
	SDL_SetRenderDrawColor(renderer, 25, 0, 25, 255);

	player->Render();
	ui->DrawFPS();
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


