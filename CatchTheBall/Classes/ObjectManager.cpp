#include "ObjectManager.h"
#include "DxLib.h"

//---------------------------------------------------------
//	������
//---------------------------------------------------------
void ObjectManager::Initialize()
{
	//�z�u
}
//---------------------------------------------------------
//	�I������
//---------------------------------------------------------
void ObjectManager::Finalize()
{
	//�v�f�̑S�폜
	while (objectArry.empty()) {
		auto obj = objectArry.end();
		objectArry.pop_back();
		delete &obj;
	}
}
//---------------------------------------------------------
//	Object�̒ǉ�
//	�EPriority(�D�揇��)���Ⴂ���̂���}��
//---------------------------------------------------------
void ObjectManager::Add(Object* object)
{
	if (&object == nullptr) return;
	//����ۂ̎�
	if (objectArry.empty())
	{
		objectArry.push_back(object);
		return;
	}
	//�D�揇��
	auto it = objectArry.begin();
	for (auto obj : objectArry)
	{
		if (obj->Priority() > object->Priority()) break;
		it++;
	}
	//�}��
	objectArry.insert(it, object);
}
//---------------------------------------------------------
//	�X�V
//---------------------------------------------------------
void ObjectManager::Update()
{
	const int UI_NO = 20;
	//�X�V
	for (auto obj : objectArry) {
		if (isStop && obj->Priority() < UI_NO) {
			continue;
		}
		obj->Update();
	}
	//�`��
	Draw();
}
//---------------------------------------------------------
//	�X�V�̒�~(UI�ȊO)
//---------------------------------------------------------
void ObjectManager::Stop()
{
	isStop = true;
}
//---------------------------------------------------------
//	�X�V�̍ĊJ(UI�ȊO)
//---------------------------------------------------------
void ObjectManager::Reopening()
{
	isStop = false;
}
//---------------------------------------------------------
//	�`��
//---------------------------------------------------------
void ObjectManager::Draw()
{
	//��ʂ�������
	ClearDrawScreen();
	//�`��
	for (auto obj : objectArry) {
		obj->Draw();
	}
	//�\��
	ScreenFlip();
}