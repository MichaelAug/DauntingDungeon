#include "TextureManager.h"

SDL_Texture * TextureManager::GetPlayerTex()
{
	return playerTex;
}

void TextureManager::SetPlayerTex(SDL_Renderer * renderer, SDL_Surface * surface)
{
	playerTex = SDL_CreateTextureFromSurface(renderer, surface);
}
