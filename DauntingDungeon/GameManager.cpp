#include "GameManager.h"
#include "Circle.h"
#include "GameMap.h"
#include "PlayerObject.h"

GameManager::GameManager() : physics(std::make_unique<PhysicsManager>())
{
	physics = std::make_unique<PhysicsManager>();
}

void GameManager::Initialise()
{
	 player = std::make_unique<PlayerObject>("Assets/man.png", Vector2(32, 48));
	 physics->AddGameObject(player.get());

	AddGameObject(player->position,	player.get());
}


void GameManager::AddGameObject(Vector2 pos, GameObject* o)
{
	float centerX = (o->position.x + GameMap::tileSize / 2);
	float centerY = (o->position.y + GameMap::tileSize / 2);
	o->AddCollider(std::make_unique<Circle>(Vector2(centerX, centerY), 16));
	physics->AddGameObject(o);
}
