#include "CollisionManager.h"
#include <iostream>
#include <algorithm>

void CollisionManager::Draw()
{
	for (auto& o : allObjects) {
		o->Render();
	}
}

void CollisionManager::AddTerrainCollider(std::shared_ptr<Collidable> col)
{
	terrain.emplace_back(col);
}

float CollisionManager::CalculateImpulse(const GameObject * a, const GameObject * b, Vector2 & normal)
{
	if (a != nullptr) {
		float e = (a->elasticity + b->elasticity) / 2;
		Vector2 vr = b->velocity - a->velocity;
		float dotProduct = vr.DotProduct(normal);
		auto j = (-(1 + e)*dotProduct) / (a->inverseMass + b->inverseMass);
		return j;
	}
	else {
		float e = b->elasticity;
		Vector2 vr = b->velocity;
		float dotProduct = vr.DotProduct(normal);
		auto j = (-(1 + e)*dotProduct) / (b->inverseMass);
		return j;
	}
}

void CollisionManager::HandleCollisionResolution()
{
	for (auto c = collisions.begin(); c != collisions.end();) {
		Vector2 posChange;
		if ((*c)->obj1 == nullptr) { //if this is null, means checking against terrain
			posChange = (*c)->normal * (*c)->penetration;
			float impulse = CalculateImpulse(nullptr, (*c)->obj2, (*c)->normal);
			(*c)->obj2->MovePosAndCol(posChange);
			(*c)->obj2->velocity += (*c)->normal*((*c)->obj2->inverseMass*impulse);
		}
		else {
			float mTotal = (*c)->obj1->inverseMass + (*c)->obj2->inverseMass;
			float impulse = CalculateImpulse((*c)->obj1, (*c)->obj2, (*c)->normal);

			posChange = (*c)->normal * (*c)->penetration * ((*c)->obj1->inverseMass / mTotal);
			(*c)->obj1->MovePosAndCol(posChange*(-1));
			(*c)->obj1->velocity -= (*c)->normal*((*c)->obj1->inverseMass*impulse);

			posChange = (*c)->normal * (*c)->penetration * ((*c)->obj2->inverseMass / mTotal);
			(*c)->obj2->MovePosAndCol(posChange);
			(*c)->obj2->velocity += (*c)->normal*((*c)->obj2->inverseMass*impulse);
		}
		c = collisions.erase(c);
	}
}

void CollisionManager::AddCollision(collision * c)
{
	collisions.emplace_back(c);
}

bool CollisionManager::AABB(const Square * a, const Square * b, Vector2 & normal, float & penDist)
{
	float distX = (b->pos.x - a->pos.x);
	float distY = (b->pos.y - a->pos.y);

	float halfX = (float)(a->GetHalfWidth()) + (float)(b->GetHalfWidth());
	float halfY = (float)(a->GetHalfHeight()) + (float)(b->GetHalfHeight());

	if (std::abs(distX) < halfX && std::abs(distY) < halfY) {
		if (halfX - std::abs(distX) > halfY - std::abs(distY)) {
			if (distY >= 0) {
				normal = Vector2(0, -1);
			}
			else {
				normal = Vector2(0, 1);
			}
			penDist = halfY - std::abs(distY);
		}
		else {
			//std::cout << "X";
			if (distX >= 0) {
				normal = Vector2(-1, 0);
			}
			else {
				normal = Vector2(1, 0);
			}
			penDist = halfX - std::abs(distX);
		}
		return true;
	}
	else {
		return false;
	}
}

bool CollisionManager::SphereCollision(const Circle * a, const Circle * b, Vector2 & normal, float & penDist)
{
	float dx = b->pos.x - a->pos.x;
	float dy = b->pos.y - a->pos.y;

	float radii = (float)(a->GetRadius() + b->GetRadius());
	float sqDist = (dx * dx + dy * dy);

	if (sqDist < radii * radii) {
		normal = Vector2(b->pos.x - a->pos.x, b->pos.y - a->pos.y);
		normal.Normalise();
		penDist = radii - std::sqrtf(sqDist);
		return true;
	}
	else {
		return false;
	}
}

bool CollisionManager::CircleSquareCollision(const Square * square, const Circle * circle, Vector2 & normal, float & penDist)
{
	float nearestX = std::max(square->pos.x - square->GetHalfWidth(),
		std::min(circle->pos.x, square->pos.x + square->GetHalfWidth()));
	float nearestY = std::max(square->pos.y - square->GetHalfHeight(),
		std::min(circle->pos.y, square->pos.y + square->GetHalfHeight()));

	float deltaX = circle->pos.x - nearestX;
	float deltaY = circle->pos.y - nearestY;

	float sqDist = pow(deltaX, 2) + pow(deltaY, 2);

	if (sqDist < pow(circle->GetRadius(), 2)) {
		normal = Vector2(circle->pos.x - nearestX, circle->pos.y - nearestY);
		normal.Normalise();
		float dist = std::sqrtf(sqDist);

		penDist = circle->GetRadius() - dist;
		return true;
	}
	else {
		return false;
	}
}

void CollisionManager::ObjectTerrainCollision(std::vector<GameObject*>& allObjects)
{
	for (size_t i = 0; i < allObjects.size(); ++i) {
		for (size_t j = 0; j < terrain.size(); ++j) {
			Vector2 normal;
			float penDist;

			ColliderType terType = terrain[j]->GetType();
			ColliderType objType = allObjects[i]->GetCollider()->GetType();

			/*Pass a nullptr to AddCollision if colliding with terrain (because it does not need to be moved)*/
			if (terType == square && objType == circle) {
				if (CircleSquareCollision(dynamic_cast<Square*>(terrain[j].get()), dynamic_cast<Circle*>
					(allObjects[i]->GetCollider()), normal, penDist)) {
					//std::cout << "collision happened";
					AddCollision(new collision{ nullptr,allObjects[i], normal,penDist });
				}
			}
			else if (terType == circle && objType == circle) {
				if (SphereCollision(dynamic_cast<Circle*>(terrain[j].get()), dynamic_cast<Circle*>
					(allObjects[i]->GetCollider()), normal, penDist)) {

					AddCollision(new collision{ nullptr,allObjects[i],normal,penDist });
				}
			}
			else if (terType == square && objType == square) {
				if (AABB(dynamic_cast<Square*>(allObjects[i]->GetCollider()), dynamic_cast<Square*>
					(terrain[j].get()), normal, penDist)) {

					AddCollision(new collision{ nullptr,allObjects[i],normal,penDist });
				}
			}
			else if (terType == circle && objType == square) {
				if (CircleSquareCollision(dynamic_cast<Square*>(allObjects[i]->GetCollider()),
					dynamic_cast<Circle*>(terrain[j].get()), normal, penDist)) {
					AddCollision(new collision{ nullptr,allObjects[i], normal,penDist });
				}
			}
		}
	}
}

void CollisionManager::CollisionDetection(std::vector<GameObject*>& allObjects)
{
	ObjectTerrainCollision(allObjects);
}
