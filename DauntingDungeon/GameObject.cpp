#include "GameObject.h"
#include "TextureManager.h"
#include "Engine.h"

GameObject::GameObject(const std::string textureName, Vector2 pos, GameObjectType type) : 
	PhysicsObject(pos), 
	objTexture(TextureManager::GetTexture(textureName.c_str())), 
	type(type)
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

void GameObject::MovePosAndCol(Vector2 posChange)
{
	collider->pos += posChange;
	position += posChange;
}

void GameObject::UpdateTexPos()
{
	destRect.x = (int)position.x;
	destRect.y = (int)position.y;
}

void GameObject::Render()
{
	TextureManager::Draw(objTexture.get(), srcRect, destRect);
}

void GameObject::UpdateObject()
{
	UpdateTexPos();
}

void GameObject::AddCollider(std::unique_ptr<Collidable> col)
{
	collider = col.release();
}
