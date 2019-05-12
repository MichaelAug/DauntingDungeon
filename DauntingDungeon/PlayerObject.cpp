#include "PlayerObject.h"
#include <iostream>
#include <cmath>
#include "Circle.h"
#include "GameObjectType.h"

PlayerObject::PlayerObject(const std::string textureName,Vector2 pos) : GameObject(textureName, pos, player)
{
	inverseMass = 0.001;
	elasticity = 0.0f;

	srcRect.h = 16;
	srcRect.w = 16;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.h = 45;
	destRect.w = 45;

	direction = Vector2(1, 0);
}