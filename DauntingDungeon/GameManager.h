#pragma once
#include <memory>
#include "PhysicsManager.h"
#include "GameObject.h"

class GameManager {
public:
	GameManager();

	void Initialise();

	void AddGameObject(Vector2 pos, GameObject* o);

	PhysicsManager& GetPhysicsManager() { return *physics; }
	PlayerObject& GetPlayer() { return *player; }
private:
	std::unique_ptr<PlayerObject> player;
	std::unique_ptr<PhysicsManager> physics;
};