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
	animated = true;
	anim = new Animation(Vector2(0, 0), 5, 50);
	hit = false;

	if (this->direction.x < 0) {
		spriteFlip = SDL_FLIP_HORIZONTAL;
	}
	if (this->direction.y > 0) {
		spriteRotation = 90;
	}
	if (this->direction.y < 0) {
		spriteRotation = -90;
	}
	if (std::abs(this->direction.x) == std::abs(this->direction.y)) {
		spriteRotation = 0;
	}

	std::cout << this->direction << std::endl;
}

bool Projectile::UpdateObject()
{
	UpdateTexPos();

	if (hit) {
		velocity = Vector2(0, 0);
		anim->startPos = Vector2(240, 0);
		anim->frames = 3;
		anim->speed = 80;

		destRect.x += direction.x * 32;
		destRect.y += direction.y * 32;

		if (SDL_GetTicks() - afterHitTimer > anim->speed * anim->frames) {

			return false;
		}
	}

	if (animated) {
		srcRect.x = anim->startPos.x + srcRect.w * static_cast<int>((SDL_GetTicks() / anim->speed) % anim->frames);
	}

	if (!hit) {
		AddForce(direction * 15);
	}
	return true;
}
