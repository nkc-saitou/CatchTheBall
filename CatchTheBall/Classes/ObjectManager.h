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
	
	void Update();	//�X�V
	void Add(Object* obj);	//�ǉ�

private:
	void Draw();	//�\��

	vector<Object*> objectArry;
};