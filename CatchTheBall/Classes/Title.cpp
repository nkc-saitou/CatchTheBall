#include "DxLib.h"
#include "Title.h"
#include "Input.h"
#include "SceneMgr.h"
#include "AudioManager.h"
#include "FileManager.h"

// �_��x���W
int cloudPosX[3];

void Title::Title_Initialize()
{
	AudioManager::Instance()->playBGM(TITLE_BGM);

	// ���W�̏�����
	cloudPosX[0] = -100;
	cloudPosX[1] = -300;
	cloudPosX[2] = -500;
}

void Title::Title_Update()
{
	// �o�b�N�̉_�𓮂���
	for (int i = 0; i < 3; i++) {
	cloudPosX[i] += 1;
	if (cloudPosX[i] > 640) {
		cloudPosX[i] = -100;
	    }
	}

	//�G���^�[�L�[�������ꂽ��
	if (Input::Instance()->ButtonDown(KEY_INPUT_RETURN)) {
		AudioManager::Instance()->playSE(SE_SELECT);
		SceneMgr::Instance()->SceneMgr_ChangeScene(eScene_Select);   //�V�[�����Q�[����ʂɕύX
	}
}

void Title::Title_Draw()
{
	DrawGraph(0, 0, FileManager::Instance()->GetFileHandle(TITLE_IMAGE), FALSE);
	DrawGraph(cloudPosX[0], 100, FileManager::Instance()->GetFileHandle(CLOUD_IMAGE), TRUE);
	DrawGraph(cloudPosX[1], 40, FileManager::Instance()->GetFileHandle(CLOUD_IMAGE), TRUE);
	DrawGraph(cloudPosX[2], 160, FileManager::Instance()->GetFileHandle(CLOUD_IMAGE), TRUE);
	DrawGraph(0, 0, FileManager::Instance()->GetFileHandle(TITLE_TEXT), TRUE);
	DrawGraph(280, 288, FileManager::Instance()->GetFileHandle(PLAYER_IMAGE), TRUE);

	DrawString(230, 410, "��", GetColor(0, 0, 0));
}