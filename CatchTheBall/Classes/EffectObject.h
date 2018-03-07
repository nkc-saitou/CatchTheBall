#pragma once

//�G�t�F�N�g�Đ��p�̃n���h��
typedef int EffectHandle;

#include "EffekseerForDXLib.h"
#include "Object.h"
#include "Input.h"
#include <math.h>

class EffectObject : public Object{

	EffectHandle loadedEffectHandle;
	EffectHandle playingEffectHandle;

	bool isPlay = false;

	bool _isleft = false;

public:

	bool autoDestroy;

	EffectObject(EffectHandle handle);
	~EffectObject();

	virtual void Update() override;

	//�G�t�F�N�g�̍Đ�
	void PlayEffect();

	//�G�t�F�N�g�̒�~
	void StopEffect();
};

