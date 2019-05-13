#pragma once
#include <memory>
#include "PhysicsManager.h"
#include "GameObject.h"
#include "GameMap.h"

class PlayerObject;

class GameManager {
public:
	GameManager();
	virtual ~GameManager();

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

	std::unique_ptr<PlayerObject> player;

	std::vector<GameObject*> allObjects;
	std::vector<GameObject*> terrain;

	std::unique_ptr<PhysicsManager> physics;

	std::unique_ptr<GameMap> map;
};