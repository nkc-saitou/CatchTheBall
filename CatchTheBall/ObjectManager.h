#pragma once

#include <vector>
#include "Object.h"

class ObjectManager
{
public:
	ObjectManager();
	~ObjectManager();
	
	void Update();	//�X�V
	void Add(Object* obj);
private:
	void Draw();	//�\��

	std::vector<Object> objList;
};