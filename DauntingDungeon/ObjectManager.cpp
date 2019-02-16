#include "ObjectManager.h"

ObjectManager::ObjectManager()
{
	playerObject = new PlayerObject("Assets/player.png", 50, 50);
}

ObjectManager::~ObjectManager()
{
	delete playerObject;
}

void ObjectManager::UpdatePlayer(const float &x, const float &y)
{
	playerObject->Update(x,y);  // FIX THIS
}

void ObjectManager::RenderPlayer()
{
	playerObject->Render();
}

void ObjectManager::UpdateObjects()
{
	for (auto o : gameObjects) {
		//o->Update();
	}
}

void ObjectManager::RenderObjects()
{
	for (auto o : gameObjects) {
		o->Render();
	}
}
