#include "PlayerObject.h"
#include <iostream>
#include <cmath>
#include "Circle.h"

PlayerObject::PlayerObject(const std::string textureName,Vector2 pos) : GameObject(textureName, pos)
{
	inverseMass = 0.001;
	elasticity = 0.0f;
}