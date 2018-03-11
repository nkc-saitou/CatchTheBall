#include "Time.h"

int Time::mGameStartTime = 0;	//起動開始時間
int Time::mCurrentTime = 0;		//現在のフレームの時間
int Time::mPrevTime = 0;		//前のフレームの時間
int Time::mCountStartTime = 0;	//測定開始時刻
int Time::mCount = 0;			//カウンタ
float Time::mFps = 0;			//fps
float Time::mDeltaTime = 0;		//フレーム間の時間
float Time::mTime = 0;			//起動してからの経過時間

void Time::Initialize() {
	//PCの時間を入れておく
	mGameStartTime = GetNowCount();
	mCurrentTime = mPrevTime = mGameStartTime;
}

bool Time::Update() {

	//時刻を更新
	mPrevTime = mCurrentTime;
	mCurrentTime = GetNowCount();
	mTime = (mCurrentTime - mGameStartTime) / 1000.0f;
	mDeltaTime = (mCurrentTime - mPrevTime) / 1000.0f;

	if (mCount == 0) { //1フレーム目なら時刻を記憶
		mCountStartTime = GetNowCount();
	}
	if (mCount == N) { //60フレーム目なら平均を計算する
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
	int tookTime = GetNowCount() - mCountStartTime;	//かかった時間
	int waitTime = mCount * 1000 / FPS - tookTime;	//待つべき時間
	if (waitTime > 0) {
		Sleep(waitTime);	//待機
	}
}

float Time::GetTime() {
	return mTime;
}

float Time::GetDeltaTime() {
	return mDeltaTime;
}