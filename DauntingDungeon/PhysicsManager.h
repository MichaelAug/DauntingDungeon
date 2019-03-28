#pragma once
#include <vector>
#include <memory>
#include "GameObject.h"
#include "CollisionManager.h"

class PhysicsManager {
public:
	PhysicsManager();

	void UpdatePhysics(Uint32 dt,std::vector<GameObject*>& allObjects,
		std::vector<std::shared_ptr<Collidable>> &terrain);

	void ResetForces(std::vector<GameObject*>& allObjects);

	void AddToAllObjects(GameObject* b);

protected:
	void Integration(float dt, std::vector<GameObject*>& allObjects);
	void IntegrateVelocity(float dt, std::vector<GameObject*>& allObjects);

	std::unique_ptr<CollisionManager> colManager;
};