#include "EffectManager.h"



EffectManager::EffectManager () {

	// Effekseerを初期化する。
	// 引数には画面に表示する最大パーティクル数を設定する。
	if (Effkseer_Init (2000) == -1) {
		cout << "警告 : Effekseerの初期化に失敗しました" << endl;
		return;
	}

	// フルスクリーンウインドウの切り替えでリソースが消えるのを防ぐ。
	// Effekseerを使用する場合は必ず設定する。
	SetChangeScreenModeGraphicsSystemResetFlag (FALSE);

	// DXライブラリのデバイスロストした時のコールバックを設定する。
	// ウインドウとフルスクリーンの切り替えが発生する場合は必ず実行する。
	// ただし、DirectX11を使用する場合は実行する必要はない。
	Effekseer_SetGraphicsDeviceLostCallbackFunctions ();

	// Effekseerに2D描画の設定をする。
	Effekseer_Set2DSetting (640, 480);
}

EffectManager::~EffectManager () {

	// Effekseerを終了する。
	Effkseer_End ();
}

void EffectManager::load() {

	// エフェクトを読み込む。
	EffectHandle effectHandle = LoadEffekseerEffect ("laser.efk");

	cout << "Effect loaded." << endl;
}


void EffectManager::update () {

	// 再生中のエフェクトを移動する。
	SetPosPlayingEffekseer2DEffect (playingEffectHandle, position_x, position_y, 0);
	position_x += 2.0f;

	// Effekseerにより再生中のエフェクトを更新する。
	UpdateEffekseer2D ();

	// Effekseerにより再生中のエフェクトを描画する。
	DrawEffekseer2D ();

}

EffectHandle EffectManager::playEffect (string name) {

}