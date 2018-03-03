#pragma once
#include "DxLib.h"
#include "CollisionManager.h"
#include "Object.h"

enum CollisionType
{
	Square,
	Circle
};

class CollisionManager;
class Collision
{
public:

	void (*onHit)(Collision);
	Collision(float x, float y, float sizeX, float sizeY, CollisionType type, Object* object, void (*func)(Collision));
	float getX() { return x; }
	float getY() { return y; }
	float getSizeX() { return sizeX; }
	float getSizeY() { return sizeY; }
	CollisionType getType() { return type; }
	Object* getObject() { return object; }

	~Collision();

private:
	float x, y;
	float sizeX, sizeY;
	CollisionType type;
	Object* object;
	
};