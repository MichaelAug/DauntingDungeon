#pragma once
#include "GameObject.h"
#include "Vector2.h"

class Engine;

class PlayerObject : public GameObject {
public:

	friend class Engine;

	//keep track of previous position, if player collides with wall, put him back to previous position

	PlayerObject(const char* textureName, int x, int y);
	void Update();
	const SDL_Rect &GetHitBoxRect();
	
private:
	Vector2 velocity;
	const float speed = 3;
};