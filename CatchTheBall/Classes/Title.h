#pragma once
#include "BaseScene.h"
 
// 画像データの string
#define TITLE_IMAGE "TitleTest.png"
#define TITLE_TEXT "TitleText.png"
#define PLAYER_IMAGE "player.png"
#define CLOUD_IMAGE "scene_01_cloud.png"

#pragma region UseFile

char* UseFile[] = {
	"TitleTes.png",
	"TitleText.png"
	"player.png"
	"scene_01_cloud.png",
	"bgm_maoudamashii_8bit02.mp3"
};
DivFile UseDivFile[] = {
	DivFile("mapChip.png", 10, 4, 4, 64, 64)
};

#pragma endregion

class Title : public BaseScene
{
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