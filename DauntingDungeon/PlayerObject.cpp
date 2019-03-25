#include "PlayerObject.h"
#include <iostream>
#include <cmath>
#include "Circle.h"
#include "GameObjectType.h"

PlayerObject::PlayerObject(const std::string textureName,Vector2 pos) : GameObject(textureName, pos, player)
{
	inverseMass = 0.001;
	elasticity = 0.0f;
}