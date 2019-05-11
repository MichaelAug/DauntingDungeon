#include "GameMap.h"
#include "TextureManager.h"
#include <fstream>
#include <iostream>
#include "Square.h"
#include "ColliderType.h"

GameMap::GameMap() :
	tileset(TextureManager::GetTexture("DauntingDungeon/Assets/map/dungeon.png"))
{
	dest.w = tileSize;
	dest.h = tileSize;

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

void GameMap::LoadMap(GameManager &gameManager)
{
	std::ifstream mapFile("DauntingDungeon/Assets/mapData/mapLayout.map");

	if (!mapFile) {
		std::cout << "Error loading in Map file!" << std::endl;
		return;
	}
	mapFile >> mapWidth;
	mapFile >> mapHeight;

	map = std::vector<std::vector<int>>(mapHeight, std::vector<int>(mapWidth, 0));

	std::vector<std::unique_ptr<Square>> initTer;

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
				initTer.emplace_back(std::make_unique<Square>(Vector2( //initially save top left corner of block as pos
					(float)col*tileSize, (float)row * tileSize), tileSize, tileSize));
			}
		}
	}

	/*Algorithm to combine terrain blocks into bigger colliders to save computation*/
	for (size_t i = 0; i < initTer.size(); ++i) {
		for (auto j = initTer.begin() + i; j != initTer.end();) {
			if (initTer[i]->pos.y == (*j)->pos.y &&
				initTer[i]->pos.x + initTer[i]->halfWidth == (*j)->pos.x &&
				initTer[i]->halfHeight == tileSize &&
				(*j)->halfHeight == tileSize && (*j)->halfWidth == tileSize) {
				initTer[i]->halfWidth += (*j)->halfWidth;
				(*j).reset();
				j = initTer.erase(j);
			}
			else if (initTer[i]->pos.x == (*j)->pos.x &&
				initTer[i]->pos.y + initTer[i]->GetHalfHeight() == (*j)->pos.y &&
				initTer[i]->halfWidth == tileSize &&
				(*j)->halfWidth == tileSize && (*j)->halfHeight == tileSize) {
				initTer[i]->halfHeight += (*j)->halfHeight;
				(*j).reset();
				j = initTer.erase(j);
			}
			else {
				++j;
			}
		}
	}

	//move pointers to primary vector and save actual center (x,y) pos and half width/height
	for (auto& o : initTer) {
		o->halfHeight /= 2;
		o->halfWidth /= 2;
		o->pos.x = o->pos.x + o->GetHalfWidth();
		o->pos.y = o->pos.y + o->GetHalfHeight();

		gameManager.AddTerrain(std::move(o));
	}

	/*std::cout << "numterrain: " << gameManager.terrain.size() << std::endl;
	for (auto a : gameManager.terrain) {
		std::shared_ptr<Square>s = std::dynamic_pointer_cast<Square>(a);
		std::cout << s->pos << " halfHeight= " << s->GetHalfHeight() << " halfWidth= " << s->GetHalfWidth() << std::endl;
	}*/
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