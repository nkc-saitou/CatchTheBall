#pragma once
 
// 画像データの string
#define TITLE_IMAGE "TitleTest.png"
#define TITLE_TEXT "TitleText.png"
#define PLAYER_IMAGE "player.png"
#define CLOUD_IMAGE "scene_01_cloud.png"

class Title
{
public:
	// 初期化
	static void Title_Initialize();
	// 更新
	static void Title_Update();
	// 描画
	static void Title_Draw();
};