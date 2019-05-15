#define SDL_MAIN_HANDLED

#include "Engine.h"
#include "FPSCounter.h"

/*NOTE: THE CODE IN THIS PROJECT IS VERY RUSHED, IN NEED OF A LOT OF REFACTORING AND IS NOT REPRESENTATIVE OF MY USUAL WORK*/

int main() {
	std::cout << "hi mark\n";
	auto engine = std::make_unique<Engine>();

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