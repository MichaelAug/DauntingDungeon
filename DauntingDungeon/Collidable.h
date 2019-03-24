#pragma once
#include "Vector2.h"
#include "ColliderType.h"

class Collidable {
	friend class Engine;
public:
	Collidable() {};
	virtual ~Collidable() {}
	Collidable(Vector2 pos, ColliderType type);
	ColliderType GetType() { return type; }
	Vector2 pos; //center of collider pos
protected:
	ColliderType type;
private:
};

