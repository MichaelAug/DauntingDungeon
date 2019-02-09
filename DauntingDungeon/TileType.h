#pragma once
#include "SDL.h"


/*Struct that contains all types of tiles used for the game map*/
struct TileType {
	SDL_Texture * ground;
	SDL_Texture * grass;
	SDL_Texture * water;
};