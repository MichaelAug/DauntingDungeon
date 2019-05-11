#pragma once
#include "SDL_image.h"
#include <memory>

class TextureManager {
public:
	static SDL_Texture* GetTexture(const char* fileName);
	static void Draw(SDL_Texture* tex, SDL_Rect src, const SDL_Rect &dest);
};