#pragma once
#include "GameObject.h"

enum EnemyType {
	demon,
	chort,
	orc
};

struct Animation;
class PlayerObject;
class EnemyObject : public GameObject {
public:
	EnemyObject(Vector2 pos, EnemyType t, PlayerObject* p);
	virtual ~EnemyObject() {}
	bool UpdateObject() override;
	EnemyType enemyType;

	void EnemyHit() { lives--; }
private:
	int lives;
	float agroRange;
	bool attacking;
	PlayerObject* player;
	int time;
	Vector2 direction;
	Animation* anim;
};