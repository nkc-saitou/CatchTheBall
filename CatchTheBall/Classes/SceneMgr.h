#pragma once
#include "Singleton.h"

#define FADE_IMAGE "test1.png"

typedef enum {
    eScene_Title,       //�^�C�g�����
	eScene_Select,    //�X�e�[�W�Z���N�g���
    eScene_Game,    //�Q�[�����
} eScene ;

class SceneMgr : public Singleton <SceneMgr>
{
public:
	SceneMgr();
	~SceneMgr();

	// ������
	void SceneMgr_Initialize();
	//�X�V
	void SceneMgr_Update();
	//�`��
	void SceneMgr_Draw();
	// ���� nextScene �ɃV�[����ύX����
	void SceneMgr_ChangeScene(eScene nextScene);
	// �V�[���t�F�[�h
	void SceneMgr_Fade();
};
