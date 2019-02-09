#pragma once
#include "Engine.h"
#include "TileType.h"

class GameMap {
public:
	GameMap();
	~GameMap();

	void LoadMap(int arr[20][25]);
	void DrawMap();

private:
	SDL_Rect src, dest;

	TileType tiles;


	int map[20][25];
};