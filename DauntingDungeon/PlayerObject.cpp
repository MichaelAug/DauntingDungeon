#include "PlayerObject.h"

PlayerObject::PlayerObject(const char* textureName, int x, int y) : GameObject(textureName, x, y)
{
	srcRect.h = 64;
	srcRect.w = 64;

	destRect.h = srcRect.h*2;
	destRect.w = srcRect.w*2;
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
