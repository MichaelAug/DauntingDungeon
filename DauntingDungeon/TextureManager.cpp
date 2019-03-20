#include "TextureManager.h"
#include <iostream>
#include "Engine.h"

std::unique_ptr<SDL_Texture, void(*)(SDL_Texture*)> TextureManager::GetTexture(const char * fileName)
{
	SDL_Surface *surface = IMG_Load(fileName);

	if (!surface) {
		std::cout << IMG_GetError() << std::endl;
	}

	std::unique_ptr<SDL_Texture, void(*)(SDL_Texture*)> tex(SDL_CreateTextureFromSurface(Engine::renderer, surface),
		SDL_DestroyTexture);
	SDL_FreeSurface(surface);
	return std::move(tex);
}

void TextureManager::Draw(SDL_Texture * tex, SDL_Rect src, const SDL_Rect &dest)
{
	SDL_RenderCopy(Engine::renderer, tex, &src, &dest);
}