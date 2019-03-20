#pragma once
#include "SDL_image.h"
#include <memory>

class TextureManager {
public:
	static std::unique_ptr<SDL_Texture, void(*)(SDL_Texture*)>GetTexture(const char* fileName);
	static void Draw(SDL_Texture* tex, SDL_Rect src, const SDL_Rect &dest);
};