#pragma once
#include "SDL.h"
#include <memory>
#include <string>
#include "PhysicsObject.h"
#include "Collidable.h"

/*Handles Object's texture (setup and Rendering), its position and a reference to collider*/

class GameObject : public PhysicsObject{
public:
	GameObject(const std::string textureName, Vector2 pos);
	~GameObject();
	virtual void Update();
	void Render();

protected:
	std::shared_ptr<Collidable> collider; //shared because will need reference for collision detection

	std::unique_ptr<SDL_Texture, void(*)(SDL_Texture*)> objTexture;
	SDL_Rect srcRect, destRect; /*Position of the texture*/
};