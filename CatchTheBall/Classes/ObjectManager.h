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
	
	void Initialize();	//������
	void Update();		//�X�V
	void Add(Object*);	//�ǉ�
	void Draw();		//�\��

private:
	vector<Object*> objectArry;
};