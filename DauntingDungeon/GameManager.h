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
	void Update(Uint32 dt);
	void Draw();
	void UpdateObjects();
	void AddTerrain(std::shared_ptr<Collidable>);
	void AddGameObject(Vector2 pos, GameObject* o);
	void AddProjectile(Vector2 direction, GameObject *o);
	void AddPlayerObject(Vector2 pos, GameObject* o);
	PlayerObject* GetPlayer() { return player; }

private:
	void DrawObjects();

	PlayerObject* player;

	
	std::vector<GameObject*> allObjects;
	std::vector<std::shared_ptr<Collidable>> terrain;

	std::unique_ptr<CollisionManager> colManager;
	std::unique_ptr<PhysicsManager> physics; /*maybe possible to turn into static class?
											 or put CollisionManager back into PhysicsManager?*/
	std::unique_ptr<GameMap> map;
};