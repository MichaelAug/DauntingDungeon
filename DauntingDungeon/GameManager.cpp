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

	player = std::make_unique<PlayerObject>(Vector2(400, 300));

	AddPlayerObject(player.get());

	EnemyObject *enemy = new EnemyObject(Vector2(300, 500), demon);
	AddEnemyObject(enemy);

	EnemyObject *enemy2 = new EnemyObject(Vector2(250, 400), orc);
	AddEnemyObject(enemy2);

	EnemyObject *enemy3 = new EnemyObject(Vector2(400, 450), chort);
	AddEnemyObject(enemy3);
}

void GameManager::Update(Uint32 dt)
{
	physics->FixedUpdate(dt, allObjects, terrain);
	UpdateObjects();
}

void GameManager::Draw()
{
	map->DrawMap();
	DrawObjects();
}

void GameManager::UpdateObjects()
{
	for (auto o = allObjects.begin(); o != allObjects.end();) {
		if (!(*o)->UpdateObject()) {
			delete (*o);
			o = allObjects.erase(o);
		}
		else {
			++o;
		}
	}
}

//void GameManager::DeleteExpired()
//{
//	for (auto a = allObjects.begin(); a != allObjects.end();) {
//		if ((*a)->ToDelete()) {
//
//		}
//	}
//}

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
	Projectile *p = new Projectile("DauntingDungeon/Assets/projectile.png", player->GetPosition(), direction);

	p->AddCollider(new Circle(player->GetCollider()->pos, 16));
	allObjects.emplace_back(p);
	std::cout << "Projectile Added!" << std::endl;
}

void GameManager::AddPlayerObject(GameObject * o)
{
	float centerX = (o->position.x+1 + GameMap::tileSize / 2);
	float centerY = (o->position.y+12 + GameMap::tileSize / 2);
	o->AddCollider(new Circle(Vector2(centerX, centerY), 16));
	allObjects.emplace_back(o);
	std::cout << "PlayerObject Added!" << std::endl;
}

void GameManager::AddEnemyObject(GameObject* o)
{
	float centerX = (o->position.x +10+ GameMap::tileSize / 2);
	float centerY = (o->position.y+25 + GameMap::tileSize / 2);
	EnemyObject* eo = dynamic_cast<EnemyObject*>(o);

	if (eo->enemyType == demon) {
		o->AddCollider(new Square(Vector2(centerX, centerY), 16, 16));
	}
	else if (eo->enemyType == orc) {
		o->AddCollider(new Square(Vector2(centerX-10, centerY-10), 16, 16));
	}
	else if (eo->enemyType == chort) {
		o->AddCollider(new Square(Vector2(centerX - 10, centerY - 10), 16, 16));
	}
	
	allObjects.emplace_back(o);
	std::cout << "Enemy Added!" << std::endl;
}

void GameManager::DrawObjects()
{
	for (auto& o : allObjects) {
		o->Render();
	}
}
