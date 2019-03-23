#pragma once
#include "SDL.h"
#include <memory>
#include <string>

class GameObject {
public:
	GameObject(const std::string textureName, int x, int y);
	~GameObject();
	virtual void Update();
	void Render();

protected:

	std::unique_ptr<SDL_Texture, void(*)(SDL_Texture*)> objTexture; //make unique
	SDL_Rect srcRect, destRect;
};