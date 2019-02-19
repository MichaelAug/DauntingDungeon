#pragma once
#include "PlayerObject.h"
#include <vector>

class ObjectManager {
public:
	ObjectManager();
	~ObjectManager();

	void UpdateObjects();
	void RenderObjects();
private:
	std::vector<GameObject*> gameObjects;
};