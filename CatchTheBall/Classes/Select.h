#pragma once

#define STAGESELECT_TEXT "Stage_Select.png"
#define STAGESELECT_BACK "TitleTest.png"
#define SELECT_RIGHTARROW "RightArrow.png"
#define SELECT_LEFTARROW "LeftArrow.png"
#define STAGE_BOARD "frame.png"
#define START_TEXT "Start.png"

class Select
{
public:
	// 初期化
	static void Select_Initialize();
	// 更新
	static void Select_Update();
	// 描画
	static void Select_Draw();
};