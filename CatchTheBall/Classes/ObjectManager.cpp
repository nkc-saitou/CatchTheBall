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
//	Public
//---------------------------------------------------------
void ObjectManager::Update() //�X�V
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
void ObjectManager::Add(Object* obj)
{
	if (&obj == nullptr) return;

	objectArry.push_back(obj);

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