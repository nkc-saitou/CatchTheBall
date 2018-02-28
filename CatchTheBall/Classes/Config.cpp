#include "Config.h"
#include "SceneMgr.h"
#include "DxLib.h"

// 画像格納変数
int Handle;

// 初期化
void Config_Instialize() 
{
	// 画像の読み込み
	Handle = LoadGraph("Resources\\image\\FireEmblem_Config.jpg");
}

//更新
void Config_Update(){
	//Escキーが押されていたら
    if(CheckHitKey(KEY_INPUT_ESCAPE)!=0){
		//シーンをメニューに変更
        SceneMgr_ChangeScene(eScene_Menu);
    }
}

//描画
void Config_Draw()
{
	// 画像描画
	DrawGraph(0, 0, Handle, false);
    DrawString(0, 0,"設定画面です。",GetColor(255,255,255));
    DrawString(0,20,"Escキーを押すとメニュー画面に戻ります。",GetColor(255,255,255));
}

