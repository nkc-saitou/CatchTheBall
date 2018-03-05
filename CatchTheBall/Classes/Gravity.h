#pragma once

/*
///////////////////////////////////////////
Gravity�N���X

�T�v�@�F�I�u�W�F�N�g�ɏd�͂�^����
�g�����F�R���X�g���N�^�̈����ɏ��������W��n���BObjGravity()�ōX�V�����āAfall_y()�̒l�ŗ�������
�g�p��FDrawGraph(x, fall_y(), GHandle, TRUE);
���Ӂ@�FObjGravity()�͖��t���[���X�V���邱��
///////////////////////////////////////////
*/

#include "DxLib.h"
#include "Input.h"

#define GRAVITY_ACCEL -9.8

class Gravity
{
	//�v���C���[��y���W
	int y;

	//���������ۂ̑O���y���W��ۑ�
	int y_prev;

	//���݂�y���W��ۑ�
	int y_temp;


public:
	//�����F�X�^�[�g�|�W�V�����̂����W
	Gravity(int startY);

protected:
	virtual void ObjGravity();
	int fall_y(){ return y; }
};