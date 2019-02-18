#include "ObjectManager.h"

ObjectManager::ObjectManager()
{
	playerObject = new PlayerObject("Assets/manTEST.png", 32, 48);
}

ObjectManager::~ObjectManager()
{
	delete playerObject;
}

void ObjectManager::UpdatePlayerVelX(float x)
{
	playerObject->UpdateVelX(x);
}

void ObjectManager::UpdatePlayerVelY(float y)
{
	playerObject->UpdateVelY(y);
}

void ObjectManager::UpdatePlayer()
{
	playerObject->Update();
}

void ObjectManager::RenderPlayer()
{
	playerObject->Render();
}

const SDL_Rect& ObjectManager::GetPlayerDestRect()
{
	return playerObject->GetDestRect();
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
