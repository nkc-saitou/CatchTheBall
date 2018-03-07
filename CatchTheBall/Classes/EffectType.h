#pragma once

enum class EffectType {
	
	ExplosionFireworkClear = 0,		//花火の爆発(クリア時)
	ExplosionFireworkGameOver,		//花火の爆発(ゲームオーバー時)

	FireworkTrailLv1,				//花火の速度確認用Lv1
	FireworkTrailLv2,				//花火の速度確認用Lv2
	FireworkTrailLv3,				//花火の速度確認用Lv3
	FireworkTrailClear,				//クリア時の花火のトレイル

	Player1Active,					//プレイヤー1が乗り移ったとき
	Player2Active,					//プレイヤー2が乗り移ったとき
	Player3Active,					//プレイヤー3が乗り移ったとき
	Player4Active,					//プレイヤー4が乗り移ったとき

	PlayerDeath,					//プレイヤーが死んだとき
	PlayerMove,						//プレイヤーが動いたとき
	PlayerJump,						//プレイヤーがジャンプしたとき
	MuzzleFlash,					//撃った時の火炎

};