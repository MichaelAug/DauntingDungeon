#pragma once
#include "TileType.h"

class GameMap {
public:
	GameMap();

	void LoadMap();
	void DrawMap();

private:
	SDL_Rect src, dest;
	int mapWidth;
	int mapHeight;

	SDL_Texture * tileset;
	TileType tiles;

	const int tileSize = 32;
	int **map;
};