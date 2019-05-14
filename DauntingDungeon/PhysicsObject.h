#pragma once
#include "Vector2.h"

class PhysicsObject {
	friend class CollisionManager;
public:
	void AddForce(Vector2 f);
	
	PhysicsObject(Vector2);
	PhysicsObject();
protected:
	Vector2 position; //top-left corner pos (used for texture drawing)
	Vector2 velocity;
	Vector2 force;

	float inverseMass;
	float elasticity;
};