#pragma once
#include "SDL.h"
#include <vector>
#include "PlayerObject.h"

class CollisionManager {
public:
	static bool Collided(const SDL_Rect &a, const SDL_Rect &b);
	void HandlePlayerMapCollision(SDL_Rect &playerRect, std::vector<SDL_Rect>, Vector2 &playerVel);
};