#include "MapObject.h"

MapObject::MapObject(float x, float y, double scale, int handle, int order) : Object(order)
{
	PositionX(x); PositionY(y);
	Scale(scale);
	GraphHandle(handle);
}
MapObject::~MapObject() { }