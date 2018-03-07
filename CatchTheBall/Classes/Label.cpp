#include "Label.h"
#include "DxLib.h"

Label::Label(int handle, int order) : Object(order)
{
	GraphHandle(handle);

	int w = 0, h = 0;
	GetGraphSize(handle, &w, &h);
	GraphWidth(w); GraphHeight(h);
}
Label::Label(int handle, float x, float y, int order) : Object(order)
{
	GraphHandle(handle);
	PositionX(x); PositionY(y);

	int w = 0, h = 0;
	GetGraphSize(handle, &w, &h);
	GraphWidth(w); GraphHeight(h);
}
Label::Label(int handle, float x, float y, double degree, double scale, int order) : Object(order)
{
	GraphHandle(handle);
	PositionX(x); PositionY(y);
	Rotation(degree); Scale(scale);

	int w = 0, h = 0;
	GetGraphSize(handle, &w, &h);
	GraphWidth(w); GraphHeight(h);
}
Label::~Label(){}