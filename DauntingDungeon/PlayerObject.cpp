#include "PlayerObject.h"
#include <iostream>
#include <cmath>

PlayerObject::PlayerObject(const std::string textureName, int x, int y) : GameObject(textureName, x, y), Collidable()
{
	srcRect.h = 32;
	srcRect.w = 32;

	destRect.h = 64;
	destRect.w = 64;

	UpdateRectPos(GetPreciseHitBox());
}
void PlayerObject::Update()
{
	
	velocity.normalise();
	
	destRect.x += std::round(velocity.x*speed);
	destRect.y += std::round(velocity.y*speed);

	UpdateRectPos(GetPreciseHitBox());
}

SDL_Rect PlayerObject::GetPreciseHitBox()
{
	/*A more precise version of the SDL_Rect that represents the player's hit-box
	(needed because of the texture having a lot of empty space)*/
	SDL_Rect playerHitBox = destRect;
	playerHitBox.x += 20;
	playerHitBox.w -= 35;

	playerHitBox.y += 20;
	playerHitBox.h -= 42;
	return playerHitBox;
}
