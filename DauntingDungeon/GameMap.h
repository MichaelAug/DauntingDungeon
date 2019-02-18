#pragma once
#include "TileType.h"

class GameMap {
public:
	GameMap();

	void LoadMap(int arr[20][30]);
	void DrawMap();

private:
	SDL_Rect src, dest;

	SDL_Texture * tileset;
	TileType tiles;

	const int tileSize = 32;
	int map[20][35];
};