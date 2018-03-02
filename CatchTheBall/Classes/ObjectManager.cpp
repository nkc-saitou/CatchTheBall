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
	
	objectArry.insert(it, object);
}
//---------------------------------------------------------
//	XV
//---------------------------------------------------------
void ObjectManager::Update()
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