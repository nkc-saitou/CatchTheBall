#pragma once

//エフェクト再生用のハンドル
typedef int EffectHandle;

#include <iostream>
#include "EffekseerForDXLib.h"
#include "Singleton.h"
#include "FileManager.h"
#include "EffectType.h"
#include "EffectObject.h"

using namespace std;

//
// エフェクトを管理するクラス
//
class EffectManager final : public Singleton<EffectManager>
{
	EffectHandle loadedEffect[static_cast<int>(EffectType::MuzzleFlash) + 1];

	bool isLoadEffect = false;

	//タイプからエフェクトのファイル名を返す
	string GetEffectName(EffectType type);


public:

	EffectManager();
	~EffectManager ();

	//エフェクトの初期化
	void Initialize();
	//エフェクトの終了
	void Finalize();

	// エフェクトのロード
	void Load ();

	// エフェクトの更新
	void Update ();

	// エフェクトの再生
	static void CreateEffect(EffectType effectType, float x, float y);
	static EffectObject* CreateEffect(EffectType effectType, float x, float y, bool autoDestroy = false);
};

