#pragma once
#include "Collidable.h"

class Square : public Collidable {
	friend class GameMap;
public:
	Square(Vector2 centerPos, int halfWidth, int halfHeight);
	~Square() {}
	int GetHalfWidth() const { return halfWidth; }
	int GetHalfHeight() const { return halfHeight; }

	//friend class GameMap;
protected:
	int halfWidth;
	int halfHeight;
};