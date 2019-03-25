#pragma once
#include "TileType.h"
#include <vector>
#include <memory>
#include "GameManager.h"

class GameMap {
public:
	GameMap();
	
	void LoadMap(GameManager &gameManager);
	void DrawMap();
	static const int tileSize = 32;
private:
	SDL_Rect src, dest;
	int mapWidth;
	int mapHeight;

	std::unique_ptr<SDL_Texture, void(*)(SDL_Texture*)> tileset;
	TileType tiles;

	static const int tileHalfSize = 16;

	std::vector<std::vector<int>> map;
};