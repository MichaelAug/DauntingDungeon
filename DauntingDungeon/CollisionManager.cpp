#include "CollisionManager.h"
#include <iostream>

CollisionManager::CollisionManager(SDL_Rect playerPos)
{
}

void CollisionManager::AddTerrainCollider(std::shared_ptr<Collidable> col)
{
	terrain.emplace_back(col);
}
