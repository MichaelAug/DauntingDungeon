#include "Engine.h"
#include "FPSCounter.h"
int main(int argc, char *argv[]) {

	Engine *engine = new Engine();

	FPSCounter fps;

	engine->Initialise("My Game!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1440, 810, false);

	fps.Init();

	while (engine->Running()) {

		fps.FrameStart(); // for FPS limiting

		fps.Count(); // counts and prints fps to console

		engine->HandleEvents();
		engine->Update();
		engine->Render();

		fps.Limit(); //limits FPS to 60
	}

	engine->ExitGame();

	return 0;
}