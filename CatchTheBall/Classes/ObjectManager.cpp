#include "ObjectManager.h"
#include "DxLib.h"
#include <algorithm>

ObjectManager::ObjectManager()
{
}
ObjectManager::ObjectManager(eScene SceneName)
{
	//“Ç‚Ýž‚Ý

}
ObjectManager::~ObjectManager()
{
	//”jŠü
}
//---------------------------------------------------------
//	Public
//---------------------------------------------------------
void ObjectManager::Update() //XV
{
	//XV
	for (auto obj : objectArry)
	{
		obj->Update();
	}

	//•`‰æ
	Draw();
}
//---------------------------------------------------------
//	Object’Ç‰Á
//---------------------------------------------------------
void ObjectManager::Add(Object* obj)
{
	if (&obj == nullptr) return;

	objectArry.push_back(obj);

}
//---------------------------------------------------------
//	•`‰æ
//---------------------------------------------------------
void ObjectManager::Draw()
{
	//‰æ–Ê‚ð‰Šú‰»
	ClearDrawScreen();

	//•`‰æ
	for (auto obj : objectArry)
	{
		obj->Draw();
	}
	
	//•\Ž¦
	ScreenFlip();
}