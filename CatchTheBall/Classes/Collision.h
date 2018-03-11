#pragma once
#include "DxLib.h"
#include "CollisionManager.h"
#include "Object.h"
#include <functional>

enum CollisionType
{
	Square,
	Circle
};

class CollisionManager;
class Collision
{
public:
	Collision() {}

	function<void(Collision*)> onHit;

	Collision(float x, float y, float sizeX, float sizeY, CollisionType type, Object* object, function<void(Collision*)> onHit);
	float getX() { return x; }
	float getY() { return y; }
	float getSizeX() { return sizeX; }
	float getSizeY() { return sizeY; }
	CollisionType getType() { return type; }
	Object* getObject() { return object; }

	void SetOnHit(function<void(Collision*)> onHit)
	{
		Collision::onHit = onHit;
	}

	void OnHit()
	{
		auto DummyCol = new Collision();
		onHit(DummyCol);
	}

	~Collision();

private:
	float x, y;
	float sizeX, sizeY;
	CollisionType type;
	Object* object;

};