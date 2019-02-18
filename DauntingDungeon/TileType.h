#pragma once
#include "SDL.h"


/*Struct that contains SDL_Rects corresponding to a certain tile on the tilemap*/
struct TileType {
	SDL_Rect groundTL; //ground top left
	SDL_Rect groundT; //ground top
	SDL_Rect groundTR; // ground top right
	SDL_Rect groundR;
	SDL_Rect upper_wall;
	SDL_Rect pillar;
	SDL_Rect ground;
	SDL_Rect grass;
	SDL_Rect water;
};