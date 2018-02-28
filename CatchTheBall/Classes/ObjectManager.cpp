#include "ObjectManager.h"
#include "DxLib.h"
#include <algorithm>

ObjectManager::ObjectManager()
{
}
ObjectManager::ObjectManager(eScene SceneName)
{
	//読み込み

}
ObjectManager::~ObjectManager()
{
	//破棄
}
//---------------------------------------------------------
//	Public
//---------------------------------------------------------
void ObjectManager::Update() //更新
{
	//更新
	for (auto obj : objectArry)
	{
		obj->Update();
	}

	//描画
	Draw();
}
//---------------------------------------------------------
//	Object追加
//---------------------------------------------------------
void ObjectManager::Add(Object* obj)
{
	if (&obj == nullptr) return;

	objectArry.push_back(obj);

}
//---------------------------------------------------------
//	描画
//---------------------------------------------------------
void ObjectManager::Draw()
{
	//画面を初期化
	ClearDrawScreen();

	//描画
	for (auto obj : objectArry)
	{
		obj->Draw();
	}
	
	//表示
	ScreenFlip();
}