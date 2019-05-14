#include "Food.h"
#include "TextureManager.h"
#include "GameManager.h"

Food::Food(Vector2 pos, FoodType f, GameManager* g) : 
	GameObject("DauntingDungeon/Assets/collectables/ChickenLeg.png", pos, food)
{
	consumed = false;
	inverseMass = 0.005;
	game = g;
	destRect.h = 35;
	destRect.w = 35;
	switch (f) {
	case chickenLeg: 
		break;
	case fishSteak: objTexture =  TextureManager::GetTexture("DauntingDungeon/Assets/collectables/FishSteak.png");
		break;
	case Jerky: objTexture = TextureManager::GetTexture("DauntingDungeon/Assets/collectables/Jerky.png");
		break;
	case pepperoni: objTexture = TextureManager::GetTexture("DauntingDungeon/Assets/collectables/Pepperoni.png");
		break;
	case pieLemon: objTexture = TextureManager::GetTexture("DauntingDungeon/Assets/collectables/PieLemon.png");
		break;
	case piePumpkin: objTexture = TextureManager::GetTexture("DauntingDungeon/Assets/collectables/PiePumpkin.png");
		break;
	case potatoRed: objTexture = TextureManager::GetTexture("DauntingDungeon/Assets/collectables/PotatoRed.png");
		break;
	case pretzel: objTexture = TextureManager::GetTexture("DauntingDungeon/Assets/collectables/Pretzel.png");
		break;
	case ribs: objTexture = TextureManager::GetTexture("DauntingDungeon/Assets/collectables/Ribs.png");
	}
}

void Food::Consumed()
{
	consumed = true;
}

bool Food::UpdateObject()
{
	if (consumed) {
		game->FoodConsumed();
		return false;
	}

	UpdateTexPos();

	return true;
}
