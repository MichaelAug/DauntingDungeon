#include "GameManager.h"
#include "Circle.h"
#include "GameMap.h"
#include "PlayerObject.h"
#include "PhysicsManager.h"
#include "EnemyObject.h"

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

	AddPlayerObject(player->position,player);

	EnemyObject *enemy = new EnemyObject("Assets/demon.png", Vector2(300, 300));
	AddGameObject(enemy->position, enemy);

	EnemyObject *enemy2 = new EnemyObject("Assets/chort.png", Vector2(250, 400));
	AddGameObject(enemy2->position, enemy2);

	EnemyObject *enemy3 = new EnemyObject("Assets/orc.png", Vector2(400, 250));
	AddGameObject(enemy3->position, enemy3);
}

void GameManager::AddGameObject(Vector2 pos, GameObject* o)
{
	float centerX = (o->position.x+10 + GameMap::tileSize / 2);
	float centerY = (o->position.y+30 + GameMap::tileSize / 2);
	o->AddCollider(std::make_unique<Circle>(Vector2(centerX, centerY), 20));
	physics->AddToAllObjects(o);
	std::cout << "GameObject Added!" << std::endl;
}

void GameManager::AddProjectile(Vector2 direction, GameObject *o)
{
	o->AddCollider(std::make_unique<Circle>(player->GetCollider()->pos, 8));
	physics->AddToAllObjects(o);
	std::cout << "Projectile Added!" << std::endl;
}

void GameManager::AddPlayerObject(Vector2 pos, GameObject * o)
{
	float centerX = (o->position.x+20 + GameMap::tileSize / 2);
	float centerY = (o->position.y+10 + GameMap::tileSize / 2);
	o->AddCollider(std::make_unique<Circle>(Vector2(centerX, centerY), 16));
	physics->AddToAllObjects(o);
	std::cout << "PlayerObject Added!" << std::endl;
}
