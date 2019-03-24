#pragma once
#include "GameObject.h"
#include "Vector2.h"
#include "Collidable.h"

class Engine;

class PlayerObject : public GameObject {
public:
	friend class Engine;

	PlayerObject(const std::string textureName, Vector2 pos);
	
private:
};