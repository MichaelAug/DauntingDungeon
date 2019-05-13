#pragma once
#include "GameObject.h"
#include "Vector2.h"
#include "Collidable.h"

class Engine;

class PlayerObject : public GameObject {
public:
	friend class Engine;

	PlayerObject(Vector2 pos);

	bool UpdateObject();

	void UpdateDirection(Vector2 dir) { direction = dir; }
	Vector2 GetDirection() { return direction; }
	
	Vector2 GetPosition() { return position; }

	void SetMoving() { objTexture = movingTex; }
	void SetIdle() { objTexture = idleTex; }

	void AddToScore() { score += 10; }
	int GetScore() { return score; }
	int GetLives() { return lives; }

	void EnemyHit() { 

		if (!recentlyHit) {
			invincibilityTime = SDL_GetTicks();
			--lives;
			recentlyHit = true;
		}
	}
private:
	int lives;
	int score;
	Vector2 direction;
	SDL_Texture* idleTex;
	SDL_Texture* movingTex;

	Uint32 invincibilityTime;
	bool recentlyHit;
};