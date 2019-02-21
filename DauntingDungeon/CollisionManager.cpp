#include "CollisionManager.h"

#include <iostream>

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

void CollisionManager::HandlePlayerMapCollision(SDL_Rect & playerRect, std::vector<SDL_Rect> walls, Vector2 &playerVel)
{
	for (auto& t : walls) {
		if (Collided(playerRect, t)) {
			playerVel.x *= -1;
			playerVel.y *= -1;
			std::cout << "WALL HIT!" << std::endl;
		}
	}
}
