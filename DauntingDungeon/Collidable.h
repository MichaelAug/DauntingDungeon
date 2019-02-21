#pragma once
#include "SDL.h"
#include "Vector2.h"


/*if collision occurs, compare center points of blocks,
if a.x < b.x then push to right
if a.y < b.y then push up
etc*/


/* store the SDL_Rects here for collision, player's hitbox for example (instead of calculating it in the collision detection)*/
class Collidable {
public:
	Collidable() {};
	Collidable(SDL_Rect);
	void UpdateRectPos(SDL_Rect);
	SDL_Rect GetHitBox();

protected:
	SDL_Rect hitbox;
	Vector2 centerPoint;

private:
	Vector2 GetCenterPoint(SDL_Rect dimensions);
};

