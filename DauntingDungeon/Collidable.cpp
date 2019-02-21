#include "Collidable.h"

Collidable::Collidable(SDL_Rect rect)
{
	UpdateRectPos(rect);
}

void Collidable::UpdateRectPos(SDL_Rect rect)
{
	hitbox = rect;
	centerPoint = GetCenterPoint(rect);
}

SDL_Rect Collidable::GetHitBox()
{
	return hitbox;
}

Vector2 Collidable::GetCenterPoint(SDL_Rect dimensions)
{
	float x = (dimensions.x + dimensions.w) / 2;
	float y = (dimensions.y + dimensions.h) / 2;
	return Vector2(x, y);
}
