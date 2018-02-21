#include "Collision.h"

Collision::Collision(float x, float y, float sizeX, float sizeY, CollisionType type, void* object)
{
	Collision::x = x;
	Collision::y = y;
	Collision::sizeX = sizeX;
	Collision::sizeY = sizeY;
	Collision::type = type;
	Collision::object = object;
}