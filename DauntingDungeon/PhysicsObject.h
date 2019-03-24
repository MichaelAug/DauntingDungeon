#pragma once
#include "Vector2.h"

class PhysicsObject {
public:
	PhysicsObject() {}
	PhysicsObject(Vector2);
protected:
	Vector2 position; //top-left corner pos (used for texture drawing)
	Vector2 velocity;
	Vector2 force;

	float inverseMass;
	float elasticity;
};