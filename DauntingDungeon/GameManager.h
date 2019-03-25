#pragma once
#include <memory>
#include "PhysicsManager.h"
#include "GameObject.h"

class PlayerObject;

class GameManager {
public:
	GameManager();
	~GameManager();

	void Initialise();

	void AddGameObject(Vector2 pos, GameObject* o);
	void AddProjectile(Vector2 direction, GameObject *o);
	void AddPlayerObject(Vector2 pos, GameObject* o);
	PhysicsManager* GetPhysicsManager() { return physics; }
	PlayerObject* GetPlayer() { return player; }
private:
	PlayerObject* player;
	PhysicsManager* physics;
};