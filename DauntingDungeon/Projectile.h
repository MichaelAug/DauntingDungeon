#pragma once
#include "GameObject.h"

class Projectile : public GameObject{
public:

	Projectile(const std::string textureName, Vector2 pos, Vector2 direction);
	void UpdateObject() override;
private:
	Vector2 direction;
};