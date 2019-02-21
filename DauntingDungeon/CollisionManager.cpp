#include "CollisionManager.h"

#include <iostream>

CollisionManager::CollisionManager(SDL_Rect playerPos, std::vector<Collidable> collidableTiles)
{
	previousPlayerPos = playerPos;
	tiles = collidableTiles;
}

bool CollisionManager::Collided(const SDL_Rect & a, const SDL_Rect & b)
{
	if (a.x + a.w >= b.x &&
		b.x + b.w >= a.x &&
		a.y + a.h >= b.y &&
		b.y + b.h >= a.y) {
		return true;
	}
	return false;
}

void CollisionManager::HandlePlayerMapCollision(SDL_Rect &playerHitBox, SDL_Rect &playerDest)
{
	Vector2 difference;
	for (auto& t : tiles) {
		if (Collided(playerHitBox, t.GetHitBox())) {

			//difference = 
			std::cout << "WALL HIT! Current pos: x="<<playerHitBox.x<<" y="<<playerHitBox.y<<" going back to: x="<<previousPlayerPos.x<<" y="<<previousPlayerPos.y << std::endl;
			playerHitBox = previousPlayerPos;
			playerDest = previousPlayerPos;
		}
	}
}

void CollisionManager::UpdatePreviousPlayerPos(SDL_Rect ppp)
{
	if (previousPlayerPos.x != ppp.x || previousPlayerPos.y != ppp.y) {
		previousPlayerPos = ppp;
		//std::cout << "Updated previous player position to x="<<ppp.x << " y="<<ppp.y << std::endl;
	}
	
}
