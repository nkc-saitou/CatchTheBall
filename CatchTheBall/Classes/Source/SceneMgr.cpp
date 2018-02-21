#include "DxLib.h"
#include "Config.h"
#include "Game.h"
#include "Menu.h"
#include "SceneMgr.h"

//シーン管理変数
static eScene Scene = eScene_Menu;   
// 次のシーン
static eScene nextScene;

// 初期化
void SceneMgr_Instialize() 
{
	switch (Scene) 
	{       
    //シーンによって処理を分岐
	case eScene_Menu:    //現在の画面がメニューなら
		//Menu_Update();   //メニュー画面の更新処理をする
		break;//以下略
	case eScene_Game:
		Game_Instialize();
		break;
	case eScene_Config:
		Config_Instialize();
		break;
	}
}

//更新
void SceneMgr_Update(){
    switch(Scene){      
	//シーンによって処理を分岐
    case eScene_Menu:    //現在の画面がメニューなら
        Menu_Update();   //メニュー画面の更新処理をする
        break;//以下略
    case eScene_Game:
        Game_Update();
        break;
    case eScene_Config:
        Config_Update();
        break;
    }
}

//描画
void SceneMgr_Draw(){
    switch(Scene){     
	//シーンによって処理を分岐
    case eScene_Menu:   //現在の画面がメニュー画面なら
        Menu_Draw();    //メニュー画面の描画処理をする
        break;//以下略
    case eScene_Game:
		Game_Draw();
        break;
    case eScene_Config:
        Config_Draw();
        break;
    }
}

// 引数 nextScene にシーンを変更する
void SceneMgr_ChangeScene(eScene NextScene){
	// 次のシーンの情報を格納
	nextScene = NextScene;
	// シーンフェード
	SceneMgr_Fade();
}

// シーンフェード
void SceneMgr_Fade()
{
	// フェード用変数(透明度,フェード用画像)
	int alpha, FadeIn;
	FadeIn = LoadGraph("images\\test1.png");

	SetDrawScreen(DX_SCREEN_BACK);

	// フェードイン
	for (alpha = 0; alpha < 255; alpha += 3)
	{
		ClearDrawScreen();
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		SceneMgr_Draw();

		// フェードイン開始
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
		DrawGraph(0, 0, FadeIn, TRUE);
		ScreenFlip();
	}

	StopMusic();

	// 次のシーンに切り替え
	Scene = nextScene;
	// 次のシーンの初期化
	SceneMgr_Instialize();

	// フェードアウト
	for (alpha = 255; alpha > 0; alpha -= 3)
	{
		ClearDrawScreen();
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		SceneMgr_Draw();

		// フェードアウト開始
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
		DrawGraph(0, 0, FadeIn, TRUE);
		ScreenFlip();
	}

	// 描画のブレンドを切る
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND,0);
	ScreenFlip();
}