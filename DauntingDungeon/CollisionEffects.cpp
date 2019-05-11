#include "CollisionEffects.h"
#include "CollisionManager.h"

bool CollisionEffects::ApplyEffects(collision* c)
{
	//std::cout << c->obj1->type<<"    "<<c->obj2->type << std::endl;
	if (playerProjectileCollision(c)) {
		return false;
	}
	return true;
}

bool CollisionEffects::playerProjectileCollision(collision* c)
{
	return c->obj1->type == player && c->obj2->type == projectile ||
		c->obj1->type == projectile && c->obj2->type == player;
}
