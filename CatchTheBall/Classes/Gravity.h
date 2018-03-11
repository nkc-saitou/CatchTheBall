#pragma once

/*
///////////////////////////////////////////
Gravity�N���X

�T�v�@�F�I�u�W�F�N�g�ɏd�͂�^����
�g�����F�R���X�g���N�^�̈����ɏ��������W��n���BObjGravity()�ōX�V�����āAFall_y�̒l�ŗ�������
�g�p��FDrawGraph(x, fall_y(), GHandle, TRUE);
���Ӂ@�FObjGravity()�͖��t���[���X�V���邱��
///////////////////////////////////////////
*/

#include "DxLib.h"
#include "Input.h"

class Gravity
{
	//�v���C���[��y���W
	int y;

	//���������ۂ̑O���y���W��ۑ�
	int y_prev;

	//���݂�y���W��ۑ�
	int y_temp;

public:
	Gravity();

protected:
	void ObjGravity();
	void GravityReset();

	int Fall_y(){ return y; }
	void Fall_y(int fallY) { y = fallY; }
};