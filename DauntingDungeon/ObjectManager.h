#pragma once
#include "PlayerObject.h"

#include <vector>

class ObjectManager {
public:
	ObjectManager();
	~ObjectManager();

	void UpdatePlayerVelX(float x);
	void UpdatePlayerVelY(float y);
	void UpdatePlayer();
	void RenderPlayer();
	const SDL_Rect& GetPlayerDestRect();

	void UpdateObjects();
	void RenderObjects();
private:
	std::vector<GameObject*> gameObjects;
	PlayerObject* playerObject;
};