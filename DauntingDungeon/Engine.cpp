#include "Engine.h"

Engine::Engine() {
}

Engine::~Engine() {
}

void Engine::Initialise(const char * title, int x, int y, int width, int height, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Game Initialised Successfully!" << std::endl;

		window = SDL_CreateWindow(title, x, y, width, height, fullscreen);
		if (window) {
			std::cout << "Window Created Successfully!" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			std::cout << "Renderer Created Successfully!" << std::endl;
		}

		IsRunning = true;
	}
	else {
		IsRunning = false;

		std::cout << "Error Initialising Game!" << std::endl;
	}
}

void Engine::HandleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type) {
	case SDL_QUIT:
		IsRunning = false;
		break;
	default:
		break;
	}
}

void Engine::Render()
{
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
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
