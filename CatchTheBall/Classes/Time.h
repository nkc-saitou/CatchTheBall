#pragma once
#include <math.h>
#include "DxLib.h"

static class Time {
	static const int N = 60;		//���ς����T���v����
	static const int FPS = 10;		//�ݒ肵��FPS

	static int mGameStartTime;		//�N���J�n����
	static int mCurrentTime;		//���݂̃t���[���̎���
	static int mPrevTime;			//�O�̃t���[���̎���
	static int mCountStartTime;		//����J�n����
	static int mCount;				//�J�E���^
	static float mFps;				//fps
	static float mDeltaTime;		//�t���[���Ԃ̎���
	static float mTime;				//�N�����Ă���̌o�ߎ���

public:

	//������
	static void Initialize();

	//�v�Z�̍X�V
	static bool Update();

	//�f�o�b�O�p��FPS��`�悷��
	static void Draw();
	//���������������ꍇ�A�ڕWFPS�ɂȂ�܂ő҂�
	static void Wait();
	//�Q�[�����N�����Ă���̌o�ߎ��Ԃ��擾
	static float GetTime();
	//�t���[���Ԃ̌o�ߎ��Ԃ��擾
	static float GetDeltaTime();
};