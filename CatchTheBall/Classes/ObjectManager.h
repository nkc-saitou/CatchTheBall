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
	
	void Update();	//更新
	void Add(Object* obj);	//追加

private:
	void Draw();	//表示

	vector<Object*> objectArry;
};