#pragma once
#include "Collidable.h"

class Circle : public Collidable {
public:
	Circle(Vector2 pos, int radius);
	~Circle() {}
	int GetRadius() const { return radius; }
protected:
	int radius;
};