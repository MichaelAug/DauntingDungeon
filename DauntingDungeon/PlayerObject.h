#pragma once
#include "GameObject.h"

class PlayerObject : public GameObject {
public:
	PlayerObject(const char* textureName, int x, int y);
	void Update(const float &x, const float &y);
private:
};