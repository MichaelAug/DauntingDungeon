#pragma once
#include "TileType.h"
#include <vector>
#include "Collidable.h"

class GameMap {
public:
	GameMap();
	~GameMap();
	
	void LoadMap(); 
	void DrawMap();
	std::vector<Collidable> GetCollidableTiles();

private:
	SDL_Rect src, dest;
	int mapWidth;
	int mapHeight;

	SDL_Texture *tileset;
	TileType tiles;

	const int tileSize = 32;
	int **map;

	std::vector<Collidable> collidableTiles;
};