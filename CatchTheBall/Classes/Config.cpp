#include "Config.h"
#include "SceneMgr.h"
#include "DxLib.h"

// �摜�i�[�ϐ�
int Handle;

// ������
void Config_Instialize() 
{
	// �摜�̓ǂݍ���
	Handle = LoadGraph("Resources\\image\\FireEmblem_Config.jpg");
}

//�X�V
void Config_Update(){
	//Esc�L�[��������Ă�����
    if(CheckHitKey(KEY_INPUT_ESCAPE)!=0){
		//�V�[�������j���[�ɕύX
        SceneMgr::Instance()->SceneMgr_ChangeScene(eScene_Title);
    }
}

//�`��
void Config_Draw()
{
	// �摜�`��
	DrawGraph(0, 0, Handle, false);
    DrawString(0, 0,"�ݒ��ʂł��B",GetColor(255,255,255));
    DrawString(0,20,"Esc�L�[�������ƃ��j���[��ʂɖ߂�܂��B",GetColor(255,255,255));
}

