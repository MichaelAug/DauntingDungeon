#pragma once
#include <vector>
#include <memory>
#include "GameObject.h"
#include "CollisionManager.h"

class PhysicsManager {
public:
	PhysicsManager();

	//void FixedUpdate(float dt); maybe add later? 
	void UpdatePhysics(float dt);

	void ResetForces();

	void AddGameObject(GameObject* b);
	void RemoveGameObject(std::shared_ptr<GameObject> b);

	CollisionManager& GetCollisionManager() { return *collider; }
protected:
	std::unique_ptr<CollisionManager> collider;
	void Integration(float dt);
	void IntegrateVelocity(float dt);
};