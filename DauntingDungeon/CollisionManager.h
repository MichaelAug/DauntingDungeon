#pragma once
#include "SDL.h"
#include <vector>

class CollisionManager {
public:
	static bool Collided(const SDL_Rect &a, const SDL_Rect &b);
	void HandlePlayerMapCollision(SDL_Rect &player, std::vector<SDL_Rect>);
};