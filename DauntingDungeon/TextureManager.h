#pragma once
#include "SDL_image.h"

class TextureManager {
public:
	static SDL_Texture* GetTexture(const char* fileName, SDL_Renderer* renderer);
private:
	
};