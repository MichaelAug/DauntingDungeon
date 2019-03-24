#include "Square.h"

Square::Square(Vector2 centerPos, int halfWidth, int halfHeight) :
	Collidable(centerPos, square), halfWidth(halfWidth), halfHeight(halfHeight)
{
}
