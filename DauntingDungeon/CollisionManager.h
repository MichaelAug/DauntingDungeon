#pragma once
#include "SDL.h"
#include <vector>
#include "PlayerObject.h"
#include "Collidable.h"

class CollisionManager {
public:
	CollisionManager() {}
	CollisionManager(SDL_Rect playerPos, std::vector<Collidable> collidableTiles);
	static bool Collided(const SDL_Rect &a, const SDL_Rect &b);
	void HandlePlayerMapCollision(SDL_Rect &playerHitBox, SDL_Rect &playerDest);
	void UpdatePreviousPlayerPos(SDL_Rect playerPos, SDL_Rect playerHitBox);

private:
	SDL_Rect previousPlayerPos;
	SDL_Rect previousPlayerHitBox;
	std::vector<Collidable> tiles;
};