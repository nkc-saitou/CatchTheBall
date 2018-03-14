#pragma once

#include "FileManager.h"
#include "DxLib.h"
#include "EffectManager.h"
#include "EffectType.h"
#include "ObjectManager.h"
#include "UI.h"

class Result
{
	int gh;
	double x,y,frameX,frameY;
	bool filstFlg;
	EffectObject *fireworkEffect;
	EffectObject *trailEffect;

	UI *frameUI;
public:
	Result();
	~Result();
	void Update();
	void Draw();
};