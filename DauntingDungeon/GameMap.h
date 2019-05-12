#pragma once
#include "TileType.h"
#include <vector>
#include <memory>

class GameManager;

class GameMap {
private:
	SDL_Rect src, dest;
	int mapWidth;
	int mapHeight;

	
	TileType tiles;

	static const int tileHalfSize = 16;

	std::vector<std::vector<int>> map;
public:
	SDL_Texture* tileset;
	inline static const int tileSize = 32;
	GameMap();

	void LoadMap(GameManager &gameManager);
	void DrawMap();


};

#include "GameManager.h"