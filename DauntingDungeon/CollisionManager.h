#pragma once
#include "SDL.h"
#include <vector>
#include "PlayerObject.h"

class CollisionManager {
public:
	CollisionManager() {}
	CollisionManager(SDL_Rect playerPos, std::vector<SDL_Rect> collidableTiles);
	static bool Collided(const SDL_Rect &a, const SDL_Rect &b);
	void HandlePlayerMapCollision(SDL_Rect &playerRect, Vector2 &playerVel);
	void UpdatePreviousPlayerPos(SDL_Rect);

private:
	SDL_Rect previousPlayerPos;
	std::vector<SDL_Rect> tiles;
};