#pragma once
#include "BaseScene.h"

#define STAGESELECT_TEXT "Stage_Select.png"
#define STAGESELECT_BACK "TitleTest.png"
#define SELECT_RIGHTARROW "RightArrow.png"
#define SELECT_LEFTARROW "LeftArrow.png"
#define STAGE_BOARD "frame.png"
#define START_TEXT "Start.png"

class Select : public BaseScene
{
public:
	Select();
	~Select();

	// 初期化
	void Initialize();
	// 更新
	void Update();
	// 描画
	void Draw();
};