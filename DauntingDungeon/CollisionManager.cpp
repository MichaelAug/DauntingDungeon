#include "CollisionManager.h"
#include <iostream>

void CollisionManager::Draw()
{
	for (auto& o : allObjects) {
		o->Render();
	}
}

void CollisionManager::AddTerrainCollider(std::shared_ptr<Collidable> col)
{
	terrain.emplace_back(col);
}
