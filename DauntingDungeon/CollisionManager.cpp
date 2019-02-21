#include "CollisionManager.h"

#include <iostream>

CollisionManager::CollisionManager(SDL_Rect playerPos, std::vector<SDL_Rect> collidableTiles)
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

void CollisionManager::HandlePlayerMapCollision(SDL_Rect &playerRect, Vector2 &playerVel)
{
	/*A more precise version of the SDL_Rect that represents the player hit-box
	(needed because of the texture having a lot of empty space)*/
	SDL_Rect playerHitBox = playerRect;
	playerHitBox.x += 20;
	playerHitBox.w -= 35;

	playerHitBox.y += 20;
	playerHitBox.h -= 42;


	for (auto& t : tiles) {
		if (Collided(playerHitBox, t)) {
			

			std::cout << "WALL HIT! Current pos: x="<<playerRect.x<<" y="<<playerRect.y<<" going back to: x="<<previousPlayerPos.x<<" y="<<previousPlayerPos.y << std::endl;
			playerRect = previousPlayerPos;
		}
	}
}

void CollisionManager::UpdatePreviousPlayerPos(SDL_Rect ppp)
{
	if (previousPlayerPos.x != ppp.x || previousPlayerPos.y != ppp.y) {
		previousPlayerPos = ppp;
		std::cout << "Updated previous player position! to x="<<ppp.x << " y="<<ppp.y << std::endl;
	}
	
}
