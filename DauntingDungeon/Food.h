#pragma once
#include "GameObject.h"
#include "Vector2.h"

enum FoodType {
	chickenLeg,
	fishSteak,
	Jerky,
	pepperoni,
	pieLemon,
	piePumpkin,
	potatoRed,
	pretzel,
	ribs
};

class Food : public GameObject {
public:
	Food(Vector2 pos, FoodType f);

protected:

};