#include "PhysicsManager.h"

PhysicsManager::PhysicsManager()
{
	collider = std::make_unique<CollisionManager>();
}

void PhysicsManager::UpdatePhysics(float dt)
{
	Integration(dt);
	/*colManager.CollisionDetection(dt, allObjects);
	colManager.HandleCollisionResolution();*/
	IntegrateVelocity(dt);
	ResetForces();
}

void PhysicsManager::ResetForces()
{
	for (auto& b : collider->allObjects) {
		b->force.ToZero();
	}
}

void PhysicsManager::AddGameObject(GameObject* b)
{
	collider->allObjects.emplace_back(b);
}

void PhysicsManager::Integration(float dt)
{
	Vector2 acceleration;
	for (auto& b : collider->allObjects) {
		acceleration = b->force * b->inverseMass;
		b->velocity += acceleration * dt;
		b->velocity *= 0.87f;
	}
}

void PhysicsManager::IntegrateVelocity(float dt)
{
	for (auto& b : collider->allObjects) {
		Vector2 posChange = b->velocity * dt;
		b->collider->pos += posChange;
		b->position += posChange;
		b->UpdateTexturePos();
	}

}
