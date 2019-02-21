#pragma once
#include "GameObject.h"
#include "Vector2.h"
#include "Collidable.h"

class Engine;

class PlayerObject : public GameObject, public Collidable {
public:
	friend class Engine;

	//keep track of previous position, if player collides with wall, put him back to previous position

	PlayerObject(const char* textureName, int x, int y);
	void Update();
	
private:
	SDL_Rect GetPreciseHitBox();

	Vector2 velocity;
	const float speed = 3;
};