#include "PhysicsManager.h"

PhysicsManager::PhysicsManager()
{
	colManager = std::make_unique<CollisionManager>();
}

void PhysicsManager::UpdatePhysics(float dt)
{
	Integration(dt);
	colManager->CollisionDetection(colManager->allObjects);  //refactor this monstrosity
	colManager->HandleCollisionResolution();
	IntegrateVelocity(dt);
	ResetForces();
}

void PhysicsManager::ResetForces()
{
	for (auto& b : colManager->allObjects) {
		b->force.ToZero();
	}
}

void PhysicsManager::AddToAllObjects(GameObject* b)
{
	colManager->allObjects.emplace_back(b);
}

void PhysicsManager::Integration(float dt)
{
	Vector2 acceleration;
	for (auto& b : colManager->allObjects) {
		b->UpdateObject();
		acceleration = b->force * b->inverseMass;
		b->velocity += acceleration * dt;
		b->velocity *= 0.87f;
	}
}

void PhysicsManager::IntegrateVelocity(float dt)
{
	for (auto& b : colManager->allObjects) {
		Vector2 posChange = b->velocity * dt;
		b->collider->pos += posChange;
		b->position += posChange;
	}
}
