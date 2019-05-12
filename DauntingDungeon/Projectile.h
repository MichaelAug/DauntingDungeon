#pragma once
#include "GameObject.h"

class Projectile : public GameObject {
public:

	Projectile(const std::string textureName, Vector2 pos, Vector2 direction);
	bool UpdateObject() override;

	void Hit(){hit = true;}
private:
	Vector2 direction;
	bool hit;
};