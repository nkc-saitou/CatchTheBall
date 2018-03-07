#pragma once
#include "BaseScene.h"
 
// 画像データの string
#define TITLE_IMAGE "TitleTest.png"
#define TITLE_TEXT "TitleText.png"
#define PLAYER_IMAGE "player.png"
#define CLOUD_IMAGE "scene_01_cloud.png"

class Title : public BaseScene
{
public:
	Title();
	~Title();

	// 初期化
	void Initialize();
	// 更新
	void Update();
	// 描画
	void Draw();
};