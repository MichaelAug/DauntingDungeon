#pragma once
#include "GameObject.h"
#include "Vector2.h"

class PlayerObject : public GameObject {
public:
	PlayerObject(const char* textureName, int x, int y);
	void UpdateVelX(float x); // update player's velocity on x axis
	void UpdateVelY(float y); // update player's velocity on y axis
	void Update();
	const SDL_Rect &GetHitBoxRect();
	Vector2 velocity;
private:
	const float speed = 3;
};