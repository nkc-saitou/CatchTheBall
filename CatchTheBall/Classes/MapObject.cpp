#include "MapObject.h"

MapObject::MapObject(float x, float y, double scale, int handle)
{
	Scale(scale);
	GraphHandle(handle);
	Priority(0);

}
MapObject::~MapObject() { }