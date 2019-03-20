#pragma once
#include "TileType.h"
#include <vector>
#include "Collidable.h"
#include <memory>

class GameMap {
public:
	GameMap();
	
	void LoadMap(); 
	void DrawMap();
	std::vector<Collidable> GetCollidableTiles();

private:
	SDL_Rect src, dest;
	int mapWidth;
	int mapHeight;

	std::unique_ptr<SDL_Texture, void(*)(SDL_Texture*)> tileset;
	TileType tiles;

	const int tileSize = 32;

	std::vector<std::vector<int>> map;

	std::vector<Collidable> collidableTiles;
};