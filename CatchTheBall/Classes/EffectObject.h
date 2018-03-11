#pragma once

//エフェクト再生用のハンドル
typedef int EffectHandle;

#include "EffekseerForDXLib.h"
#include "Object.h"
#include "Input.h"
#include <math.h>

class EffectObject : public Object{

	const float EFFECT_SCALE = 25.0f;

	EffectHandle loadedEffectHandle;
	EffectHandle playingEffectHandle;

	bool isPlay = false;

	bool _isleft = false;

public:

	bool autoDestroy;
	bool _canControl = false;

	EffectObject(EffectHandle handle);
	~EffectObject();

	virtual void Update() override;
	virtual void Draw(float cameraX, float cameraY) override;

	//エフェクトの再生
	void PlayEffect();

	//エフェクトの停止
	void StopEffect();
};

