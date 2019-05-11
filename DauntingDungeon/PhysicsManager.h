#pragma once
#include <vector>
#include <memory>
#include "GameObject.h"
#include "CollisionManager.h"
#include "CollisionEffects.h"

class PhysicsManager {
public:
	PhysicsManager();

	void FixedUpdate(Uint32 dt, std::vector<GameObject*>& allObjects,
		std::vector<GameObject*> &terrain);

	void UpdatePhysics(Uint32 dt,std::vector<GameObject*>& allObjects,
		std::vector<GameObject*>& terrain);

	void ResetForces(std::vector<GameObject*>& allObjects);

	void AddToAllObjects(GameObject* b);

protected:
	void Integration(float dt, std::vector<GameObject*>& allObjects);
	void IntegrateVelocity(float dt, std::vector<GameObject*>& allObjects);

	std::unique_ptr<CollisionManager> colManager;
	Uint32 timeRemaining;
	const Uint32 subTimeDelta = 8; //1000/120 = 8ms
};