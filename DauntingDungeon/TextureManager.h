#pragma once
#include "SDL_image.h"


class TextureManager {
public:
	static SDL_Texture* GetTexture(const char* fileName); //make unique
	static void Draw(SDL_Texture* tex, SDL_Rect src, const SDL_Rect &dest);
};