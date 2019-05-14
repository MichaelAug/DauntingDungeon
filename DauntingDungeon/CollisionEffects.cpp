#include "CollisionEffects.h"
#include "CollisionManager.h"
#include "Projectile.h"
#include "EnemyObject.h"
#include "PlayerObject.h"

bool CollisionEffects::ApplyEffects(collision* c)
{
	//std::cout << c->obj1->type<<"    "<<c->obj2->type << std::endl;
	if (EnemyPlayerCollision(c) ||
		ProjectileEnemyCollision(c) ||
		playerProjectileCollision(c) ||
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

bool CollisionEffects::ProjectileEnemyCollision(collision* c)
{

	if (c->obj1->type == projectile && c->obj2->type == enemy) {
		EnemyObject* e = dynamic_cast<EnemyObject*>(c->obj2);
		Projectile* p = dynamic_cast<Projectile*>(c->obj1);
		
		if (!p->IsHit()) {
			//std::cout << "HERE" << std::endl;
			e->EnemyHit();
		}
	}
	if (c->obj2->type == projectile && c->obj1->type == enemy) {
		EnemyObject* e = dynamic_cast<EnemyObject*>(c->obj1);
		Projectile* p = dynamic_cast<Projectile*>(c->obj2);
		if (!p->IsHit()) {
			e->EnemyHit();
		}
	}

	return false;
}

bool CollisionEffects::EnemyPlayerCollision(collision* c)
{
	if (c->obj1->type == player && c->obj2->type == enemy) {
		PlayerObject* p = dynamic_cast<PlayerObject*>(c->obj1);
		p->EnemyHit();
	}
	if (c->obj1->type == enemy && c->obj2->type == player) {
		PlayerObject* p = dynamic_cast<PlayerObject*>(c->obj2);
		p->EnemyHit();
	}


	return false;
}
