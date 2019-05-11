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

	player = std::make_unique<PlayerObject>("DauntingDungeon/Assets/man.png", Vector2(400, 300));

	AddPlayerObject(player.get());

	EnemyObject *enemy = new EnemyObject("DauntingDungeon/Assets/demon.png", Vector2(300, 300));
	AddGameObject(enemy);

	EnemyObject *enemy2 = new EnemyObject("DauntingDungeon/Assets/chort.png", Vector2(250, 400));
	AddGameObject(enemy2);

	EnemyObject *enemy3 = new EnemyObject("DauntingDungeon/Assets/orc.png", Vector2(400, 250));
	AddGameObject(enemy3);
}

void GameManager::Update(Uint32 dt)
{
	UpdateObjects();
	physics->FixedUpdate(dt, allObjects, terrain);
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

void GameManager::AddTerrain(Collidable* c)
{
	GameObject* g = new GameObject(wall);
	g->AddCollider(c);
	terrain.emplace_back(g);
}

void GameManager::AddGameObject(GameObject* o)
{
	float centerX = (o->position.x+10 + GameMap::tileSize / 2);
	float centerY = (o->position.y+30 + GameMap::tileSize / 2);
	o->AddCollider(new Circle(Vector2(centerX, centerY), 20));
	allObjects.emplace_back(o);
	std::cout << "GameObject Added!" << std::endl;
}

void GameManager::AddProjectile(Vector2 direction)
{
	Projectile *p = new Projectile("DauntingDungeon/Assets/projectile.png", player->GetPosition()/*+direction*60*/, direction);

	p->AddCollider(new Circle(player->GetCollider()->pos, 8));
	allObjects.emplace_back(p);
	std::cout << "Projectile Added!" << std::endl;
}

void GameManager::AddPlayerObject(GameObject * o)
{
	float centerX = (o->position.x+20 + GameMap::tileSize / 2);
	float centerY = (o->position.y+10 + GameMap::tileSize / 2);
	o->AddCollider(new Circle(Vector2(centerX, centerY), 16));
	allObjects.emplace_back(o);
	std::cout << "PlayerObject Added!" << std::endl;
}

void GameManager::DrawObjects()
{
	for (auto& o : allObjects) {
		o->Render();
	}
}
