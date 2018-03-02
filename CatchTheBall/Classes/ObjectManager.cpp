#include "ObjectManager.h"
#include "DxLib.h"


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
//	Objectの追加
//	・Priority(優先順位)が低いものから挿入
//---------------------------------------------------------
void ObjectManager::Add(Object* object)
{
	if (&object == nullptr) return;
	//空っぽの時
	if (objectArry.begin() == objectArry.end())
	{
		objectArry.push_back(object);
		return;
	}
	//優先順位
	auto it = objectArry.begin();
	for (auto obj : objectArry)
	{
		if (obj->Priority() > object->Priority()) break;
		it++;
	}
	
	objectArry.insert(it, object);
}
//---------------------------------------------------------
//	更新
//---------------------------------------------------------
void ObjectManager::Update()
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