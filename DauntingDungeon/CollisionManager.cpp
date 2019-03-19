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
			//std::cout << "WALL HIT! Current pos: x="<<playerHitBox.x<<" y="<<playerHitBox.y<<" going back to: x="<<previousPlayerHitBox.x<<" y="<< previousPlayerHitBox.y << std::endl;
			playerHitBox = previousPlayerHitBox;
			playerDest = previousPlayerPos;
		}
		
	}
}

void CollisionManager::UpdatePreviousPlayerPos(SDL_Rect playerPos, SDL_Rect playerHitBox)
{
	if (previousPlayerPos.x != playerPos.x || previousPlayerPos.y != playerPos.y) {
		previousPlayerPos = playerPos;
		previousPlayerHitBox = playerHitBox;
		//std::cout << "Updated previous player position to x="<< playerPos.x << " y="<< playerPos.y<<" Hitbox to: x="<<playerHitBox.x << " y="<<playerHitBox.y << std::endl;
	}

}
