#pragma once
#include <vector>
#include "UILabel.h"
#include <SDL_ttf.h>

class UIManager {
public:
	UIManager();

	void UpdateFPS(std::string msg);
	void UpdateScore(std::string msg);
	void DrawUI(int heart);
private:
	UILabel fps;
	UILabel score;

	SDL_Texture* healthHeart;
	SDL_Rect healthSrcRect;
	SDL_Rect heatlhDestRect;
	int heartDistance;
};