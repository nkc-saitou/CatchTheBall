#include "Game.h"
#include "SceneMgr.h"
#include "DxLib.h"

// x���W
int PosX;
// �摜
int music, B_Handle, G_Handle[16];

// ������
void Game_Instialize() 
{
	// ���y�Đ�(���[�v)
	PlayMusic("game_maoudamashii_1_battle25.mp3", DX_PLAYTYPE_LOOP);
	// �摜�̓ǂݍ���
	B_Handle = LoadGraph("images\\test2.png");
	LoadDivGraph("images\\mapChip.png", 16, 4, 4, 64, 64, G_Handle);
}

//�X�V
void Game_Update()
{
	//Esc�L�[��������Ă�����
    if(CheckHitKey(KEY_INPUT_ESCAPE)!=0){ 
		//�V�[�������j���[�ɕύX
        SceneMgr_ChangeScene(eScene_Menu);
    }

	// �ړ���
	PosX -= 2;
	// �w�i�X�N���[��
	if (PosX == -640) {
		PosX = 0;
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
    DrawString(0, 0,"�Q�[����ʂł��B",GetColor(255,255,255));
    DrawString(0,20,"Esc�L�[�������ƃ��j���[��ʂɖ߂�܂��B",GetColor(255,255,255));
}
