#pragma once
#include <vector>
#include "SDL2/SDL.h"
#include <string>
#include "SDL2/SDL_ttf.h"
#include <memory>

class UILabel {
	friend class UIManager;
public:
	UILabel();
	UILabel(std::string fontName, int fontSize, SDL_Rect, SDL_Color col, std::string message);
	void Draw();
	void UpdateMessage(std::string msg);
private:
	std::unique_ptr<TTF_Font, void(*)(TTF_Font*)> font;
	SDL_Rect position;
	SDL_Color colour;
	std::string text;

};