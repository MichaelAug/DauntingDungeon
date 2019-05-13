#pragma once

struct collision;
class CollisionEffects {
public:
	static bool ApplyEffects(collision* c);
	static bool playerProjectileCollision(collision* c);
	static bool ProjectileCollision(collision* c);
	static bool ProjectileEnemyCollision(collision* c);
	static bool EnemyPlayerCollision(collision* c);
};