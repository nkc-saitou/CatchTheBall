#pragma once

//�G�t�F�N�g�Đ��p�̃n���h��
typedef int EffectHandle;

#include "EffekseerForDXLib.h"
#include "Object.h"

class EffectObject : public Object{

	EffectHandle loadedEffectHandle;
	EffectHandle playingEffectHandle;

	bool isPlay = false;

public:
	EffectObject(EffectHandle handle);
	~EffectObject();

	virtual void Update() override;

	//�G�t�F�N�g�̍Đ�
	void PlayEffect();

	//�G�t�F�N�g�̒�~
	void StopEffect();
};

