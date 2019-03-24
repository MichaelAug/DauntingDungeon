#pragma once
#include "GameObject.h"
#include "Vector2.h"
#include "Collidable.h"

class Engine;

class PlayerObject : public GameObject {
public:
	friend class Engine;

	PlayerObject(const std::string textureName, Vector2 pos);
	void Update();
	
private:
	SDL_Rect GetPreciseHitBox();

	Vector2 velocity;
	const float speed = 3;
};