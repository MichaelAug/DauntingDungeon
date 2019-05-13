#include "CollisionEffects.h"
#include "CollisionManager.h"
#include "Projectile.h"

bool CollisionEffects::ApplyEffects(collision* c)
{
	//std::cout << c->obj1->type<<"    "<<c->obj2->type << std::endl;
	if (playerProjectileCollision(c) ||
		ProjectileCollision(c)) {
		return false;
	}
	return true;
}

bool CollisionEffects::playerProjectileCollision(collision* c)
{
	return c->obj1->type == player && c->obj2->type == projectile ||
		c->obj1->type == projectile && c->obj2->type == player;
}

bool CollisionEffects::ProjectileCollision(collision* c)
{
	if (c->obj1->type == projectile && c->obj2->type != projectile) {
		Projectile* p = dynamic_cast<Projectile*>(c->obj1);
		p->Hit();
	}
	if (c->obj2->type == projectile && c->obj1->type != projectile) {
		Projectile* p = dynamic_cast<Projectile*>(c->obj2);
		p->Hit();
	}

	if (c->obj1->type == projectile && c->obj2->type == projectile) {

		return true;
	}
	return false;
}
