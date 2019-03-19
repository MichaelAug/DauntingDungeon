#pragma once
#include "SDL.h"

class GameObject {
public:
	GameObject(const char* textureName, int x, int y);
	~GameObject();

	virtual void Update();
	void Render();

protected:

	SDL_Texture *objTexture; //make unique
	SDL_Rect srcRect, destRect;
};