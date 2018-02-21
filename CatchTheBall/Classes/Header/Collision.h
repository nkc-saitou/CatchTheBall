#pragma once
#include "DxLib.h"
#include "Singleton.h"

enum CollisionType
{
	Square,
	Circle
};

class Collision : public Singleton <Collision>
{
public:
	Collision(float x, float y, float sizeX, float sizeY, CollisionType type, void* object);
	float getX() { return x; }
	float getY() { return y; }
	float getSize() { return sizeX; }
	float getSize() { return sizeY; }
	CollisionType getType() { return type; }
	void* getObject() { return object; }

private:
	float x, y;
	float sizeX, sizeY;
	CollisionType type;
	void* object;
};