#include "ObjectManager.h"
#include "DxLib.h"
#include "Camera.h"

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
		//objectArry.pop_back();
		delete &obj;
	}
}
//---------------------------------------------------------
//	Object�̒ǉ�
//	�EPriority(�D�揇��)���Ⴂ���̂���}��
//---------------------------------------------------------
void ObjectManager::Add(Object* object)
{
	if (object == nullptr) return;
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
//	�폜
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
//	�X�V
//---------------------------------------------------------
void ObjectManager::Update()
{
	if (isStop) return;
	//�X�V
	for (auto obj : objectArry) {
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
	if (Camera::MainCamera == nullptr)  {
		//�J������
		for (auto obj : objectArry) {
			obj->Draw();
		}
	}
	else {
		//�J�����L
		Camera::MainCamera->DrawScreen(objectArry);
	}
}