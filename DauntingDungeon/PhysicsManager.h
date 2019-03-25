#pragma once
#include <vector>
#include <memory>
#include "GameObject.h"
#include "CollisionManager.h"

class PhysicsManager {
public:
	PhysicsManager();

	void UpdatePhysics(float dt);

	void ResetForces();

	void AddToAllObjects(GameObject* b);
	void RemoveGameObject(std::shared_ptr<GameObject> b);

	CollisionManager& GetCollisionManager() { return *colManager; }
protected:
	std::unique_ptr<CollisionManager> colManager;
	void Integration(float dt);
	void IntegrateVelocity(float dt);
};