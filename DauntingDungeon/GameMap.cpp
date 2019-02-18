#include "GameMap.h"
#include "TextureManager.h"


int lvl1[20][30] = { 0 }; //initialise array with all values set to 0

GameMap::GameMap()
{
	lvl1[13][10] = 1;
	lvl1[13][11] = 1;
	lvl1[13][12] = 1;
	lvl1[14][10] = 1;
	lvl1[15][10] = 1;
	lvl1[2][10] = 2;
	lvl1[3][10] = 2;
	LoadMap(lvl1);

	/*height and width of rendered tile*/
	dest.w = tileSize;
	dest.h = tileSize;
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

void GameMap::LoadMap(int arr[20][30])
{
	for (int row = 0; row < 20; row++) {
		for (int col = 0; col < 30; col++) {
			map[row][col] = arr[row][col];
		}
	}
}

void GameMap::DrawMap()
{
	int type = 0;

	for (int row = 0; row < 20; row++) {
		for (int col = 0; col < 30; col++) {
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
