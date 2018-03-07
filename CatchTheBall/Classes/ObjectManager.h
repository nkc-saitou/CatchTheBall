#pragma once

#include "Object.h"
#include "Singleton.h"
#include <vector>

using namespace std;

const static int UI_NO = 20;

class ObjectManager : public Singleton<ObjectManager>
{
public:
	void Initialize();		//������
	void Finalize();		//�I������
	void Add(Object*);		//�ǉ�
	void Destroy(Object*);	//�폜
	void Update();			//�X�V
	void Stop();			//�X�V�̒�~
	void Reopening();		//�X�V�̍ĊJ
	void Draw();			//�\��

private:
	vector<Object*> objectArry;

	bool isStop;
};