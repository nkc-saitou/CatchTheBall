#include "EffectObject.h"
#include <iostream>

EffectObject::EffectObject(EffectHandle handle) : Object(10)
{
	loadedEffectHandle = handle;
}

EffectObject::~EffectObject() {}

void EffectObject::Update() {

	if (_canControl) {
		//移動
		int movespeed = 4;
		if (Input::Instance()->Button(KEY_INPUT_D)) {
			_isleft = false;
			float posX = PositionX() + movespeed;
			PositionX(posX);
		}

		if (Input::Instance()->Button(KEY_INPUT_A)) {
			_isleft = true;
			PositionX(PositionX() - movespeed);
		}
		if (Input::Instance()->Button(KEY_INPUT_W)) {
			PositionY(PositionY() - movespeed);
		}
		if (Input::Instance()->Button(KEY_INPUT_S)) {
			PositionY(PositionY() + movespeed);
		}

		//回転
		float rotSpeed = 0.1f;
		if (Input::Instance()->Button(KEY_INPUT_Q)) {
			Rotation(Rotation() + rotSpeed);
		}
		if (Input::Instance()->Button(KEY_INPUT_E)) {
			Rotation(Rotation() - rotSpeed);
		}

		//拡大
		float scaleSpeed = 0.1f;
		if (Input::Instance()->Button(KEY_INPUT_SPACE)) {
			Scale(Scale() + scaleSpeed);
		}
		if (Input::Instance()->Button(KEY_INPUT_LSHIFT)) {
			Scale(Scale() - scaleSpeed);
		}
	}

	//自動削除する場合は毎フレーム確認する
	if (autoDestroy && IsEffekseer2DEffectPlaying(playingEffectHandle)) {
		//削除処理
		delete this;
	}

	SetPosPlayingEffekseer2DEffect(playingEffectHandle, PositionX(), PositionY(), 0);
	SetRotationPlayingEffekseer2DEffect(playingEffectHandle, 0, 0, Rotation());
	float scale = EFFECT_SCALE * Scale();
	SetScalePlayingEffekseer2DEffect(playingEffectHandle, scale, scale, scale);
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