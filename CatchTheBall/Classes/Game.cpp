#include "Game.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "AudioManager.h"

// x���W
int PosX;
// �摜 (C �� �L�����N�^�[, B �� �w�i, G �� �}�b�v�`�b�v)
int C_Handle, B_Handle, G_Handle[16];

// ������
void Game_Instialize() 
{
	AudioManager::getInstance()->playBGM(BGM_Game);
	// �摜�̓ǂݍ���
	C_Handle = LoadGraph("Resources\\image\\chara_64.png");
	B_Handle = LoadGraph("Resources\\image\\test2.png");
	LoadDivGraph("Resources\\image\\mapChip.png", 16, 4, 4, 64, 64, G_Handle);
}

//�X�V
void Game_Update()
{
	//Esc�L�[��������Ă�����
    if(CheckHitKey(KEY_INPUT_ESCAPE)!=0){ 
		AudioManager::getInstance()->playSE(SE_Select);
		//�V�[�������j���[�ɕύX
		SceneMgr_ChangeScene(eScene_Menu);
    }
	if (CheckHitKey(KEY_INPUT_RIGHT) != 0) {
		// �ړ���
		PosX -= 3;
		// �w�i�X�N���[��
		if (PosX <= -640) {
			PosX = 0;
		}
	}
}

//�`��
void Game_Draw()
{	
	// �w�i�X�N���[��
	DrawGraph(PosX, 0, B_Handle, TRUE);
	DrawGraph(PosX + 640, 0, B_Handle, TRUE);

	// �}�b�v�摜(��)
	DrawGraph(0, 352, G_Handle[0], TRUE);
	DrawGraph(64, 352, G_Handle[0], TRUE);
	DrawGraph(64, 416, G_Handle[1], TRUE);
	DrawGraph(0, 416, G_Handle[1], TRUE);
	DrawGraph(0, 224, C_Handle, TRUE);
    DrawString(0, 0,"�Q�[����ʂł��B",GetColor(255,255,255));
    DrawString(0,20,"Esc�L�[�������ƃ��j���[��ʂɖ߂�܂��B",GetColor(255,255,255));
}
