#include "Game.h"
#include "SceneMgr.h"
#include "DxLib.h"

// x座標
int PosX;
// 画像
int music, B_Handle, G_Handle[16];

// 初期化
void Game_Instialize() 
{
	// 音楽再生(ループ)
	PlayMusic("game_maoudamashii_1_battle25.mp3", DX_PLAYTYPE_LOOP);
	// 画像の読み込み
	B_Handle = LoadGraph("images\\test2.png");
	LoadDivGraph("images\\mapChip.png", 16, 4, 4, 64, 64, G_Handle);
}

//更新
void Game_Update()
{
	//Escキーが押されていたら
    if(CheckHitKey(KEY_INPUT_ESCAPE)!=0){ 
		//シーンをメニューに変更
        SceneMgr_ChangeScene(eScene_Menu);
    }

	// 移動量
	PosX -= 2;
	// 背景スクロール
	if (PosX == -640) {
		PosX = 0;
	}
}

//描画
void Game_Draw()
{	
	// 背景スクロール
	DrawGraph(PosX, 0, B_Handle, TRUE);
	DrawGraph(PosX + 640, 0, B_Handle, TRUE);

	// マップ画像(仮)
	DrawGraph(0, 352, G_Handle[0], TRUE);
	DrawGraph(64, 352, G_Handle[0], TRUE);
	DrawGraph(64, 416, G_Handle[1], TRUE);
	DrawGraph(0, 416, G_Handle[1], TRUE);
    DrawString(0, 0,"ゲーム画面です。",GetColor(255,255,255));
    DrawString(0,20,"Escキーを押すとメニュー画面に戻ります。",GetColor(255,255,255));
}
