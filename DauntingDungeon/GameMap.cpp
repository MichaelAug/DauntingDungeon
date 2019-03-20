#include "GameMap.h"
#include "TextureManager.h"
#include <fstream>
#include <iostream>

GameMap::GameMap() :
	tileset(TextureManager::GetTexture("Assets/map/dungeon.png"))
{
	dest.w = tileSize;
	dest.h = tileSize;

	/*Initialise and load map*/
	LoadMap();

	mapHeight = 0;
	mapWidth = 0;

	/*height and width of rendered tile*/
	dest.x = dest.y = 0;

	src.w = src.h = tileSize;

	src.x = 96; src.y = 64;
	tiles.ground = src;

	src.x = 96; src.y = 0;
	tiles.upper_wall = src;

	src.x = 32; src.y = 32;
	tiles.pillar = src;

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

	map = std::vector<std::vector<int>>(mapHeight, std::vector<int>(mapWidth, 0));

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
				TextureManager::Draw(tileset.get(), tiles.ground, dest);
				break;
			case 1:
				TextureManager::Draw(tileset.get(), tiles.upper_wall, dest);
				break;
			case 2:
				TextureManager::Draw(tileset.get(), tiles.pillar, dest);
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
