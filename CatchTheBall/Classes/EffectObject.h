#pragma once

//エフェクト再生用のハンドル
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

	//エフェクトの再生
	void PlayEffect();

	//エフェクトの停止
	void StopEffect();
};

