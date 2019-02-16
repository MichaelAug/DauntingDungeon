#include "GameObject.h"
#include "TextureManager.h"
#include "Engine.h"

GameObject::GameObject(const char * textureName, int x, int y)
{
	xpos = x;
	ypos = y;

	srcRect.h = 64;
	srcRect.w = 64;
	srcRect.x = 0;
	srcRect.y = 0;
	
	destRect.h = srcRect.h;
	destRect.w = srcRect.w;
	destRect.x = xpos;
	destRect.y = ypos;

	objTexture = TextureManager::GetTexture(textureName);
}

void GameObject::Update()
{

	/*TODO: Replace with intended enemy behavior*/
	xpos++;
	ypos++;
	destRect.x = xpos;
	destRect.y = ypos;

}

void GameObject::Render()
{
	SDL_RenderCopy(Engine::renderer, objTexture, &srcRect, &destRect);
}
