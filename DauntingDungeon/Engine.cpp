#include "Engine.h"
#include "GameObject.h"
#include "GameMap.h"


SDL_Renderer* Engine::renderer = nullptr;


Engine::Engine() {
	player = nullptr;
	objManager = nullptr;
	map = nullptr;
}

Engine::~Engine() {
	delete objManager;
	delete map;
	delete player;
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
	player = new PlayerObject("Assets/man.png", 32, 48);
}

void Engine::HandleEvents()
{
	SDL_Rect playerRect = player->GetHitBoxRect();
	std::vector<SDL_Rect> tiles = map->GetCollidableTiles();
	inputManager.HandleInput(isRunning, player->velocity);
	collider.HandlePlayerMapCollision(playerRect,tiles, player->velocity);
}

void Engine::Update()
{
	player->Update();
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
	SDL_DestroyWindow(window);
	SDL_Quit();
	std::cout << "Game Exited" << std::endl;
}


