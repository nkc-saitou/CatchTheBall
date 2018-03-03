#pragma once
#include <vector>
#include "Collision.h"
#include "Singleton.h"
#include "Object.h"

class Collision;
class CollisionManager : public Singleton<CollisionManager>
{

public:
	std::vector<Collision*> collision;
	void HitCollision();
	void hit(Collision* a, Collision* b);

private:

	bool HitBoxToBox(Collision firstCollision, Collision secondCollision);
	bool HitCircleToCircle(Collision firstCollision, Collision secondCollision);
	bool HitCircleToBox(Collision firstCollision, Collision secondCollision);
};
