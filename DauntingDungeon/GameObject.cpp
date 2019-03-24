#include "GameObject.h"
#include "TextureManager.h"
#include "Engine.h"

GameObject::GameObject(const std::string textureName, Vector2 pos) : PhysicsObject(pos),
	objTexture(TextureManager::GetTexture(textureName.c_str()))
{

	srcRect.h = 64;
	srcRect.w = 64;
	srcRect.x = 0;
	srcRect.y = 0;
	
	destRect.h = srcRect.h;
	destRect.w = srcRect.w;
	destRect.x = position.x;
	destRect.y = position.y;
}

GameObject::~GameObject()
{
}

void GameObject::Update()
{
	/*TODO: Replace with intended enemy behavior*/
	destRect.x++;
	destRect.y++;

}

void GameObject::Render()
{
	TextureManager::Draw(objTexture.get(), srcRect, destRect);
}
