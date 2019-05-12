#include "EnemyObject.h"
#include "GameObjectType.h"

EnemyObject::EnemyObject(const std::string textureName, Vector2 pos) : GameObject(textureName, pos, enemy)
{
	inverseMass = 0.001;
	elasticity = 1;
	time = SDL_GetTicks();
	direction = Vector2(((rand() % 10) - 5)*0.1, ((rand() % 10) - 5)*0.1);
}

bool EnemyObject::UpdateObject()
{
	if (SDL_GetTicks() - time > 1000) {
		direction = Vector2(((rand() % 10) - 5)*0.1, ((rand() % 10) - 5)*0.1);
		time = SDL_GetTicks();
	}
	force += direction;

	UpdateTexPos();
	return true;
}
