#pragma once
#include <vector>
#include "UILabel.h"
#include <SDL_ttf.h>

class UIManager {
public:
	UIManager();

	void UpdateFPS(std::string msg);
	void DrawFPS();
private:
	UILabel fps;
};