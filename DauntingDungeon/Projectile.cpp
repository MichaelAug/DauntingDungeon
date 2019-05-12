#include "Projectile.h"
#include "GameObjectType.h"

Projectile::Projectile(const std::string textureName, Vector2 pos, Vector2 direction) :
	GameObject(textureName, pos, projectile)
{
	inverseMass = 0.001f;
	elasticity = 1.0f;
	direction.normalise();
	this->direction = direction;
	srcRect.h = 150;
	srcRect.w = 150;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.h = 50;
	destRect.w = 50;
	hit = false;
}

bool Projectile::UpdateObject()
{
	if (hit) {
		return false;
	}
	AddForce(direction*15);

	//direction *= 0.98;
	UpdateTexPos();

	return true;
}
