#include "EffectObject.h"

EffectObject::EffectObject(EffectHandle handle) {
	loadedEffectHandle = handle;
}

EffectObject::~EffectObject() {}

void EffectObject::Update() {
	SetPosPlayingEffekseer2DEffect(playingEffectHandle, PositionX(), PositionY(), 0);
	SetScalePlayingEffekseer2DEffect(playingEffectHandle, Scale(), Scale(), 0);
}

void EffectObject::PlayEffect() {
	playingEffectHandle = PlayEffekseer2DEffect(loadedEffectHandle);
}

void EffectObject::StopEffect() {
	StopEffekseer2DEffect(playingEffectHandle);
}
