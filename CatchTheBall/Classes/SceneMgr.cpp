#include "DxLib.h"
#include "Select.h"
#include "Game.h"
#include "Title.h"
#include "SceneMgr.h"
#include "AudioManager.h"
#include "FileManager.h"

//�V�[���Ǘ��ϐ�
static eScene Scene;   
// ���̃V�[��
static eScene nextScene;

SceneMgr::SceneMgr()
{
	Scene = eScene_Title;
}

SceneMgr::~SceneMgr()
{

}

// ������
void SceneMgr::SceneMgr_Initialize() 
{
	switch (Scene) 
	{       
    //�V�[���ɂ���ď����𕪊�
	case eScene_Title:    //���݂̉�ʂ����j���[�Ȃ�
		Title::Title_Initialize();   //���j���[��ʂ̍X�V����������
		break;//�ȉ���
	case eScene_Select:
		Select::Select_Initialize();
		break;
	case eScene_Game:
		Game::Game_Initialize();
		break;
	}
}

//�X�V
void SceneMgr::SceneMgr_Update(){
    switch(Scene){      
	//�V�[���ɂ���ď����𕪊�
    case eScene_Title:    //���݂̉�ʂ����j���[�Ȃ�
        Title::Title_Update();   //���j���[��ʂ̍X�V����������
        break;//�ȉ���
	case eScene_Select:
		Select::Select_Update();
		break;
    case eScene_Game:
        Game::Game_Update();
        break;
    }
}

//�`��
void SceneMgr::SceneMgr_Draw(){
    switch(Scene){     
	//�V�[���ɂ���ď����𕪊�
    case eScene_Title:   //���݂̉�ʂ����j���[��ʂȂ�
        Title::Title_Draw();    //���j���[��ʂ̕`�揈��������
        break;//�ȉ���
	case eScene_Select:
		Select::Select_Draw();
		break;
    case eScene_Game:
		Game::Game_Draw();
        break;
    }
}

// ���� nextScene �ɃV�[����ύX����
void SceneMgr::SceneMgr_ChangeScene(eScene NextScene){
	// ���̃V�[���̏����i�[
	nextScene = NextScene;
	// �V�[���t�F�[�h
	SceneMgr_Fade();
}

// �V�[���t�F�[�h
void SceneMgr::SceneMgr_Fade()
{
	// �t�F�[�h�p�ϐ�(�����x,�t�F�[�h�p�摜)
	int alpha;

	SetDrawScreen(DX_SCREEN_BACK);

	// �t�F�[�h�A�E�g
	for (alpha = 0; alpha < 255; alpha += 3)
	{
		ClearDrawScreen();
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	    SceneMgr_Draw();

		// �t�F�[�h�C���J�n
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
		DrawGraph(0, 0, FileManager::Instance()->GetFileHandle(FADE_IMAGE), TRUE);
		// �����ɉ��ʂ��t�F�[�h
		AudioManager::Instance()->VolumeFade(alpha);
		ScreenFlip();
	}

	// ���̃V�[���ɐ؂�ւ�
	Scene = nextScene;
	// ���̃V�[���̏�����
	SceneMgr_Initialize();

	// �t�F�[�h�C��
	for (alpha = 255; alpha > 0; alpha -= 3)
	{
		ClearDrawScreen();
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		SceneMgr_Draw();

		// �t�F�[�h�A�E�g�J�n
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
		DrawGraph(0, 0, FileManager::Instance()->GetFileHandle(FADE_IMAGE), TRUE);
		// �����ɉ��ʂ��t�F�[�h
		AudioManager::Instance()->VolumeFade(alpha);
		ScreenFlip();
	}

	// �`��̃u�����h��؂�
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND,0);
	ScreenFlip();
}