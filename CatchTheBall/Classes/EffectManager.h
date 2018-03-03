#pragma once

//エフェクト再生用のハンドル
typedef int EffectHandle;

#include <iostream>
#include <map>
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
	EffectHandle loadedEffect[static_cast<int>(EffectType::PlayerJump)];

	bool isLoadEffect = false;

	
	//エフェクトの初期化
	void Initialize();

	//タイプからエフェクトのファイル名を返す
	string GetEffectName(EffectType type);

public:

	EffectManager();
	~EffectManager ();

	// エフェクトのロード
	void Load ();

	// エフェクトの更新
	void Update ();

	// エフェクトの再生
	static EffectObject* CreateEffect(EffectType effectType);
	static EffectObject* CreateEffect(EffectType effectType, bool autoPlay);
};

