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
#include "Time.h"

class Gravity
{
	//�v���C���[��y���W
	double vecY;

	double gravity;

public:
	Gravity();

protected:
	void ObjGravity();
	void GravityReset();

	//�x�N�g��
	double Fall_y() { return vecY; }
	void Fall_y(double vecY) { Gravity::vecY = vecY; }
};