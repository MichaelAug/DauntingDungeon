#include "PhysicsObject.h"

void PhysicsObject::AddForce(Vector2 f)
{
	force += f;
}



PhysicsObject::PhysicsObject(Vector2 pos) : PhysicsObject()
{
	position = pos;
}

PhysicsObject::PhysicsObject() :
	position(Vector2(0, 0)),
	velocity(Vector2(0, 0)),
	force(Vector2(0, 0)),
	inverseMass(0),
	elasticity(1)
{
}