#include "ObjectManager.h"
#include "DxLib.h"


ObjectManager::ObjectManager()
{
}
ObjectManager::ObjectManager(eScene SceneName)
{
	//�ǂݍ���

}
ObjectManager::~ObjectManager()
{
	//�j��
}
//---------------------------------------------------------
//	������
//---------------------------------------------------------
void ObjectManager::Initialize()
{
	//�v�f�̍폜
	while (objectArry.begin() != objectArry.end()) {
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
	if (objectArry.begin() == objectArry.end())
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
	//�X�V
	for (auto obj : objectArry) {
		obj->Update();
	}
	//�`��
	Draw();
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