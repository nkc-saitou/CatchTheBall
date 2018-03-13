#include "DxLib.h"
#include "BaseScene.h"
#include "FileManager.h"
#include "ObjectManager.h"
#include "EffectManager.h"
#include "Input.h"
#include "Time.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	#pragma region DXライブラリの初期設定
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
	#pragma endregion

	#pragma region 初期化
	//マネージャーの初期化
	FileManager::Instance()->Initialize();

	ObjectManager::Instance()->Initialize();

	EffectManager::Instance()->Initialize();
	EffectManager::Instance()->Load();

	//起動時間の初期化
	Time::Initialize();

	// シーンの初期化
	Scene* scene = new Scene();
	#pragma endregion

	//メインループ
	while (!ProcessMessage() && !ClearDrawScreen() && !CheckHitKey(KEY_INPUT_ESCAPE))
	{
		#pragma region ループの初めに実行する
		//入力の更新
		Input::Instance()->InputMemory();
		//時間の計測
		Time::Update();
		#pragma endregion

		#pragma region 更新処理
		//アクティブシーンの更新
		scene->Update();
		// シーンの描画
		scene->Draw();
		//FPSを左上に表示
		Time::Draw();
		#pragma endregion

		// スクリーンを入れ替える。
		ScreenFlip();

		#pragma region ループの最後に実行する
		//FPSが早くならないように待つ
		Time::Wait();
		#pragma endregion

	}

	#pragma region マネージャーの終了処理
	EffectManager::Instance()->Finalize();
	ObjectManager::Instance()->Finalize();
	#pragma endregion

	// DXライブラリを終了する。
	DxLib_End();

	return 0;
}