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
	
	void Initialize();	//初期化
	void Update();		//更新
	void Add(Object*);	//追加
	void Draw();		//表示

private:
	vector<Object*> objectArry;
};