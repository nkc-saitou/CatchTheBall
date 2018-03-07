#pragma once

#include "Object.h"

class Label : public Object
{
public:
	Label(int handle, int order = 0);
	Label(int handle, float x, float y, int order = 0);
	Label(int handle, float x, float y, double degree, double scale, int order = 0);
	~Label();
};