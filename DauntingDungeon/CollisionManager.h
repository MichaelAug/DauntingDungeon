#pragma once
#include "SDL.h"
#include <vector>
#include "PlayerObject.h"
#include "Collidable.h"
#include <memory>

class CollisionManager {
	friend class PhysicsManager;
public:
	CollisionManager() {}
	void Draw();

	void AddTerrainCollider(std::shared_ptr<Collidable> col);
	std::vector<std::shared_ptr<Collidable>> terrain;
private:
	
	std::vector<GameObject*> allObjects;
};