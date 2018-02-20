#include "Input.h"

/////////////////////////////////////////////////////
//����			:���̓L�[�R�[�h
//�߂�l		:�����̃L�[��������Ă����true
//����			:�����̃L�[��������Ă��邩�𔻒�
/////////////////////////////////////////////////////
bool Input::Button(int keyCode)
{
	if (CheckHitKey(keyCode) == INPUT_ON)
	{
		return true;
	}
	return false;
}

/////////////////////////////////////////////////////
//����			:���̓L�[�R�[�h
//�߂�l		:�����̃L�[�������ꂽ�u�Ԃ̂�true
//����			:�����̃L�[�������ꂽ�u�Ԃ𔻒�
/////////////////////////////////////////////////////
bool Input::ButtonDown(int keyCode)
{
	Input::ButtonSetting();

	if (key[keyCode] == INPUT_ON) return true;
	else return false;
}


/////////////////////////////////////////////////////
//����			:���̓L�[�R�[�h
//�߂�l		:�����̃L�[�������ꂽ�u�Ԃ̂�true
//����			:�����̃L�[�������ꂽ�u�Ԃ𔻒�
/////////////////////////////////////////////////////
bool Input::ButtonPull(int keyCode)
{
	Input::ButtonSetting();

	if (tempButton > key[keyCode] && key[keyCode] == INPUT_OFF)
	{
		tempButton = 0;
		return true;
	}

	tempButton = key[keyCode];
	
	return false;
}

/////////////////////////////////////////////////////
//����			:���̓L�[�R�[�h
//�߂�l		:�����̃L�[��������Ă��Ȃ����true
//����			:�����̃L�[��������Ă����Ԃ��𔻒�
/////////////////////////////////////////////////////
bool Input::ButtonFree(int keyCode)
{
	if (CheckHitKey(keyCode) == INPUT_OFF)
	{
		return true;
	}
	return false;
}

/////////////////////////////////////////////////////
//����			:�Ȃ�
//�߂�l		:�Ȃ�
//����			:���݂̃L�[���͏�Ԃ��Ǘ�
/////////////////////////////////////////////////////
void Input::ButtonSetting()
{
	//���݂̃L�[�̓��͏�Ԃ��i�[
	buf[256];
	//�L�[�̓��͏�Ԃ𓾂�
	GetHitKeyStateAll(buf);

	//�L�[�R�[�h�ɑΉ�����L�[��������Ă�����
	for (int i = 0; i < 256; i++)
	{
		if (buf[i] != INPUT_OFF) key[i]++;
		else key[i] = 0;
	}
}
