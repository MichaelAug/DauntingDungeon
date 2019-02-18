#include "Engine.h"

int main(int argc, char *argv[]) {

	/*TODO: Create game setings class!!*/

	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;

	Engine *engine = new Engine();

	engine->Initialise("My Game!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1080, 720, false);

	while (engine->Running()) {

		frameStart = SDL_GetTicks(); // for FPS limiting

		engine->HandleEvents();
		engine->Update();
		engine->Render();

		// FPS limiting TODO: add a keypress to switch between limited and unlimited fps
		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime);
		}
		//---------------
	}

	engine->ExitGame();

	return 0;
}