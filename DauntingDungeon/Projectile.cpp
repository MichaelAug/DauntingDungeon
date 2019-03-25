#include "Projectile.h"

Projectile::Projectile(const std::string textureName, Vector2 pos, Vector2 direction) :
	GameObject(textureName, pos)
{
	inverseMass = 0.001;
	elasticity = 1.0f;
	direction.normalise();
	this->direction = direction;
	srcRect.h = 150;
	srcRect.w = 150;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.h = 50;
	destRect.w = 50;
}

void Projectile::UpdateObject()
{
	AddForce(direction*7);


	direction *= 0.98;
	UpdateTexPos();
}
