#pragma once
#include "SDL2/SDL.h"


/*Struct that contains SDL_Rects corresponding to a certain tile on the tilemap*/
struct TileType {
	SDL_Rect ground = {16,64, 16,16};
	SDL_Rect ground1 = { 32,64, 16,16 }; //ground top left
	SDL_Rect ground2 = { 48,64, 16,16 }; //ground top
	SDL_Rect ground3 = { 32,80, 16,16 }; // ground top right
	SDL_Rect groundR;
	SDL_Rect lava_fountain = { 64,16, 16,16 };
	SDL_Rect water_fountain = { 64,48, 16,16 };
	SDL_Rect flag_wall = { 16,32, 16,16 };
	SDL_Rect upper_wall = { 16,16, 16,16 };
	SDL_Rect pillar = { 32,32, 16,16 };
	SDL_Rect flag_wall_blue = { 32,32, 16,16 };
	SDL_Rect flag_wall_yellow = { 32,48, 16,16 };
	SDL_Rect wall_acid = { 64,80, 16,16 };
	SDL_Rect grass;
	SDL_Rect water;
};