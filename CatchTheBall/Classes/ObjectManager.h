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
	
	void Initialize();	//‰Šú‰»
	void Update();		//XV
	void Add(Object*);	//’Ç‰Á
	void Draw();		//•\¦

private:
	vector<Object*> objectArry;
};