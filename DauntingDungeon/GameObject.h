#pragma once
#include "SDL.h"

class GameObject {
public:
	GameObject(const char* textureName, int x, int y);

	virtual void Update();
	void Render();

protected:
	int xpos;
	int ypos;

	SDL_Texture *objTexture;
	SDL_Rect srcRect, destRect;
};