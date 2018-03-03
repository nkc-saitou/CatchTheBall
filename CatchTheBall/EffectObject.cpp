#include "EffectObject.h"



EffectObject::EffectObject() {}


EffectObject::~EffectObject() {}

void EffectObject::Update() {
	
	SetPosPlayingEffekseer2DEffect(playingEffectHandle, position_x, position_y, 0);

	// エフェクトの拡大率を設定する。
	// Effekseerで作成したエフェクトは2D表示の場合、小さすぎることが殆どなので必ず拡大する。
	//SetScalePlayingEffekseer2DEffect(playingEffectHandle, 25.0f, 25.0f, 25.0f);
}