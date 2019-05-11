#include "PhysicsManager.h"

PhysicsManager::PhysicsManager() : colManager(std::make_unique<CollisionManager>())
{
	timeRemaining = 0;
}

void PhysicsManager::FixedUpdate(Uint32 dt, std::vector<GameObject*>& allObjects,
	std::vector<GameObject*>& terrain)
{
	timeRemaining += dt;

	while (timeRemaining > subTimeDelta) {
		UpdatePhysics(subTimeDelta, allObjects, terrain);
		timeRemaining -= subTimeDelta;
	}
}

void PhysicsManager::UpdatePhysics(Uint32 dt, std::vector<GameObject*>& allObjects, 
	std::vector<GameObject*>& terrain)
{
	Integration(dt, allObjects);
	colManager->CollisionDetection(allObjects, terrain);
	colManager->HandleCollisionResolution();
	IntegrateVelocity(dt, allObjects);
	ResetForces(allObjects);
}

void PhysicsManager::ResetForces(std::vector<GameObject*>& allObjects)
{
	for (auto& b : allObjects) {
		b->force.ToZero();
	}
}

void PhysicsManager::Integration(float dt, std::vector<GameObject*>& allObjects)
{
	Vector2 acceleration;
	for (auto& b : allObjects) {
		acceleration = b->force * b->inverseMass;
		b->velocity += acceleration * dt;
		b->velocity *= 0.87f;
	}
}

void PhysicsManager::IntegrateVelocity(float dt, std::vector<GameObject*>& allObjects)
{
	for (auto& b : allObjects) {
		Vector2 posChange = b->velocity * dt;
		b->collider->pos += posChange;
		b->position += posChange;
	}
}
