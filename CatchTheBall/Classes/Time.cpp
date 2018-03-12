#include "Time.h"

LONGLONG Time::mGameStartTime = 0;	//�N���J�n����
LONGLONG Time::mCurrentTime = 0;		//���݂̃t���[���̎���
LONGLONG Time::mPrevTime = 0;		//�O�̃t���[���̎���
LONGLONG Time::mCountStartTime = 0;	//����J�n����
int Time::mCount = 0;			//�J�E���^
float Time::mFps = 0;			//fps
float Time::mDeltaTime = 0;		//�t���[���Ԃ̎���
float Time::mTime = 0;			//�N�����Ă���̌o�ߎ���

void Time::Initialize() {
	//PC�̎��Ԃ����Ă���
	mGameStartTime = GetNowHiPerformanceCount();
	mCurrentTime = mPrevTime = mGameStartTime;
}

bool Time::Update() {

	//�������X�V
	mPrevTime = mCurrentTime;
	mCurrentTime = GetNowHiPerformanceCount();
	mTime = (mCurrentTime - mGameStartTime) / 1000000.0;
	mDeltaTime = (mCurrentTime - mPrevTime) / 1000000.0;
	//clsDx();
	//printfDx(std::to_string(mDeltaTime).c_str());

	if (mCount == 0) { //1�t���[���ڂȂ玞�����L��
		mCountStartTime = GetNowHiPerformanceCount();
	}
	if (mCount == N) { //60�t���[���ڂȂ畽�ς��v�Z����
		auto t = GetNowHiPerformanceCount();
		mFps = 1000000.0f / ((t - mCountStartTime) / N);
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
	auto tookTime = GetNowHiPerformanceCount() - mCountStartTime;	//������������
	auto waitTime = mCount * 1000000 / FPS - tookTime;	//�҂ׂ�����
	if (waitTime > 0) {
		Sleep(waitTime / 1000);	//�ҋ@
	}
}

float Time::GetTime() {
	return mTime;
}

float Time::GetDeltaTime() {
	return mDeltaTime;
}