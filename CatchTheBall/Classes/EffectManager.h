#pragma once

#include <iostream>
#include "EffekseerForDXLib.h"
#include "Singleton.h"

using namespace std;

//エフェクト再生用のハンドル
typedef int EffectHandle;

enum class EffectType {
	ExplosionFireworkClear,		//花火の爆発(クリア時)
	ExplosionFireworkGameOver,	//花火の爆発(ゲームオーバー時)
	
	FireworkTrailLv1,			//花火の速度確認用Lv1
	FireworkTrailLv2,			//花火の速度確認用Lv2
	FireworkTrailLv3,			//花火の速度確認用Lv3

	MazzleFlash,				//撃った時の火炎
	PlayerActive,				//プレイヤーが乗り移ったとき
	PlayerDeath,				//プレイヤーが死んだとき
	PlayerMove,					//プレイヤーが動いたとき
	PlayerJump,					//プレイヤーがジャンプしたとき

};

//
// エフェクトを管理するクラス
//
class EffectManager final : public Singleton<EffectManager>
{
	const char (*effectName)[];
	map

	bool isLoadEffect = false;

	EffectManager ();



public:

	~EffectManager ();

	// エフェクトのロード
	void load ();

	// エフェクトの更新
	void update ();

	// エフェクトの再生
	EffectHandle playEffect (string name);
};

