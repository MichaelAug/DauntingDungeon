#include "GameManager.h"
#include "Circle.h"
#include "GameMap.h"
#include "PlayerObject.h"
#include "PhysicsManager.h"

GameManager::GameManager()
{
	physics = new PhysicsManager();
}

GameManager::~GameManager()
{
	delete physics;
	delete player;
}

void GameManager::Initialise()
{
	 player = new PlayerObject("Assets/man.png", Vector2(32, 48));
	 physics->AddGameObject(player);

	AddPlayerObject(player->position,player);
}

void GameManager::AddGameObject(Vector2 pos, GameObject* o)
{
	float centerX = (o->position.x + GameMap::tileSize / 2);
	float centerY = (o->position.y + GameMap::tileSize / 2);
	o->AddCollider(std::make_unique<Circle>(Vector2(centerX, centerY), 16));
	physics->AddGameObject(o);
}

void GameManager::AddPlayerObject(Vector2 pos, GameObject * o)
{
	float centerX = (o->position.x+20 + GameMap::tileSize / 2);
	float centerY = (o->position.y+10 + GameMap::tileSize / 2);
	o->AddCollider(std::make_unique<Circle>(Vector2(centerX, centerY), 16));
	physics->AddGameObject(o);
}
