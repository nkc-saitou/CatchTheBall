#pragma once
#include "BaseScene.h"

// 画像データの string 
#define BACKGROUND_IMAGE "test2.png"
#define PLAYER_IMAGE "player.png"
#define BOM_IMAGE "Bom.png"

class Game : public BaseScene
{
public:
	Game();
	~Game();

	// 初期化
	void Initialize();

	//更新
	void Update();

	//描画
	void Draw();
};

