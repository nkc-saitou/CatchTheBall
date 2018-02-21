#pragma once

#include <vector>
#include "Object.h"

class ObjectManager
{
public:
	ObjectManager();
	~ObjectManager();
	
	void Update();	//çXêV
	void Add(Object* obj);
private:
	void Draw();	//ï\é¶

	std::vector<Object> objList;
};