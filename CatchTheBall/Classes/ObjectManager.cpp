#include "ObjectManager.h"
#include "DxLib.h"

//---------------------------------------------------------
//	‰Šú‰»
//---------------------------------------------------------
void ObjectManager::Initialize()
{
	//”z’u
}
//---------------------------------------------------------
//	I—¹ˆ—
//---------------------------------------------------------
void ObjectManager::Finalize()
{
	//—v‘f‚Ì‘Síœ
	while (objectArry.empty()) {
		auto obj = objectArry.end();
		//objectArry.pop_back();
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
	if (objectArry.empty())
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
	if (isStop) return;
	//XV
	for (auto obj : objectArry) {
		obj->Update();
	}
	//•`‰æ
	Draw();
}
//---------------------------------------------------------
//	XV‚Ì’âŽ~(UIˆÈŠO)
//---------------------------------------------------------
void ObjectManager::Stop()
{
	isStop = true;
}
//---------------------------------------------------------
//	XV‚ÌÄŠJ(UIˆÈŠO)
//---------------------------------------------------------
void ObjectManager::Reopening()
{
	isStop = false;
}
//---------------------------------------------------------
//	•`‰æ
//---------------------------------------------------------
void ObjectManager::Draw()
{
	//‰æ–Ê‚ð‰Šú‰»
	//ClearDrawScreen();
	//•`‰æ
	for (auto obj : objectArry) {
		obj->Draw();
	}
	//•\Ž¦
	//ScreenFlip();
}