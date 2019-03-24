#include "Circle.h"

Circle::Circle(Vector2 pos, int radius) :
	Collidable(pos, circle), radius(radius)
{
}
