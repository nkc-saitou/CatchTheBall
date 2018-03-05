#include "DxLib.h"
#include "EffectManager.h"
#include "SceneMgr.h"
#include "Input.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	// DXライブラリの表示方法をウィンドウモードに変更する。
	ChangeWindowMode(true);

	//描画先を裏画面に変更する。
	SetDrawScreen(DX_SCREEN_BACK);

	// DirectX9を使用するようにする。(DirectX11も可)
	// Effekseerを使用するには必ず設定する。
	SetUseDirect3DVersion(DX_DIRECT3D_9);

	// DXライブラリを初期化する。
	if (DxLib_Init() == -1) return -1;

	// 何でもいいので画像を読み込む。
	int grBackgroundHandle = LoadGraph(_T("Texture/Background.png"));
	int grFrontHandle = LoadGraph(_T("Texture/Front.png"));

	// 時間を初期化する(定期的にエフェクトを再生するため)
	int time = 0;

	// フルスクリーン切り替え用フラグを設定する。(F1、F2でウインドウ、フルスクリーンを切り替えれるようにする。)
	bool isFullScreen = false;

	//エフェクトマネージャーを初期化する
	EffectManager::Instance()->Initialize();
	EffectManager::Instance()->Load();

	// 再生中のエフェクトを初期化する。
	EffectObject *obj = EffectManager::CreateEffect(EffectType::ExplosionFireworkClear, false);
	obj->PositionX(100.0f);
	obj->PositionY(250.0f);
	obj->Scale(25.0f);

	// シーンの初期化
	SceneMgr::Instance()->SceneMgr_Instialize();


	while (!ProcessMessage() && !ClearDrawScreen() && !CheckHitKey(KEY_INPUT_ESCAPE))
	{
		// 定期的にエフェクトを再生する
		if (time % 60 == 0)
		{
			obj->StopEffect();
			obj->PlayEffect();
			// エフェクトの位置をリセットする。
			obj->PositionX(100.0f);
		}

		obj->PositionX(obj->PositionX() + 2);

		obj->Update();

		//---------------------------------------------
		// シーンの更新
		SceneMgr::Instance()->SceneMgr_Update();
		// シーンの描画
		SceneMgr::Instance()->SceneMgr_Draw();
		//---------------------------------------------

		// 何でもいいので画像を描画する。
		// こうして描画した後でないと、Effekseerは描画できない。
		DrawGraph(0, 0, grBackgroundHandle, TRUE);

		//入力情報の更新
		Input::Instance()->InputMemory();

		EffectManager::Instance()->Update();

		// エフェクトの上にも画像を描画できる。
		DrawGraph(0, 0, grFrontHandle, TRUE);

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
	}

	EffectManager::Instance()->Finalize();

	// DXライブラリを終了する。
	DxLib_End();

	return 0;
}