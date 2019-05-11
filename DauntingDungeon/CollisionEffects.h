#pragma once

struct collision;
class CollisionEffects {
public:
	static bool ApplyEffects(collision* c);
	static bool playerProjectileCollision(collision* c);
};