#include "DxLib.h"
#include "Game.h"
#include "SceneMgr.h"
#include "AudioManager.h"
#include "FileManager.h"
#include "Input.h"

// x���W
int PosX, BomPosX;
// �摜 (�}�b�v�`�b�v)
int G_Handle[16];

Game::Game()
{
	Initialize();
}

Game::~Game()
{

}

// ������
void Game::Initialize() 
{
	AudioManager::Instance()->playBGM(GAME_BGM);
	LoadDivGraph("Resources\\image\\mapChip.png", 16, 4, 4, 64, 64, G_Handle);
}

//�X�V
void Game::Update()
{
	//Esc�L�[��������Ă�����
    if(Input::Instance()->ButtonDown(KEY_INPUT_ESCAPE)){
		AudioManager::Instance()->playSE(SE_SELECT);
		//�V�[���t�F�[�h���Ă���V�[�����^�C�g���ɕύX
		Scene::SceneFade(Scene::TITLE);
    }
	if (Input::Instance()->ButtonDown(KEY_INPUT_SPACE)) {
		AudioManager::Instance()->playSE(SE_SHOT);
	}
	if (Input::Instance()->ButtonDown(KEY_INPUT_RETURN)) {
		AudioManager::Instance()->playSE(SE_DESTROY);
	}

	// �E�L�[��������Ă�����
	if (Input::Instance()->Button(KEY_INPUT_RIGHT)) {
		// �ړ���
		PosX += 3;

		// �ړ����̉��y���Đ�����Ă��Ȃ������特�y�Đ�
		if (CheckSoundMem(FileManager::Instance()->GetFileHandle(SE_MOVE)) == 0) {
			PlaySoundMem(FileManager::Instance()->GetFileHandle(SE_MOVE), DX_PLAYTYPE_LOOP);
		}
		// �w�i�X�N���[��
		if (PosX >= 640) {
			PosX = 0;
		}
	}
	// �E�L�[��������Ă��Ȃ�������
	else if(Input::Instance()->Button(KEY_INPUT_LEFT)) {
		// �ړ���
		PosX -= 3;

		// �ړ����̉��y���Đ�����Ă��Ȃ������特�y�Đ�
		if (CheckSoundMem(FileManager::Instance()->GetFileHandle(SE_MOVE)) == 0) {
			PlaySoundMem(FileManager::Instance()->GetFileHandle(SE_MOVE), DX_PLAYTYPE_LOOP);
		}
		// �w�i�X�N���[��
		if (PosX <= -640) {
			PosX = 0;
		}
	}
	else {
		// �ړ����̉��y���~�߂�
		StopSoundMem(FileManager::Instance()->GetFileHandle(SE_MOVE));
	}
}

//�`��
void Game::Draw()
{	
	// �w�i�X�N���[��
	DrawGraph(PosX, 0, FileManager::Instance()->GetFileHandle(BACKGROUND_IMAGE), TRUE);
	DrawGraph(PosX - 640, 0, FileManager::Instance()->GetFileHandle(BACKGROUND_IMAGE), TRUE);

	// �}�b�v�摜(��)
	DrawGraph(PosX, 352, G_Handle[0], TRUE);
	DrawGraph(PosX + 64, 352, G_Handle[0], TRUE);
	DrawGraph(PosX + 64, 416, G_Handle[1], TRUE);
	DrawGraph(PosX, 416, G_Handle[1], TRUE);
	DrawGraph(PosX, 90, FileManager::Instance()->GetFileHandle(PLAYER_IMAGE), TRUE);
    DrawString(PosX, 0,"�Q�[����ʂł��B",GetColor(255,255,255));
    DrawString(PosX,20,"Esc�L�[�������ƃ��j���[��ʂɖ߂�܂��B",GetColor(255,255,255));
}
