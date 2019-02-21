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

void CollisionManager::HandlePlayerMapCollision(SDL_Rect & playerRect, std::vector<SDL_Rect> walls, PlayerObject &player)
{
	for (auto& t : walls) {
		if (Collided(playerRect, t)) {
			player.velocity.x *= -1;
			player.velocity.y *= -1;
			std::cout << "WALL HIT!" << std::endl;
		}
	}
}
