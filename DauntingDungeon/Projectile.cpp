#include "Projectile.h"
#include "GameObjectType.h"
#include "Animation.h"

Projectile::Projectile(const std::string textureName, Vector2 pos, Vector2 direction) :
	GameObject(textureName, pos, projectile)
{
	inverseMass = 0.001f;
	elasticity = 1.0f;
	direction.normalise();
	this->direction = direction;
	srcRect.h = 50;
	srcRect.w = 48;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.h = 32;
	destRect.w = 32;
	hit = false;
	animated = true;
	anim = new Animation(Vector2(0, 0), 5, 50);
}

bool Projectile::UpdateObject()
{
	if (hit) {
		return false;
	}

	if (animated) {
		srcRect.x = srcRect.w * static_cast<int>((SDL_GetTicks() / anim->speed) % anim->frames);
	}

	AddForce(direction*15);

	//direction *= 0.98;
	UpdateTexPos();

	return true;
}
