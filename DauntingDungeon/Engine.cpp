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
		IsRunning = false;

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

	IsRunning = true;

	objManager = new ObjectManager();
	map = new GameMap();
}

void Engine::HandleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	if (event.type == SDL_KEYDOWN) {
		switch (event.key.keysym.sym) {
		case SDLK_ESCAPE:
			IsRunning = false;
			break;
		case SDLK_w:
			objManager->UpdatePlayer(0, -1);
			break;
		case SDLK_a:
			objManager->UpdatePlayer(-1, 0);
			break;
		case SDLK_s:
			objManager->UpdatePlayer(0, 1);
			break;
		case SDLK_d:
			objManager->UpdatePlayer(1, 0);
			break;
		}
	}

	switch (event.type) {
	case SDL_QUIT:
		IsRunning = false;
		break;
	default:
		break;
	}
}

void Engine::Update()
{
}

void Engine::Render()
{
	SDL_RenderClear(renderer);
	map->DrawMap();
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

	objManager->RenderPlayer();
	SDL_RenderPresent(renderer);
}

bool Engine::Running()
{
	return IsRunning;
}

void Engine::ExitGame()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	std::cout << "Game Exited" << std::endl;
}


