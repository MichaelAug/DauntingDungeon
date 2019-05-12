#pragma once
#include "GameObject.h"
#include "Vector2.h"
#include "Collidable.h"

class Engine;

class PlayerObject : public GameObject {
public:
	friend class Engine;

	void UpdateDirection(Vector2 dir) { direction = dir; }
	Vector2 GetDirection() { return direction; }
	PlayerObject(const std::string textureName, Vector2 pos);
	Vector2 GetPosition() { return position; }
private:
	Vector2 direction;
};