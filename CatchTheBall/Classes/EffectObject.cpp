#include "EffectObject.h"

EffectObject::EffectObject(EffectHandle handle) {
	loadedEffectHandle = handle;
}

EffectObject::~EffectObject() {}

void EffectObject::Update() {
	SetPosPlayingEffekseer2DEffect(playingEffectHandle, PositionX(), PositionY(), 0);
	SetScalePlayingEffekseer2DEffect(playingEffectHandle, Scale(), Scale(), Scale());
}

void EffectObject::PlayEffect() {

	if (isPlay == true) return;

	playingEffectHandle = PlayEffekseer2DEffect(loadedEffectHandle);
	isPlay = true;
}

void EffectObject::StopEffect() {

	if (isPlay == false) return;

	StopEffekseer2DEffect(playingEffectHandle);
	isPlay = false;
}
