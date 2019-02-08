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

		SDL_Surface *surface = IMG_Load("Assets/03zx13.png");

		if (!surface) {
			std::cout << IMG_GetError() << std::endl;
		}
		//playerTex = SDL_CreateTextureFromSurface(renderer, surface);
		texManager.SetPlayerTex(renderer, surface);
		SDL_FreeSurface(surface);
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
	
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderCopy(renderer, texManager.GetPlayerTex(), NULL, NULL);
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
