#include "PlayerObject.h"

PlayerObject::PlayerObject(const char* textureName, int x, int y) : GameObject(textureName, x, y)
{
	srcRect.h = 32;
	srcRect.w = 32;

	destRect.h = 64;
	destRect.w = 64;
}

void PlayerObject::Update()
{
	destRect.x += velocity.x*speed;
	destRect.y += velocity.y*speed;
}
