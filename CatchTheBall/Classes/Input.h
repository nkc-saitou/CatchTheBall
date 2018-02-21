#pragma once
#include "DxLib.h"
#include <string>
#include "Singleton.h"

//�`�F�b�N����Q�[���p�b�h�̐�
#define MAX_GAMEPAD_NUM 8

//�{�^������
#define MAX_BUTTON_PAD 32

//�L�[�{�[�h���͗p�o�b�t�@�T�C�Y
#define KEY_STATE_BUFFER_SIZE 256

//�����ꂽ
#define INPUT_ON 1

//������Ă��Ȃ�
#define INPUT_OFF 0

///////////////////////////////////////////
// ���͊Ǘ��N���X
///////////////////////////////////////////
class Input : public Singleton <Input>
{
	//�L�[�̓��͏�Ԃ��i�[
	int key[256];
	char buf[256];

	int tempButton; //�P�t���[���O�̓��͏��(�����ꂽ���ǂ���)

	void ButtonSetting();

public:

	bool ButtonDown(int keyCode); //�{�^�����������u��
	bool Button(int keyCode); //�{�^���������Ă���Ƃ�
	bool ButtonPull(int keyCode); //�{�^���������ꂽ�Ƃ�
	bool ButtonFree(int keyCode); //�{�^����������Ă��Ȃ���
};
