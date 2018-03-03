#include "EffectManager.h"

EffectManager::EffectManager() {}

EffectManager::~EffectManager() {}

void EffectManager::Initialize() {

	// Effekseerを初期化する。
	// 引数には画面に表示する最大パーティクル数を設定する。
	if (Effkseer_Init(2000) == -1) {
		cout << "警告 : Effekseerの初期化に失敗しました" << endl;
		return;
	}

	// フルスクリーンウインドウの切り替えでリソースが消えるのを防ぐ。
	// Effekseerを使用する場合は必ず設定する。
	SetChangeScreenModeGraphicsSystemResetFlag(FALSE);

	// DXライブラリのデバイスロストした時のコールバックを設定する。
	// ウインドウとフルスクリーンの切り替えが発生する場合は必ず実行する。
	// ただし、DirectX11を使用する場合は実行する必要はない。
	Effekseer_SetGraphicsDeviceLostCallbackFunctions();

	// Effekseerに2D描画の設定をする。
	Effekseer_Set2DSetting(640, 480);

	// Zバッファを有効にする。
	// Effekseerを使用する場合、2DゲームでもZバッファを使用する。
	SetUseZBuffer3D(TRUE);

	// Zバッファへの書き込みを有効にする。
	// Effekseerを使用する場合、2DゲームでもZバッファを使用する。
	SetWriteZBuffer3D(TRUE);

	cout << "Effect initialized." << endl;
}

void EffectManager::Finalize() {

	// エフェクトを削除する。(Effekseer終了時に破棄されるので削除しなくてもいい)
	for (auto i = 0; i < sizeof(loadedEffect) / sizeof(EffectHandle); i++) {
		DeleteEffekseerEffect(loadedEffect[i]);
	}

	// Effekseerを終了する。
	Effkseer_End();

	cout << "Effect finalized." << endl;
}

string EffectManager::GetEffectName(EffectType type) {
	switch (type) {
		case EffectType::ExplosionFireworkClear:
		case EffectType::ExplosionFireworkGameOver:
		case EffectType::FireworkTrailLv1:
		case EffectType::FireworkTrailLv2:
		case EffectType::FireworkTrailLv3:
		case EffectType::MazzleFlash:
		case EffectType::PlayerActive:
		case EffectType::PlayerDeath:
		case EffectType::PlayerMove:
		case EffectType::PlayerJump:
			return "laser.efk";
		default:
			return "";
	}
}

void EffectManager::Load() {

	// エフェクトを読み込む。
	for (auto i = 0; i < sizeof(loadedEffect) / sizeof(EffectHandle); i++) {
		loadedEffect[i] = FileManager::Instance()->GetFileHandle(GetEffectName(static_cast<EffectType>(i)));
	}

	isLoadEffect = true;
	cout << "Effect loaded." << endl;
}


void EffectManager::Update() {

	// Effekseerにより再生中のエフェクトを更新する。
	UpdateEffekseer2D();

	// Effekseerにより再生中のエフェクトを描画する。
	DrawEffekseer2D();

}

EffectObject* EffectManager::CreateEffect(EffectType effectType) {
	return CreateEffect(effectType, true);
}

EffectObject* EffectManager::CreateEffect(EffectType effectType, bool autoPlay){

	if (Instance()->isLoadEffect == false) return NULL;

	EffectObject *effectObject = new EffectObject(Instance()->loadedEffect[static_cast<int>(effectType)]);

	if (autoPlay) effectObject->PlayEffect();

	return effectObject;
}

