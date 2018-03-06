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

// ������
void Game::Game_Initialize() 
{
	AudioManager::Instance()->playBGM(GAME_BGM);
	LoadDivGraph("Resources\\image\\mapChip.png", 16, 4, 4, 64, 64, G_Handle);
}

//�X�V
void Game::Game_Update()
{
	//Esc�L�[��������Ă�����
    if(Input::Instance()->ButtonDown(KEY_INPUT_ESCAPE)){
		AudioManager::Instance()->playSE(SE_SELECT);
		//�V�[�������j���[�ɕύX
		SceneMgr::Instance()->SceneMgr_ChangeScene(eScene_Title);
    }
	if (Input::Instance()->ButtonDown(KEY_INPUT_SPACE)) {
		AudioManager::Instance()->playSE(SE_SHOT);
	}
	if (Input::Instance()->ButtonDown(KEY_INPUT_RETURN)) {
		AudioManager::Instance()->playSE(SE_DESTROY);
	}

	// �E�L�[��������Ă�����
	if (Input::Instance()->ButtonDown(KEY_INPUT_RIGHT)) {
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
	// �E�L�[��������Ă��Ȃ�������
	else {
		// �ړ����̉��y���~�߂�
		StopSoundMem(FileManager::Instance()->GetFileHandle(SE_MOVE));
	}
}

//�`��
void Game::Game_Draw()
{	
	// �w�i�X�N���[��
	DrawGraph(PosX, 0, FileManager::Instance()->GetFileHandle(BACKGROUND_IMAGE), TRUE);
	DrawGraph(PosX + 640, 0, FileManager::Instance()->GetFileHandle(BACKGROUND_IMAGE), TRUE);

	// �}�b�v�摜(��)
	DrawGraph(0, 352, G_Handle[0], TRUE);
	DrawGraph(64, 352, G_Handle[0], TRUE);
	DrawGraph(64, 416, G_Handle[1], TRUE);
	DrawGraph(0, 416, G_Handle[1], TRUE);
	DrawGraph(120, 90, FileManager::Instance()->GetFileHandle(PLAYER_IMAGE), TRUE);
    DrawString(0, 0,"�Q�[����ʂł��B",GetColor(255,255,255));
    DrawString(0,20,"Esc�L�[�������ƃ��j���[��ʂɖ߂�܂��B",GetColor(255,255,255));
}
