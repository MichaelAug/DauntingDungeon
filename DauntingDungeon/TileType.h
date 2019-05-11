#pragma once
#include "SDL.h"


/*Struct that contains SDL_Rects corresponding to a certain tile on the tilemap*/
struct TileType {
	SDL_Rect ground;
	SDL_Rect ground1; //ground top left
	SDL_Rect ground2; //ground top
	SDL_Rect ground3; // ground top right
	SDL_Rect groundR;
	SDL_Rect lava_fountain;
	SDL_Rect water_fountain;
	SDL_Rect flag_wall;
	SDL_Rect upper_wall;
	SDL_Rect pillar;
	
	SDL_Rect grass;
	SDL_Rect water;
};