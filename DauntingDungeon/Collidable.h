#pragma once
#include "SDL.h"
#include "Vector2.h"

class Collidable {
public:
	Collidable() {};
	Collidable(SDL_Rect);
	void UpdateRectPos(SDL_Rect);
	SDL_Rect GetHitBox();

protected:
	SDL_Rect hitbox;

private:
};

