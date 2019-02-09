#include "GameObject.h"

GameObject::GameObject(const char * textureName, int x, int y)
{
	xpos = x;
	ypos = y;

	objTexture = TextureManager::GetTexture(textureName);
	
}

void GameObject::Update()
{
	xpos++;
	ypos++;

	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.h = srcRect.h * 2;
	destRect.w = srcRect.w * 2;
	
}

void GameObject::Render()
{
	SDL_RenderCopy(Engine::renderer, objTexture, NULL, &destRect);
}
