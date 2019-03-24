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

void GameObject::UpdateTexturePos()
{
	destRect.x = position.x;
	destRect.y = position.y;

}

void GameObject::Render()
{
	TextureManager::Draw(objTexture.get(), srcRect, destRect);
}

void GameObject::AddCollider(std::unique_ptr<Collidable> col)
{
	collider.reset(col.release());
}
