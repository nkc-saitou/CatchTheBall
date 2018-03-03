#include "ObjectManager.h"
#include "DxLib.h"


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
//	‰Šú‰»
//---------------------------------------------------------
void ObjectManager::Initialize()
{
	//—v‘f‚Ìíœ
	while (objectArry.begin() != objectArry.end()) {
		auto obj = objectArry.end();
		objectArry.pop_back();
		delete &obj;
	}
}
//---------------------------------------------------------
//	Object‚Ì’Ç‰Á
//	EPriority(—Dæ‡ˆÊ)‚ª’á‚¢‚à‚Ì‚©‚ç‘}“ü
//---------------------------------------------------------
void ObjectManager::Add(Object* object)
{
	if (&object == nullptr) return;
	//‹ó‚Á‚Û‚ÌŽž
	if (objectArry.begin() == objectArry.end())
	{
		objectArry.push_back(object);
		return;
	}
	//—Dæ‡ˆÊ
	auto it = objectArry.begin();
	for (auto obj : objectArry)
	{
		if (obj->Priority() > object->Priority()) break;
		it++;
	}
	//‘}“ü
	objectArry.insert(it, object);
}
//---------------------------------------------------------
//	XV
//---------------------------------------------------------
void ObjectManager::Update()
{
	//XV
	for (auto obj : objectArry) {
		obj->Update();
	}
	//•`‰æ
	Draw();
}
//---------------------------------------------------------
//	•`‰æ
//---------------------------------------------------------
void ObjectManager::Draw()
{
	//‰æ–Ê‚ð‰Šú‰»
	ClearDrawScreen();
	//•`‰æ
	for (auto obj : objectArry) {
		obj->Draw();
	}
	//•\Ž¦
	ScreenFlip();
}