#include "TextureManager.h"
#include <iostream>

SDL_Texture * TextureManager::GetTexture(const char * fileName, SDL_Renderer * renderer)
{
	SDL_Surface *surface = IMG_Load(fileName);

	if (!surface) {
		std::cout << IMG_GetError() << std::endl;
	}

	SDL_Texture *tex = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
	return tex;
}