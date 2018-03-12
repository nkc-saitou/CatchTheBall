#include "DxLib.h"
#include "BaseScene.h"
#include "ObjectManager.h"
#include "EffectManager.h"
#include "Input.h"
#include "Time.h"
#include "FireworkObject.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	// DXライブラリの表示方法をウィンドウモードに変更する。
	ChangeWindowMode(true);

	// DirectX9を使用するようにする。(DirectX11も可)
	// Effekseerを使用するには必ず設定する。
	SetUseDirect3DVersion(DX_DIRECT3D_9);

	SetWaitVSyncFlag(FALSE);

	// DXライブラリを初期化する。
	if (DxLib_Init() == -1) return -1;

	//描画先を裏画面に変更する。
	SetDrawScreen(DX_SCREEN_BACK);

	// 何でもいいので画像を読み込む。
	int grBackgroundHandle = LoadGraph(_T("Texture/Background.png"));
	int grFrontHandle = LoadGraph(_T("Texture/Front.png"));

	// 時間を初期化する(定期的にエフェクトを再生するため)
	int time = 0;

	// フルスクリーン切り替え用フラグを設定する。(F1、F2でウインドウ、フルスクリーンを切り替えれるようにする。)
	bool isFullScreen = false;

	//オブジェクトマネージャーを初期化する
	ObjectManager::Instance()->Initialize();

	//エフェクトマネージャーを初期化する
	EffectManager::Instance()->Initialize();
	EffectManager::Instance()->Load();

	// シーンの初期化
	Scene* scene = new Scene();

	ScreenFlip();
	WaitKey();

	//起動時間の初期化
	Time::Initialize();

	while (!ProcessMessage() && !ClearDrawScreen() && !CheckHitKey(KEY_INPUT_ESCAPE))
	{
		// 定期的にエフェクトを再生する
		if (time % 60 == 0)
		{
			//obj->StopEffect();
			// エフェクトの位置をリセットする。
			//obj->PositionX(100.0f);
		}

		if (Input::Instance()->ButtonDown(KEY_INPUT_G)) {
			//花火の生成
			auto g = new FireworkObject();
			g->SetPosition(100, 100);
			g->SetForce(300, 1 / 1.4142, -1 / 1.4142);
			//g->SetForce(300, 1, 0);
		}

		//obj->PositionX(obj->PositionX() + 2);

		//---------------------------------------------
		// シーンの更新
		scene->Update();
		// シーンの描画
		scene->Draw();
		//---------------------------------------------

		// 何でもいいので画像を描画する。
		// こうして描画した後でないと、Effekseerは描画できない。
		DrawGraph(0, 0, grBackgroundHandle, TRUE);

		//入力情報の更新
		Input::Instance()->InputMemory();

		ObjectManager::Instance()->Update();
		ObjectManager::Instance()->Draw();

		EffectManager::Instance()->Update();

		// エフェクトの上にも画像を描画できる。
		DrawGraph(0, 0, grFrontHandle, TRUE);
	
		Time::Update();
		//FPSを左上に表示
		Time::Draw();

		// スクリーンを入れ替える。
		ScreenFlip();

		// 時間を経過させる。
		time++;


		// フルスクリーンの切り替えを行う。
		if (CheckHitKey(KEY_INPUT_F1) && !isFullScreen)
		{
			ChangeWindowMode(FALSE);
			SetDrawScreen(DX_SCREEN_BACK);
			isFullScreen = true;
		}
		if (CheckHitKey(KEY_INPUT_F2) && isFullScreen)
		{
			ChangeWindowMode(TRUE);
			SetDrawScreen(DX_SCREEN_BACK);
			isFullScreen = false;
		}

		//-------------------------
		//FPS安定させるやつ
		Time::Wait();
	}


	EffectManager::Instance()->Finalize();
	ObjectManager::Instance()->Finalize();

	// DXライブラリを終了する。
	DxLib_End();

	return 0;
}