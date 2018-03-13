#pragma once
#include "BaseScene.h"
 
// 画像データの string
#define TITLE_IMAGE "TitleTest.png"
#define TITLE_LOGO "Title_Logo.png"
#define START_TEXT "Start.png"
#define CLOUD_IMAGE "scene_01_cloud.png"

class Title : public BaseScene
{
	const int MOVE_SCENE_PAD = PAD_INPUT_3;
	const int MOVE_SCENE_KEY = KEY_INPUT_SPACE;

	bool isMovingScene;

public:
	Title();
	~Title();

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