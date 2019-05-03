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
	void AddTerrain(std::shared_ptr<Collidable>);
	void AddGameObject(GameObject* o);
	void AddProjectile(Vector2 direction);
	void AddPlayerObject(GameObject* o);
	PlayerObject& GetPlayer() { return *player; }

private:
	void DrawObjects();

	std::unique_ptr<PlayerObject> player;

	std::vector<GameObject*> allObjects;
	std::vector<std::shared_ptr<Collidable>> terrain;

	std::unique_ptr<PhysicsManager> physics;

	std::unique_ptr<GameMap> map;
};