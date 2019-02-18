#include "PlayerObject.h"

PlayerObject::PlayerObject(const char* textureName, int x, int y) : GameObject(textureName, x, y)
{
	srcRect.h = 32;
	srcRect.w = 32;

	destRect.h = 64;
	destRect.w = 64;
}

void PlayerObject::UpdateVelX(float x)
{
	velocity.x = x;
}

void PlayerObject::UpdateVelY(float y)
{
	velocity.y = y;
}

void PlayerObject::Update()
{
	xpos+= velocity.x * speed;
	ypos+= velocity.y * speed;
	destRect.x = xpos;
	destRect.y = ypos;
}
