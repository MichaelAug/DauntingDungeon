#pragma once
#include "TileType.h"
#include <vector>

class GameMap {
public:
	GameMap();
	~GameMap();

	void LoadMap();
	void DrawMap();
	std::vector<SDL_Rect> GetCollidableTiles();

private:
	SDL_Rect src, dest;
	int mapWidth;
	int mapHeight;

	SDL_Texture *tileset;
	TileType tiles;

	const int tileSize = 32;
	int **map;

	std::vector<SDL_Rect> collidableTiles;
};