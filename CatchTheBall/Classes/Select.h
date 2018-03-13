#pragma once
#include "BaseScene.h"
#include "DxLib.h"

#define STAGESELECT_TEXT "Stage_Select.png"
#define STAGESELECT_BACK "TitleTest.png"
#define SELECT_RIGHTARROW "RightArrow.png"
#define SELECT_LEFTARROW "LeftArrow.png"
#define STAGE_BOARD "frame.png"
#define START_TEXT "Start.png"
#define STAGE1_IMAGE "View_Stage1.png"
#define STAGE2_IMAGE "View_StageLong.png"

class Select : public BaseScene
{
public:
	Select();
	~Select();

	// ファイル読み込み
	void LoadFile();
	// 読み込んだファイルの破棄
	void UnLoadFile();
	// 初期化
	void Initialize();
	// 更新
	void Update();
	// 描画
	void Draw();
};