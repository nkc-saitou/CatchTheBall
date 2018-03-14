#include "MapObject.h"

MapObject::MapObject(float x, float y, double scale, int handle, int order) : Object(order)
{
	PositionX(x); PositionY(y);
	Scale(scale);
	GraphHandle(handle);

	collider = new Collision(GraphWidth() / 2, GraphHeight() / 2, GraphWidth(), GraphHeight(), Square, this, [this](auto other) { });
	tag = GetTagName();
}
MapObject::~MapObject()
{
	delete collider;
}