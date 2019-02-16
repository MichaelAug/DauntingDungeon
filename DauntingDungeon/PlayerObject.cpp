#include "PlayerObject.h"

PlayerObject::PlayerObject(const char* textureName, int x, int y) : GameObject(textureName, x, y)
{
	srcRect.h = 64;
	srcRect.w = 64;

	destRect.h = srcRect.h*2;
	destRect.w = srcRect.w*2;
}

void PlayerObject::Update(const float & x, const float & y)
{
	xpos=xpos +x;
	ypos=ypos + y;
	destRect.x = xpos;
	destRect.y = ypos;
}
