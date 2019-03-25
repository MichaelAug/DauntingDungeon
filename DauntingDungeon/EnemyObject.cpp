#include "EnemyObject.h"

EnemyObject::EnemyObject(const std::string textureName, Vector2 pos) : GameObject(textureName, pos)
{
	inverseMass = 0.001;
	elasticity = 0.5f;
	time = SDL_GetTicks();
	direction = Vector2(((rand() % 10) - 5)*0.1, ((rand() % 10) - 5)*0.1);
}

void EnemyObject::UpdateObject()
{
	if (SDL_GetTicks() - time > 1000) {
		direction = Vector2(((rand() % 10) - 5)*0.1, ((rand() % 10) - 5)*0.1);
		time = SDL_GetTicks();
	}
	force += direction;

	UpdateTexPos();
}