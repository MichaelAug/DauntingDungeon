#pragma once
#include "PlayerObject.h"
#include <vector>
#include <memory>

class ObjectManager {
public:
	ObjectManager();
	~ObjectManager();

	void UpdateObjects();
	void RenderObjects();
private:
	std::vector<std::unique_ptr<GameObject>> gameObjects;
};