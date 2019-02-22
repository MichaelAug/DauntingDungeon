#include "Vector2.h"
#include <cmath>

Vector2::Vector2()
{
	x = 0.0f;
	y = 0.0f;
}

Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}

void Vector2::normalise()
{
	if (x == 0 && y == 0)
		return;

	float length = std::sqrtf((x*x) + (y*y));
	x /= length;
	y /= length;
}

Vector2 operator-(const Vector2&vec1, const Vector2&vec2)
{
	float x = vec1.x - vec2.x;
	float y = vec1.y - vec2.y;
	return Vector2(x,y);
}
