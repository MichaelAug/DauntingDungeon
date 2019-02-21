#include "GameMap.h"
#include "TextureManager.h"
#include <fstream>
#include <iostream>

GameMap::GameMap()
{
	dest.w = tileSize;
	dest.h = tileSize;
	LoadMap();
	mapHeight = 0;
	mapWidth = 0;
	/*map = nullptr;   IF I UNCOMMENT THIS I GET ACCESS VIOLATION ERROR! WHY*/

	/*height and width of rendered tile*/
	
	dest.x = dest.y = 0;

	tileset = TextureManager::GetTexture("Assets/map/dungeon.png");
	src.w = src.h = tileSize;

	src.x = 96; src.y = 64;
	tiles.ground = src;

	src.x = 96; src.y = 0;
	tiles.upper_wall = src;

	src.x = 32; src.y = 32;
	tiles.pillar = src;

}

GameMap::~GameMap()
{
	if (map) {
		for (int i = 0; i < mapHeight; ++i) {
			delete[] map[i];
		}
		delete[] map;
	}
}

void GameMap::LoadMap()
{
	std::ifstream mapFile("Assets/mapData/mapLayout.map");

	if (!mapFile) {
		std::cout << "Error loading in Map file!" << std::endl;
		return;
	}

	mapFile >> mapWidth;
	mapFile >> mapHeight;

	map = new int*[mapHeight];
	for (int i = 0; i < mapHeight; ++i) {
		map[i] = new int[mapWidth];
	}

	for (int y = 0; y < mapHeight; ++y) {
		for (int x = 0; x < mapWidth; ++x) {

			char type = 0;
			mapFile >> type;
			map[y][x] = type - '0';			
		}
	}

	int type = 0;
	for (int row = 0; row < 20; ++row) {
		for (int col = 0; col < 30; ++col) {
			type = map[row][col];

			dest.x = col * tileSize;
			dest.y = row * tileSize;

			if (type == 1) {
				collidableTiles.emplace_back(Collidable(dest));
			}
		}
	}
}

void GameMap::DrawMap()
{
	int type = 0;

	for (int row = 0; row < 20; ++row) {
		for (int col = 0; col < 30; ++col) {
			type = map[row][col];

			dest.x = col * tileSize;
			dest.y = row * tileSize;

			switch (type) {
			case 0:
				TextureManager::Draw(tileset, tiles.ground, dest);
				break;
			case 1:
				TextureManager::Draw(tileset, tiles.upper_wall, dest);
				break;
			case 2:
				TextureManager::Draw(tileset, tiles.pillar, dest);
				break;

			default:
				break;
			}
		}
	}
}

std::vector<Collidable> GameMap::GetCollidableTiles()
{
	return collidableTiles;
}
