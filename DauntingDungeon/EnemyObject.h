#pragma once
#include "GameObject.h"

enum EnemyType {
	demon,
	chort,
	orc
};

struct Animation;
class PlayerObject;
class GameManager;
class EnemyObject : public GameObject {
public:
	EnemyObject(Vector2 pos, EnemyType t, PlayerObject* p, GameManager* g);
	virtual ~EnemyObject() {}
	bool UpdateObject() override;
	EnemyType enemyType;

	void EnemyHit() { lives--; }
	void IncreaseAgroRange() { agroRange += 20; }
private:
	int lives;
	float agroRange;
	bool attacking;
	PlayerObject* player;
	GameManager* game;
	int time;
	Vector2 direction;
	Animation* anim;
	float agroRangeTimer;
};

float Distance(Vector2 a, Vector2 b);