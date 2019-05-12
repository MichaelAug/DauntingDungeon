#include "GameObject.h"
#include "TextureManager.h"
#include "Engine.h"

GameObject::GameObject(const std::string textureName, Vector2 pos, GameObjectType type) :
	PhysicsObject(pos),
	type(type),
	objTexture(TextureManager::GetTexture(textureName.c_str()))
{
	srcRect.h = 64;
	srcRect.w = 64;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.h = srcRect.h;
	destRect.w = srcRect.w;
	destRect.x = (int)position.x;
	destRect.y = (int)position.y;
}

GameObject::GameObject(GameObjectType type) : objTexture(nullptr), PhysicsObject()
{
	srcRect.h = 64;
	srcRect.w = 64;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.h = srcRect.h;
	destRect.w = srcRect.w;
	destRect.x = (int)position.x;
	destRect.y = (int)position.y;

	this->type = type;
}

void GameObject::MovePosAndCol(Vector2 posChange)
{
	collider->pos += posChange;
	position += posChange;
}

void GameObject::UpdateTexPos()
{
	destRect.x = (int)position.x - Engine::camera.x;
	destRect.y = (int)position.y - Engine::camera.y;
}

void GameObject::Render()
{
	if (objTexture) {
		TextureManager::Draw(objTexture, srcRect, destRect);
	}
}

bool GameObject::UpdateObject()
{
	UpdateTexPos();

	std::cout << "updated" << std::endl;
	return true;
}

void GameObject::AddCollider(Collidable* col)
{
	collider = col;
}
