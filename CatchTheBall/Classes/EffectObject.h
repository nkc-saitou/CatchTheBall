#pragma once

//エフェクト再生用のハンドル
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

	//エフェクトの再生
	void PlayEffect();

	//エフェクトの停止
	void StopEffect();
};

