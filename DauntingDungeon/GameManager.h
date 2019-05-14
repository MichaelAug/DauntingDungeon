#pragma once
#include <memory>
#include "PhysicsManager.h"
#include "GameObject.h"
#include "GameMap.h"

class PlayerObject;
class AudioManager;
class GameManager {
	friend class InputManager;
public:
	GameManager(AudioManager* audioManager);

	void FoodConsumed() { --foodNum; }
	void EnemyKilled() { --enemyNum; }
	void SpawnNewObjects();
	void UpdateTimers();
	virtual ~GameManager();
	bool CheckIfCollides(GameObject* g, Collidable* col);
	void SpawnFood();
	void SpawnEnemy(int num);
	void RestartGame();
	void Initialise();
	void Update(Uint32 dt);
	void Draw();
	void UpdateObjects();
	void AddTerrain(Collidable*);
	void AddGameObject(GameObject* o);
	void AddProjectile(Vector2 direction);
	void AddPlayerObject(GameObject* o);
	void AddEnemyObject(GameObject* o);
	PlayerObject& GetPlayer() { return *player; }
	void UpdateScore(int scr) { score = scr; }
	int GetLives() { return playerLives; }
	int GetScore() { return score; }
	int GetDied() { return died; }
	void UpdateLives(int lives);
	void TogglePause();
	bool GetPaused() { return paused; }
private:
	void DrawObjects();
	int score = 0;
	int playerLives;

	bool paused;
	bool died;

	int foodNum;
	float foodRespawn;
	float enemyRespawn;
	int enemyNum;

	float foodTimer;
	float enemyTimer;

	PlayerObject* player;

	std::vector<GameObject*> allObjects;
	std::vector<GameObject*> terrain;
	AudioManager* audio;
	std::unique_ptr<PhysicsManager> physics;

	std::unique_ptr<GameMap> map;
};