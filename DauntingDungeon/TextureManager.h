#pragma once
#include "SDL_image.h"

class TextureManager {
public:
	SDL_Texture* GetPlayerTex();
	void SetPlayerTex(SDL_Renderer *renderer, SDL_Surface *surface);
private:
	SDL_Texture* playerTex;
};