#include "MapObject.h"
#include "Collision.h"

MapObject::MapObject(float x, float y, double scale, int handle, int order) : Object(order)
{
	PositionX(x); PositionY(y);
	Scale(scale);
	GraphHandle(handle);

	col = new Collision(GraphWidth() / 2, GraphHeight() / 2, GraphWidth(), GraphHeight(), CollisionType::Square, this, [this](auto other) {});
}
MapObject::~MapObject()
{
	delete col;
}