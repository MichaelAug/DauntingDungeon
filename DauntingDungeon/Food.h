#pragma once
#include "GameObject.h"
#include "Vector2.h"

enum FoodType {
	chickenLeg,
	fishSteak,
	Jerky
};

class Food : public GameObject {
public:
	Food(Vector2 pos, FoodType f);

protected:

};