#pragma once
#include "GameObject.h"

enum VortexType {
	red
};

class Vortex : public GameObject {
public:
	Vortex(Vector2 pos, VortexType t);
};