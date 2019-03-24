#include "PhysicsObject.h"

void PhysicsObject::AddForce(Vector2 f)
{
	force += f;
}

PhysicsObject::PhysicsObject(Vector2 pos) : position(pos)
{
}
