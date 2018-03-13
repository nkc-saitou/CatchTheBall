#pragma once

#include "Object.h"
#include "Collision.h"

class MapObject : public Object
{
public:
	static const string GetTagName() { return "Wall"; }

	MapObject(float x, float y, double scale, int handle, int order = -1);
	~MapObject();

private:
	Collision *collider;
};