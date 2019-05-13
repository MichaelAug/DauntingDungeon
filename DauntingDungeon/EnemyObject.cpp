#include "EnemyObject.h"
#include "GameObjectType.h"
#include "Animation.h"
#include "PlayerObject.h"

EnemyObject::EnemyObject(Vector2 pos, EnemyType t, PlayerObject* p) : GameObject("DauntingDungeon/Assets/map/dungeon.png", pos, enemy)
{
	inverseMass = 0.0005;
	elasticity = 1;
	time = SDL_GetTicks();
	direction = Vector2(((rand() % 10) - 5) * 0.1, ((rand() % 10) - 5) * 0.1);
	player = p;
	animated = true;
	//anim = new Animation(Vector2(17,368), 8, 200);
	attacking = false;
	enemyType = t;

	if (t == demon) {
		anim = new Animation(Vector2(17, 368), 8, 200);
		srcRect.h = 32;
		srcRect.w = 32;
		srcRect.x = 17;
		srcRect.y = 368;
		agroRange = 200;
	}
	else if (t == orc) {
		anim = new Animation(Vector2(370, 176), 8, 200);
		destRect.h = 48;
		destRect.w = 48;

		srcRect.h = 20;
		srcRect.w = 16;
		srcRect.x = 371;
		srcRect.y = 174;
		agroRange = 250;
	}
	else if (t == chort) {
		anim = new Animation(Vector2(368, 332), 8, 200);
		destRect.h = 48;
		destRect.w = 48;

		srcRect.h = 20;
		srcRect.w = 16;
		srcRect.x = 368;
		srcRect.y = 332;
		agroRange = 300;
	}
}

float Distance(Vector2 a, Vector2 b) {
	return std::sqrtf(std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2));
}

bool EnemyObject::UpdateObject()
{
	if (attacking) {
		AddForce(Vector2(player->GetPosition().x - position.x, player->GetPosition().y - position.y) * 0.05);
		//std::cout << "atacking" << std::endl;

		if (Distance(player->GetPosition(), position) > agroRange*1.5) {
			attacking = false;
		}
	}
	else {
		std::srand(SDL_GetTicks());
		if (SDL_GetTicks() - time > 1000) {
			direction = Vector2(((rand() % 10) - 5) * 0.1, ((rand() % 10) - 5) * 0.1);
			time = SDL_GetTicks();
		}
		AddForce(direction * 5);
		//std::cout << "not attacking" << std::endl;
		if (Distance(player->GetPosition(), position) < agroRange) {
			attacking = true;
		}
	}

	if (animated) {
		srcRect.x = anim->startPos.x + (srcRect.w) * static_cast<int>((SDL_GetTicks() / anim->speed) % anim->frames);
	}

	if (this->force.x < 0) {
		spriteFlip = SDL_FLIP_HORIZONTAL;
	}
	if (this->force.x >= 0) {
		spriteFlip = SDL_FLIP_NONE;
	}

	UpdateTexPos();
	return true;
}
