#include "Engine.h"
#include "GameObject.h"
#include "GameMap.h"


SDL_Renderer* Engine::renderer = nullptr;


Engine::Engine() {
	objManager = nullptr;
	map = nullptr;
}

Engine::~Engine() {
	delete objManager;
	delete map;
}

void Engine::Initialise(const char * title, int x, int y, int width, int height, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING)) {
		isRunning = false;

		std::cout << "Error Initialising Game!" << std::endl;
		return;
	}

	std::cout << "Game Initialised Successfully!" << std::endl;

	window = SDL_CreateWindow(title, x, y, width, height, fullscreen);
	if (window) {
		std::cout << "Window Created Successfully!" << std::endl;
	}

	renderer = SDL_CreateRenderer(window, -1, 0);
	if (renderer) {
		std::cout << "Renderer Created Successfully!" << std::endl;
	}

	SDL_RenderSetLogicalSize(renderer, 960, 640);

	isRunning = true;

	objManager = new ObjectManager();
	map = new GameMap();
}

void Engine::HandleEvents()
{
	inputManager.HandleInput(isRunning, objManager);
}

void Engine::Update()
{
	objManager->UpdatePlayer();
}

void Engine::Render()
{
	SDL_RenderClear(renderer);
	map->DrawMap();
	SDL_SetRenderDrawColor(renderer, 25, 0, 25, 255);

	objManager->RenderPlayer();
	SDL_RenderPresent(renderer);
}

bool Engine::Running()
{
	return isRunning;
}

void Engine::ExitGame()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	std::cout << "Game Exited" << std::endl;
}


