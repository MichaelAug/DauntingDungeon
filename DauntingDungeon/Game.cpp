#include "Engine.h"
#include "FPSCounter.h"
int main() {

	std::unique_ptr<Engine>engine = std::make_unique<Engine>();

	FPSCounter fps;

	engine->Initialise("Daunting Dungeon", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1440, 900, false);

	fps.Init();

	while (engine->Running()) {
		fps.FrameStart(); // for FPS limiting
		fps.Count(); // counts fps

		engine->Update(std::to_string(fps.GetFPS()), fps.GetDeltaTime());
		engine->Render();

		fps.Limit(); //limits FPS to 60
		fps.FrameEnd(); // counts deltaTime
	}

	engine->ExitGame();

	return 0;
}