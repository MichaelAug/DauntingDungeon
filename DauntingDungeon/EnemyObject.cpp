#include "EnemyObject.h"
#include "GameObjectType.h"
#include "Animation.h"

EnemyObject::EnemyObject(Vector2 pos, EnemyType t) : GameObject("DauntingDungeon/Assets/map/dungeon.png", pos, enemy)
{
	inverseMass = 0.001;
	elasticity = 1;
	time = SDL_GetTicks();
	direction = Vector2(((rand() % 10) - 5)*0.1, ((rand() % 10) - 5)*0.1);
	
	animated = true;
	//anim = new Animation(Vector2(17,368), 8, 200);

	enemyType = t;
	
	if (t == demon) {
		anim = new Animation(Vector2(17, 368), 8, 200);
		srcRect.h = 32;
		srcRect.w = 32;
		srcRect.x = 17;
		srcRect.y = 368;
	}
	else if(t == orc) {
		anim = new Animation(Vector2(370, 176), 8, 150);
		destRect.h = 48;
		destRect.w = 48;

		srcRect.h = 20;
		srcRect.w = 16;
		srcRect.x = 371;
		srcRect.y = 174;
	}
	else if (t == chort) {
		anim = new Animation(Vector2(368, 332), 8, 150);
		destRect.h = 48;
		destRect.w = 48;

		srcRect.h = 20;
		srcRect.w = 16;
		srcRect.x = 368;
		srcRect.y = 332;
	}
}

bool EnemyObject::UpdateObject()
{
	if (animated) {
		srcRect.x = anim->startPos.x + (srcRect.w) * static_cast<int>((SDL_GetTicks() / anim->speed) % anim->frames);
	}

	if (SDL_GetTicks() - time > 1000) {
		direction = Vector2(((rand() % 10) - 5)*0.1, ((rand() % 10) - 5)*0.1);
		time = SDL_GetTicks();
	}
	force += direction;

	UpdateTexPos();
	return true;
}
