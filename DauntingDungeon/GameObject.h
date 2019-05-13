#pragma once
#include "SDL.h"
#include <memory>
#include <string>
#include "PhysicsObject.h"
#include "Collidable.h"
#include "GameObjectType.h"

/*Handles Object's texture (setup and Rendering), its position and a reference to collider*/

struct Animation;
class GameObject : public PhysicsObject{
	friend class PhysicsManager;
	friend class GameManager;
	friend class InputManager;
public:
	int animIndex = 0;
	GameObject(const std::string textureName, Vector2 pos, GameObjectType type);
	GameObject(GameObjectType type);
	//~GameObject();
	void MovePosAndCol(Vector2 posChange);
	void UpdateTexPos();
	void Render();
	virtual bool UpdateObject();

	Collidable* GetCollider() { return collider; }

	void AddCollider(Collidable* col);
	GameObjectType type;
protected:
	SDL_RendererFlip spriteFlip = SDL_FLIP_NONE;
	float spriteRotation;
	Animation* anim;
	Vector2 animDirection;
	bool animated = false;

	Collidable* collider;
	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect; /*Position of the texture*/
};