#pragma once
#include <math.h>
#include "DxLib.h"

static class Time {
	static const int N = 60;		//平均を取るサンプル数
	static const int FPS = 10;		//設定したFPS

	static int mGameStartTime;		//起動開始時間
	static int mCurrentTime;		//現在のフレームの時間
	static int mPrevTime;			//前のフレームの時間
	static int mCountStartTime;		//測定開始時刻
	static int mCount;				//カウンタ
	static float mFps;				//fps
	static float mDeltaTime;		//フレーム間の時間
	static float mTime;				//起動してからの経過時間

public:

	//初期化
	static void Initialize();

	//計算の更新
	static bool Update();

	//デバッグ用にFPSを描画する
	static void Draw();
	//処理が早かった場合、目標FPSになるまで待つ
	static void Wait();
	//ゲームを起動してからの経過時間を取得
	static float GetTime();
	//フレーム間の経過時間を取得
	static float GetDeltaTime();
};