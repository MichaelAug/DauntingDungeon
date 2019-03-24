#include "PlayerObject.h"
#include <iostream>
#include <cmath>
#include "Circle.h"

PlayerObject::PlayerObject(const std::string textureName,Vector2 pos) : GameObject(textureName, pos)
{
	/*srcRect.h = 32;
	srcRect.w = 32;

	destRect.h = 64;
	destRect.w = 64;*/
	inverseMass = 0.001;
}
void PlayerObject::Update()
{

	UpdateTexturePos();
}