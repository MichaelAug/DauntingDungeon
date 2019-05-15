#pragma once
#include "SDL2/SDL.h"
#include <vector>
#include "Square.h"
#include "Circle.h"
#include <memory>
#include "GameObject.h"
#include "Vector2.h"
#include "CollisionEffects.h"

struct collision {
	GameObject* obj1;
	GameObject* obj2;
	Vector2 normal;
	float penetration;
};
class CollisionEffects;
class CollisionManager {
	friend class PhysicsManager;
	friend class GameMap; //refactor to not need this
protected:
	std::vector<collision*> collisions;

	static float CalculateImpulse(const GameObject * a, const GameObject * b, Vector2&normal);
public:
	void HandleCollisionResolution();
	void AddCollision(collision*);

	bool AABB(const Square *a, const Square *b, Vector2 &normal, float &penDist);
	bool SphereCollision(const Circle *a, const Circle *b, Vector2 &normal, float &penDist);
	bool CircleSquareCollision(const Square * square,
		const Circle * circle, Vector2 &normal, float &penDist);
	void ObjectTerrainCollision(std::vector<GameObject*>& allObjects, std::vector<GameObject*>& terrain);
	void CollisionDetection(std::vector<GameObject*> &allObjects, std::vector<GameObject*>& terrain);
	void ObjectCollision(std::vector<GameObject*> &allObjects);
	void CollisionChecking(GameObject* a, GameObject* b);
	CollisionManager() {}

	bool CheckIfCollides(GameObject* g, std::vector<GameObject*>& allObjects);
private:
	
	
};