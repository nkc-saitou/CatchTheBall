#include "Time.h"

int Time::mGameStartTime = 0;	//�N���J�n����
int Time::mCurrentTime = 0;		//���݂̃t���[���̎���
int Time::mPrevTime = 0;		//�O�̃t���[���̎���
int Time::mCountStartTime = 0;	//����J�n����
int Time::mCount = 0;			//�J�E���^
float Time::mFps = 0;			//fps
float Time::mDeltaTime = 0;		//�t���[���Ԃ̎���
float Time::mTime = 0;			//�N�����Ă���̌o�ߎ���

void Time::Initialize() {
	//PC�̎��Ԃ����Ă���
	mGameStartTime = GetNowCount();
	mCurrentTime = mPrevTime = mGameStartTime;
}

bool Time::Update() {

	//�������X�V
	mPrevTime = mCurrentTime;
	mCurrentTime = GetNowCount();
	mTime = (mCurrentTime - mGameStartTime) / 1000.0f;
	mDeltaTime = (mCurrentTime - mPrevTime) / 1000.0f;

	if (mCount == 0) { //1�t���[���ڂȂ玞�����L��
		mCountStartTime = GetNowCount();
	}
	if (mCount == N) { //60�t���[���ڂȂ畽�ς��v�Z����
		int t = GetNowCount();
		mFps = 1000.f / ((t - mCountStartTime) / (float)N);
		mCount = 0;
		mCountStartTime = t;
	}
	mCount++;
	return true;
}

void Time::Draw() {
	DrawFormatString(0, 0, GetColor(255, 255, 255), "%.1f", mFps);
}

void Time::Wait() {
	int tookTime = GetNowCount() - mCountStartTime;	//������������
	int waitTime = mCount * 1000 / FPS - tookTime;	//�҂ׂ�����
	if (waitTime > 0) {
		Sleep(waitTime);	//�ҋ@
	}
}

float Time::GetTime() {
	return mTime;
}

float Time::GetDeltaTime() {
	return mDeltaTime;
}