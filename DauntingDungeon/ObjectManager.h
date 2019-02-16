#pragma once
#include "PlayerObject.h"

#include <vector>

class ObjectManager {
public:
	ObjectManager();
	~ObjectManager();
	void UpdatePlayer(const float &x, const float &y);
	void RenderPlayer();
	void UpdateObjects();
	void RenderObjects();
	PlayerObject* playerObject;
private:
	std::vector<GameObject*> gameObjects;
	
};