#include "Engine.h"

int main(int argc, char *argv[]) {
	Engine *engine = new Engine();

	engine->Initialise("My Game!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 900, 800, false);

	while (engine->Running()) {
		engine->HandleEvents();
		engine->Render();
	}

	engine->ExitGame();

	return 0;
}