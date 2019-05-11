#pragma once
#include "TileType.h"
#include <vector>
#include <memory>

class GameManager;

class GameMap {
public:
	inline static const int tileSize = 32;
	GameMap();

	void LoadMap(GameManager &gameManager);
	void DrawMap();

private:
	SDL_Rect src, dest;
	int mapWidth;
	int mapHeight;

	SDL_Texture* tileset;
	TileType tiles;

	static const int tileHalfSize = 16;

	std::vector<std::vector<int>> map;
};

#include "GameManager.h"