#pragma once

#include "Object.h"
#include "Singleton.h"
#include <vector>

using namespace std;

class ObjectManager : public Singleton<ObjectManager>
{
public:
	vector<Object*> objectArry;

	void Initialize();	//������
	void Finalize();	//�I������
	void Add(Object*);	//�ǉ�
	void Update();		//�X�V
	void Stop();		//�X�V�̒�~
	void Reopening();	//�X�V�̍ĊJ
	void Draw();		//�\��

private:
	bool isStop;
};