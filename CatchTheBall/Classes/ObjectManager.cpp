#include "ObjectManager.h"
#include "DxLib.h"
#include "Camera.h"

//---------------------------------------------------------
//	初期化
//---------------------------------------------------------
void ObjectManager::Initialize()
{
	//配置
}
//---------------------------------------------------------
//	終了処理
//---------------------------------------------------------
void ObjectManager::Finalize()
{
	//要素の全削除
	while (objectArry.empty()) {
		auto obj = objectArry.end();
		//objectArry.pop_back();
		delete &obj;
	}
}
//---------------------------------------------------------
//	Objectの追加
//	・Priority(優先順位)が低いものから挿入
//---------------------------------------------------------
void ObjectManager::Add(Object* object)
{
	if (object == nullptr) return;
	//空っぽの時
	if (objectArry.empty())
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
	//挿入
	objectArry.insert(it, object);
}
//---------------------------------------------------------
//	削除
//---------------------------------------------------------
void ObjectManager::Destroy(Object* object)
{
	if (object == nullptr) return;
	if (objectArry.empty()) return;

	auto itr = objectArry.begin();
	while (itr != objectArry.end()) 
	{
		if (*itr == object) break;
		else itr++;
	}
	objectArry.erase(itr);
}
//---------------------------------------------------------
//	更新
//---------------------------------------------------------
void ObjectManager::Update()
{
	if (isStop) return;
	//更新
	for (auto obj : objectArry) {
		obj->Update();
	}
	//描画
	Draw();
}
//---------------------------------------------------------
//	更新の停止(UI以外)
//---------------------------------------------------------
void ObjectManager::Stop()
{
	isStop = true;
}
//---------------------------------------------------------
//	更新の再開(UI以外)
//---------------------------------------------------------
void ObjectManager::Reopening()
{
	isStop = false;
}
//---------------------------------------------------------
//	描画
//---------------------------------------------------------
void ObjectManager::Draw()
{
	//if (Camera::MainCamera == nullptr)  {
	//	//カメラ無
	//	for (auto obj : objectArry) {
	//		obj->Draw();
	//	}
	//}
	//else {
	//	//カメラ有
	//	Camera::MainCamera->DrawScreen(objectArry);
	//}
}