#include "GameManager.h"
#include "Circle.h"
#include "PlayerObject.h"
#include "PhysicsManager.h"
#include "EnemyObject.h"
#include "GameMap.h"
#include "Projectile.h"

GameManager::GameManager() : physics(std::make_unique<PhysicsManager>()),
map(std::make_unique<GameMap>())
{
}

GameManager::~GameManager()
{
}

void GameManager::Initialise()
{
	map->LoadMap(*this);

	player = std::make_unique<PlayerObject>("Assets/man.png", Vector2(32, 48));

	AddPlayerObject(player->position,player.get());

	EnemyObject *enemy = new EnemyObject("Assets/demon.png", Vector2(300, 300));
	AddGameObject(enemy->position, enemy);

	EnemyObject *enemy2 = new EnemyObject("Assets/chort.png", Vector2(250, 400));
	AddGameObject(enemy2->position, enemy2);

	EnemyObject *enemy3 = new EnemyObject("Assets/orc.png", Vector2(400, 250));
	AddGameObject(enemy3->position, enemy3);
}

void GameManager::Update(Uint32 dt)
{
	UpdateObjects();
	physics->UpdatePhysics(dt, allObjects, terrain);
}

void GameManager::Draw()
{
	map->DrawMap();
	DrawObjects();
}

void GameManager::UpdateObjects()
{
	for (auto& o : allObjects) {
		o->UpdateObject();
	}
}

void GameManager::AddTerrain(std::shared_ptr<Collidable> c)
{
	terrain.emplace_back(c);
}

void GameManager::AddGameObject(Vector2 pos, GameObject* o)
{
	float centerX = (o->position.x+10 + GameMap::tileSize / 2);
	float centerY = (o->position.y+30 + GameMap::tileSize / 2);
	o->AddCollider(std::make_unique<Circle>(Vector2(centerX, centerY), 20));
	allObjects.emplace_back(o);
	std::cout << "GameObject Added!" << std::endl;
}

void GameManager::AddProjectile(Vector2 direction)
{
	Projectile *p = new Projectile("Assets/projectile.png", player->GetPosition()/*+direction*60*/, direction);

	p->AddCollider(std::make_unique<Circle>(player->GetCollider()->pos, 8));
	allObjects.emplace_back(p);
	std::cout << "Projectile Added!" << std::endl;
}

void GameManager::AddPlayerObject(Vector2 pos, GameObject * o)
{
	float centerX = (o->position.x+20 + GameMap::tileSize / 2);
	float centerY = (o->position.y+10 + GameMap::tileSize / 2);
	o->AddCollider(std::make_unique<Circle>(Vector2(centerX, centerY), 16));
	allObjects.emplace_back(o);
	std::cout << "PlayerObject Added!" << std::endl;
}

void GameManager::DrawObjects()
{
	for (auto& o : allObjects) {
		o->Render();
	}
}
