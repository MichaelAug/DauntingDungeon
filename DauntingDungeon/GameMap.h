#pragma once
#include "TileType.h"

class GameMap {
public:
	GameMap();

	void LoadMap(int arr[20][30]);
	void DrawMap();

private:
	SDL_Rect src, dest;

	TileType tiles;


	int map[20][35];
};