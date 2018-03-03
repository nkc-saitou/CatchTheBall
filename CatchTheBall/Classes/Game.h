#pragma once

// 画像データの string 
#define BACKGROUND_IMAGE "test2.png"
#define PLAYER_IMAGE "player.png"
#define BOM_IMAGE "Bom.png"

class Game
{
public:
	// 初期化
	static void Game_Instialize();

	//更新
	static void Game_Update();

	//描画
	static void Game_Draw();
};

