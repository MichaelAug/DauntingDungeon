#pragma once
#include "SDL.h"
#include <vector>
#include "PlayerObject.h"
#include "Collidable.h"
#include <memory>

class CollisionManager {
public:
	CollisionManager() {}
	CollisionManager(SDL_Rect playerPos);
	

	void AddTerrainCollider(std::shared_ptr<Collidable> col);

	std::vector<std::shared_ptr<Collidable>> terrain;
private:
	//std::vector<collision*> collisions;
	
};