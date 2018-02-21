#include "DxLib.h"
#include "Config.h"
#include "Game.h"
#include "Menu.h"
#include "SceneMgr.h"

//�V�[���Ǘ��ϐ�
static eScene Scene = eScene_Menu;   
// ���̃V�[��
static eScene nextScene;

// ������
void SceneMgr_Instialize() 
{
	switch (Scene) 
	{       
    //�V�[���ɂ���ď����𕪊�
	case eScene_Menu:    //���݂̉�ʂ����j���[�Ȃ�
		//Menu_Update();   //���j���[��ʂ̍X�V����������
		break;//�ȉ���
	case eScene_Game:
		Game_Instialize();
		break;
	case eScene_Config:
		Config_Instialize();
		break;
	}
}

//�X�V
void SceneMgr_Update(){
    switch(Scene){      
	//�V�[���ɂ���ď����𕪊�
    case eScene_Menu:    //���݂̉�ʂ����j���[�Ȃ�
        Menu_Update();   //���j���[��ʂ̍X�V����������
        break;//�ȉ���
    case eScene_Game:
        Game_Update();
        break;
    case eScene_Config:
        Config_Update();
        break;
    }
}

//�`��
void SceneMgr_Draw(){
    switch(Scene){     
	//�V�[���ɂ���ď����𕪊�
    case eScene_Menu:   //���݂̉�ʂ����j���[��ʂȂ�
        Menu_Draw();    //���j���[��ʂ̕`�揈��������
        break;//�ȉ���
    case eScene_Game:
		Game_Draw();
        break;
    case eScene_Config:
        Config_Draw();
        break;
    }
}

// ���� nextScene �ɃV�[����ύX����
void SceneMgr_ChangeScene(eScene NextScene){
	// ���̃V�[���̏����i�[
	nextScene = NextScene;
	// �V�[���t�F�[�h
	SceneMgr_Fade();
}

// �V�[���t�F�[�h
void SceneMgr_Fade()
{
	// �t�F�[�h�p�ϐ�(�����x,�t�F�[�h�p�摜)
	int alpha, FadeIn;
	FadeIn = LoadGraph("images\\test1.png");

	SetDrawScreen(DX_SCREEN_BACK);

	// �t�F�[�h�C��
	for (alpha = 0; alpha < 255; alpha += 3)
	{
		ClearDrawScreen();
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		SceneMgr_Draw();

		// �t�F�[�h�C���J�n
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
		DrawGraph(0, 0, FadeIn, TRUE);
		ScreenFlip();
	}

	StopMusic();

	// ���̃V�[���ɐ؂�ւ�
	Scene = nextScene;
	// ���̃V�[���̏�����
	SceneMgr_Instialize();

	// �t�F�[�h�A�E�g
	for (alpha = 255; alpha > 0; alpha -= 3)
	{
		ClearDrawScreen();
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		SceneMgr_Draw();

		// �t�F�[�h�A�E�g�J�n
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
		DrawGraph(0, 0, FadeIn, TRUE);
		ScreenFlip();
	}

	// �`��̃u�����h��؂�
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND,0);
	ScreenFlip();
}