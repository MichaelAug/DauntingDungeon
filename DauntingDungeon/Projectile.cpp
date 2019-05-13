#include "Projectile.h"
#include "GameObjectType.h"
#include "Animation.h"

Projectile::Projectile(const std::string textureName, Vector2 pos, Vector2 direction) :
	GameObject(textureName, pos, projectile)
{
	inverseMass = 0.0001f;
	elasticity = 1.0f;
	direction.normalise();
	this->direction = direction;
	srcRect.h = 50;
	srcRect.w = 48;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.h = 32;
	destRect.w = 32;
	animated = true;
	anim = new Animation(Vector2(0, 0), 5, 50);
	hit = false;
}

bool Projectile::UpdateObject()
{
	UpdateTexPos();
	
	if (hit) {
		velocity = Vector2(0, 0);
		anim->startPos = Vector2(240, 0);
		anim->frames = 3;
		anim->speed = 80;
		destRect.x += 32;

		if (SDL_GetTicks() - afterHitTimer > anim->speed*anim->frames) {
			
			return false;
		}
	}

	if (animated) {
		srcRect.x = anim->startPos.x + srcRect.w * static_cast<int>((SDL_GetTicks() / anim->speed) % anim->frames);
	}

	if (!hit) {
		AddForce(direction * 150);
	}
	return true;
}
