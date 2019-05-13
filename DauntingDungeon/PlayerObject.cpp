#include "PlayerObject.h"
#include <iostream>
#include <cmath>
#include "Circle.h"
#include "GameObjectType.h"
#include "Animation.h"
#include "TextureManager.h"

PlayerObject::PlayerObject(Vector2 pos) : 
	GameObject("DauntingDungeon/Assets/man_idle.png", pos, player)
{
	lives = 3;
	score = 0;
	recentlyHit = false;
	inverseMass = 0.001;
	elasticity = 0.0f;

	srcRect.h = 16;
	srcRect.w = 16;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.h = 45;
	destRect.w = 45;

	direction = Vector2(1, 0);

	animated = true;
	anim = new Animation(Vector2(0,0), 6, 150);

	idleTex = TextureManager::GetTexture("DauntingDungeon/Assets/man_idle.png");
	movingTex = TextureManager::GetTexture("DauntingDungeon/Assets/man_moving.png");
}

bool PlayerObject::UpdateObject()
{
	if (recentlyHit) {

		if (SDL_GetTicks() - invincibilityTime > 2000) {
			recentlyHit = false;
		}
	}

	if (animated) {
		srcRect.x = srcRect.w * static_cast<int>((SDL_GetTicks() / anim->speed) % anim->frames);
	}
	UpdateTexPos();

	//std::cout << "updated" << std::endl;
	return true;
}
