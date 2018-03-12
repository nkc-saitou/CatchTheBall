#include "DxLib.h"
#include "BaseScene.h"
#include "Input.h"
#include "Time.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	// DXライブラリの表示方法をウィンドウモードに変更する。
	ChangeWindowMode(true);

	// DirectX9を使用するようにする。(DirectX11も可)
	// Effekseerを使用するには必ず設定する。
	SetUseDirect3DVersion(DX_DIRECT3D_9);

	// DXライブラリを初期化する。
	if (DxLib_Init() == -1) return -1;

	//描画先を裏画面に変更する。
	SetDrawScreen(DX_SCREEN_BACK);

	// シーンの初期化
	Scene* scene = new Scene();

	while (!ProcessMessage() && !ClearDrawScreen() && !CheckHitKey(KEY_INPUT_ESCAPE))
	{

		//---------------------------------------------
		// シーンの更新
		scene->Update();
		// シーンの描画
		scene->Draw();
		//---------------------------------------------

		//入力情報の更新
		Input::Instance()->InputMemory();

		//FPSを左上に表示
		Time::Draw();

		// スクリーンを入れ替える。
		ScreenFlip();

		//-------------------------
		//FPS安定させるやつ
		Time::Update();
		Time::Wait();
	}

	// DXライブラリを終了する。
	DxLib_End();

	return 0;
}