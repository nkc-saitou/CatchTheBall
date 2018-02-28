#include "ObjectManager.h"
#include "DxLib.h"
#include <algorithm>

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
//	�X�V
//---------------------------------------------------------
void ObjectManager::Update()
{
	//�X�V
	for (auto obj : objectArry)
	{
		obj->Update();
	}

	//�`��
	Draw();
}
//---------------------------------------------------------
//	Object�ǉ�
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
	
	objectArry.insert(it, object);
}
//---------------------------------------------------------
//	�`��
//---------------------------------------------------------
void ObjectManager::Draw()
{
	//��ʂ�������
	ClearDrawScreen();

	//�`��
	for (auto obj : objectArry)
	{
		obj->Draw();
	}
	
	//�\��
	ScreenFlip();
}