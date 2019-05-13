#include "Food.h"
#include "TextureManager.h"

Food::Food(Vector2 pos, FoodType f) : GameObject("DauntingDungeon/Assets/collectables/ChickenLeg.png", pos, food)
{
	inverseMass = 0.005;

	destRect.h = 35;
	destRect.w = 35;
	switch (f) {
	case chickenLeg: 
		break;
	case fishSteak: objTexture =  TextureManager::GetTexture("DauntingDungeon/Assets/collectables/FishSteak.png");
		break;
	case Jerky: objTexture = TextureManager::GetTexture("DauntingDungeon/Assets/collectables/Jerky.png");
		break;
	}
}
