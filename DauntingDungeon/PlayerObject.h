#pragma once
#include "GameObject.h"
#include "Vector2.h"
#include "Collidable.h"

class Engine;

class PlayerObject : public GameObject {
public:
	friend class Engine;

	PlayerObject(Vector2 pos);


	void UpdateDirection(Vector2 dir) { direction = dir; }
	Vector2 GetDirection() { return direction; }
	
	Vector2 GetPosition() { return position; }

	void SetMoving() { objTexture = movingTex; }
	void SetIdle() { objTexture = idleTex; }
private:
	Vector2 direction;
	SDL_Texture* idleTex;
	SDL_Texture* movingTex;
};