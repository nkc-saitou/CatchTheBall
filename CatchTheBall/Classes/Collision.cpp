#include "Collision.h"


Collision::Collision(float x, float y, float sizeX, float sizeY, CollisionType type, Object* object, void(*func)(Collision))
{
	Collision::x = x;
	Collision::y = y;
	Collision::sizeX = sizeX;
	Collision::sizeY = sizeY;
	Collision::type = type;
	Collision::object = object;
	Collision::onHit = func;

	CollisionManager::Instance()->collision.push_back(this);
}

Collision::~Collision()
{
	auto itr = CollisionManager::Instance()->collision.begin();
	while (itr != CollisionManager::Instance()->collision.end())
	{
		if ((*itr) == this)
		{
			itr = CollisionManager::Instance()->collision.erase(itr);
		}
		else
		{
			itr++;
		}
	}
}
