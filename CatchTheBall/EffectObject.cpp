#include "EffectObject.h"



EffectObject::EffectObject() {}


EffectObject::~EffectObject() {}

void EffectObject::Update() {
	
	SetPosPlayingEffekseer2DEffect(playingEffectHandle, position_x, position_y, 0);

	// �G�t�F�N�g�̊g�嗦��ݒ肷��B
	// Effekseer�ō쐬�����G�t�F�N�g��2D�\���̏ꍇ�A���������邱�Ƃ��w�ǂȂ̂ŕK���g�傷��B
	//SetScalePlayingEffekseer2DEffect(playingEffectHandle, 25.0f, 25.0f, 25.0f);
}