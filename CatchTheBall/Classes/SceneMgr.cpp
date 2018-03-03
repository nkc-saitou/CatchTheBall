#include "DxLib.h"
#include "Config.h"
#include "Game.h"
#include "Title.h"
#include "SceneMgr.h"
#include "AudioManager.h"
#include "FileManager.h"

//シーン管理変数
static eScene Scene;   
// 次のシーン
static eScene nextScene;

SceneMgr::SceneMgr()
{
	Scene = eScene_Title;
}

SceneMgr::~SceneMgr()
{

}

// 初期化
void SceneMgr::SceneMgr_Instialize() 
{
	switch (Scene) 
	{       
    //シーンによって処理を分岐
	case eScene_Title:    //現在の画面がメニューなら
		Title::Title_Instialize();   //メニュー画面の更新処理をする
		break;//以下略
	case eScene_Game:
		Game::Game_Instialize();
		break;
	case eScene_Config:
		Config_Instialize();
		break;
	}
}

//更新
void SceneMgr::SceneMgr_Update(){
    switch(Scene){      
	//シーンによって処理を分岐
    case eScene_Title:    //現在の画面がメニューなら
        Title::Title_Update();   //メニュー画面の更新処理をする
        break;//以下略
    case eScene_Game:
        Game::Game_Update();
        break;
    case eScene_Config:
        Config_Update();
        break;
    }
}

//描画
void SceneMgr::SceneMgr_Draw(){
    switch(Scene){     
	//シーンによって処理を分岐
    case eScene_Title:   //現在の画面がメニュー画面なら
        Title::Title_Draw();    //メニュー画面の描画処理をする
        break;//以下略
    case eScene_Game:
		Game::Game_Draw();
        break;
    case eScene_Config:
        Config_Draw();
        break;
    }
}

// 引数 nextScene にシーンを変更する
void SceneMgr::SceneMgr_ChangeScene(eScene NextScene){
	// 次のシーンの情報を格納
	nextScene = NextScene;
	// シーンフェード
	SceneMgr_Fade();
}

// シーンフェード
void SceneMgr::SceneMgr_Fade()
{
	// フェード用変数(透明度,フェード用画像)
	int alpha;

	SetDrawScreen(DX_SCREEN_BACK);

	// フェードアウト
	for (alpha = 0; alpha < 255; alpha += 3)
	{
		ClearDrawScreen();
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	    SceneMgr_Draw();

		// フェードイン開始
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
		DrawGraph(0, 0, FileManager::Instance()->GetFileHandle(FADE_IMAGE), TRUE);
		// 同時に音量もフェード
		AudioManager::Instance()->VolumeFade(alpha);
		ScreenFlip();
	}

	// 次のシーンに切り替え
	Scene = nextScene;
	// 次のシーンの初期化
	SceneMgr_Instialize();

	// フェードイン
	for (alpha = 255; alpha > 0; alpha -= 3)
	{
		ClearDrawScreen();
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		SceneMgr_Draw();

		// フェードアウト開始
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
		DrawGraph(0, 0, FileManager::Instance()->GetFileHandle(FADE_IMAGE), TRUE);
		// 同時に音量もフェード
		AudioManager::Instance()->VolumeFade(alpha);
		ScreenFlip();
	}

	// 描画のブレンドを切る
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND,0);
	ScreenFlip();
}