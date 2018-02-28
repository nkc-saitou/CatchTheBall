#pragma once

#include "Object.h"
#include "SceneMgr.h"
#include <vector>

using namespace std;

class ObjectManager
{
public:
	ObjectManager();
	ObjectManager(eScene SceneName);
	~ObjectManager();
	
	void Update();	//çXêV
	void Add(Object* obj);	//í«â¡

private:
	void Draw();	//ï\é¶

	vector<Object*> objectArry;
};