#pragma once
#include "GameObject.h"

enum EnemyType {
	demon,
	chort,
	orc
};

struct Animation;
class EnemyObject : public GameObject {
public:
	EnemyObject(Vector2 pos, EnemyType t);
	virtual ~EnemyObject() {}
	bool UpdateObject() override;
	EnemyType enemyType;
private:
	

	int time;
	Vector2 direction;
	Animation* anim;
};