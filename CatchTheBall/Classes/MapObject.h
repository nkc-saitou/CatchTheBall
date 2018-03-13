#pragma once

#include "Object.h"

class MapObject : public Object
{
public:
	MapObject(float x, float y, double scale, int handle, int order = -1);
	~MapObject();

	Collision* col;

private:

};