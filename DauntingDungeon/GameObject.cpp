#include "GameObject.h"
#include "TextureManager.h"
#include "Engine.h"

GameObject::GameObject(const char * textureName, int x, int y) : 
	objTexture(TextureManager::GetTexture(textureName))
{

	srcRect.h = 64;
	srcRect.w = 64;
	srcRect.x = 0;
	srcRect.y = 0;
	
	destRect.h = srcRect.h;
	destRect.w = srcRect.w;
	destRect.x = x;
	destRect.y = y;
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
