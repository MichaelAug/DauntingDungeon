#include "Collidable.h"

Collidable::Collidable(SDL_Rect rect)
{
	UpdateRectPos(rect);
}

void Collidable::UpdateRectPos(SDL_Rect rect)
{
	hitbox = rect;
}

SDL_Rect Collidable::GetHitBox()
{
	return hitbox;
}