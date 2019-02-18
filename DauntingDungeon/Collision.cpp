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

void CollisionManager::HandlePlayerMapCollision(SDL_Rect & player, std::vector<SDL_Rect> walls)
{
	for (auto& t : walls) {
		if (Collided(player, t)) {
			std::cout << "WALL HIT!" << std::endl;
		}
	}
}
