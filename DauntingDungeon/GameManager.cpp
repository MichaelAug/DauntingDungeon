#include "GameManager.h"
#include "Circle.h"
#include "PlayerObject.h"
#include "PhysicsManager.h"
#include "EnemyObject.h"
#include "GameMap.h"
#include "Projectile.h"
#include "Food.h"

GameManager::GameManager() : physics(std::make_unique<PhysicsManager>()),
map(std::make_unique<GameMap>())
{
	playerLives = 3;
	score = 0;
	died = false;
	paused = false;
	foodNum = 0;
	enemyNum = 0;
}

GameManager::~GameManager()
{
}

bool GameManager::CheckIfCollides(GameObject* g, Collidable* col)
{
	g->AddCollider(col);
	
	return physics->CheckIfCollides(g, terrain);;
}

void GameManager::SpawnFood()
{
	bool placed = false;
	std::srand(SDL_GetTicks());
	int r = rand() % 9;

	for(int i=0; i<1; i++) {
		placed = false;
		r = rand() % 9;
		while (!placed) {
			float randomX = 32.0f + (rand() % map->mapWidth * 32) - map->tileSize;
			float randomY = 32.0f + (rand() % map->mapHeight * 32) - map->tileSize;

			Food* f = new Food(Vector2(randomX, randomY), (FoodType)r);
			float centerX = (f->position.x + GameMap::tileSize / 2);
			float centerY = (f->position.y + GameMap::tileSize / 2);
			Collidable* col = new Circle(Vector2(centerX, centerY), 16);
			if (CheckIfCollides(f, col)) {
				delete f;
			}
			else {
				placed = true;
				std::cout << f->position << std::endl;
				allObjects.emplace_back(f);
				++foodNum;
			}
		}
	}
	
}

void GameManager::SpawnEnemy(int num)
{
	bool placed = false;
	std::srand(SDL_GetTicks());
	int r = rand() % 3;

	for (int i = 0; i < num; i++) {
		placed = false;
		r = rand() % 3;
		while (!placed) {
			float randomX = 32.0f + (rand() % map->mapWidth * 32) - map->tileSize;
			float randomY = 32.0f + (rand() % map->mapHeight * 32) - map->tileSize;
			
			EnemyObject* f = new EnemyObject(Vector2(randomX, randomY), (EnemyType)r, player);
			float centerX = (f->position.x + GameMap::tileSize / 2);
			float centerY = (f->position.y + GameMap::tileSize / 2);
			Collidable* col = new Square(Vector2(centerX - 10, centerY - 10), 16, 16);;
			if (f->enemyType == demon) {
				delete col;
				col = new Square(Vector2(centerX+15, centerY+20), 20, 20);
			}
			else if (f->enemyType == orc) {
				delete col;
				col = new Square(Vector2(centerX + 10, centerY + 10), 16, 16);
			}
			else if (f->enemyType == chort) {
				delete col;
				col = new Square(Vector2(centerX + 10, centerY + 10), 16, 16);
			}

			if (CheckIfCollides(f, col) || Distance(player->position, f->position) < 400) {
				delete f;
			}
			else {
				placed = true;
				allObjects.emplace_back(f);
				++enemyNum;
			}
		}
	}
}

void GameManager::RestartGame()
{
	for (auto o = allObjects.begin(); o != allObjects.end();) {
		delete (*o);
		o = allObjects.erase(o);
	}
	Initialise();
	died = false;
	paused = false;
}

void GameManager::Initialise()
{
	map->LoadMap(*this);

	player = new PlayerObject(Vector2(400, 300));

	AddPlayerObject(player);

	/*EnemyObject *enemy = new EnemyObject(Vector2(300, 500), demon, player);
	AddEnemyObject(enemy);

	EnemyObject *enemy2 = new EnemyObject(Vector2(250, 400), orc, player);
	AddEnemyObject(enemy2);

	EnemyObject *enemy3 = new EnemyObject(Vector2(400, 450), chort, player);
	AddEnemyObject(enemy3);*/

	SpawnFood();
	SpawnEnemy(5);
}

void GameManager::Update(Uint32 dt)
{
	UpdateScore(player->GetScore());
	UpdateLives(player->GetLives());

	if (!paused) {
		physics->FixedUpdate(dt, allObjects, terrain);
		UpdateObjects();
	}
	
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
	//std::cout << "GameObject Added!" << std::endl;
}

void GameManager::AddProjectile(Vector2 direction)
{
	Projectile *p = new Projectile("DauntingDungeon/Assets/projectile.png", player->GetPosition(), direction);

	p->AddCollider(new Circle(player->GetCollider()->pos - Vector2(2,10), 12));
	allObjects.emplace_back(p);
	//std::cout << "Projectile Added!" << std::endl;
}

void GameManager::AddPlayerObject(GameObject * o)
{
	float centerX = (o->position.x+1 + GameMap::tileSize / 2);
	float centerY = (o->position.y+12 + GameMap::tileSize / 2);
	o->AddCollider(new Circle(Vector2(centerX, centerY), 16));
	allObjects.emplace_back(o);
	//std::cout << "PlayerObject Added!" << std::endl;
}

void GameManager::AddEnemyObject(GameObject* o)
{
	float centerX = (o->position.x +10+ GameMap::tileSize / 2);
	float centerY = (o->position.y+25 + GameMap::tileSize / 2);
	EnemyObject* eo = dynamic_cast<EnemyObject*>(o);

	if (eo->enemyType == demon) {
		o->AddCollider(new Square(Vector2(centerX, centerY), 20, 20));
	}
	else if (eo->enemyType == orc) {
		o->AddCollider(new Square(Vector2(centerX-10, centerY-10), 16, 16));
	}
	else if (eo->enemyType == chort) {
		o->AddCollider(new Square(Vector2(centerX - 10, centerY - 10), 16, 16));
	}
	
	allObjects.emplace_back(o);
	//std::cout << "Enemy Added!" << std::endl;
}

void GameManager::UpdateLives(int lives)
{
	playerLives = lives;
	if (lives == 0) {
		died = true;
		paused = true;
	}
}

void GameManager::TogglePause()
{
	if (paused) {
		paused = false;
	}
	else {
		paused = true;
	}
}

void GameManager::DrawObjects()
{
	for (auto& o : allObjects) {
		o->Render();
	}
}
