#include "EffectObject.h"
#include "Time.h"

EffectObject::EffectObject(EffectHandle handle) {
	loadedEffectHandle = handle;
}

EffectObject::~EffectObject() {}

void EffectObject::Update() {

	int movespeed = 4;

	if (Input::Instance()->Button(KEY_INPUT_RIGHT)) {
		_isleft = false;
		PositionX(PositionX() + movespeed);
	}
	if (Input::Instance()->Button(KEY_INPUT_LEFT)) {
		_isleft = true;
		PositionX(PositionX() - movespeed);
	}
	if (Input::Instance()->Button(KEY_INPUT_UP)) {
		PositionY(PositionY() - movespeed);
	}
	if (Input::Instance()->Button(KEY_INPUT_DOWN)) {
		PositionY(PositionY() + movespeed);
	}

	//自動削除する場合は毎フレーム確認する
	if (autoDestroy && IsEffekseer2DEffectPlaying(playingEffectHandle)) {
		//削除処理
		delete this;
	}

	SetPosPlayingEffekseer2DEffect(playingEffectHandle, PositionX(), PositionY(), 0);
	SetRotationPlayingEffekseer2DEffect(playingEffectHandle, 0, _isleft * -3.141519, Rotation());
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