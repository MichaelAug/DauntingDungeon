#include "GameMap.h"
#include "TextureManager.h"


int lvl1[20][30] = { 0 }; //initialise array with all values set to 0


GameMap::GameMap()
{
	tiles.ground = TextureManager::GetTexture("Assets/ground.png");
	tiles.grass = TextureManager::GetTexture("Assets/grass.png");
	tiles.water = TextureManager::GetTexture("Assets/water.png");

	LoadMap(lvl1);

	src.x = src.y = 0;
	src.w =  src.h = 32;
	dest.w = 32;
	dest.h = 32;
	dest.x = dest.y = 0;
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

			dest.x = col * 32;
			dest.y = row * 32;

			switch (type) {
			case 0:
				TextureManager::Draw(tiles.water, src, dest);
				break;
			case 1:
				TextureManager::Draw(tiles.grass, src, dest);
				break;
			case 2:
				TextureManager::Draw(tiles.ground, src, dest);
				break;

			default:
				break;
			}
		}
	}
}
