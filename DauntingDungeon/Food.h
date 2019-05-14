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
class GameManager;
class Food : public GameObject {
public:
	Food(Vector2 pos, FoodType f, GameManager* g);
	void Consumed();

	bool UpdateObject();
	bool IsConsumed() { return consumed; }
protected:
	GameManager* game;
	bool consumed;
};