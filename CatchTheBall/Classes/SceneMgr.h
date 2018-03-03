#pragma once
#include "Singleton.h"

#define FADE_IMAGE "test1.png"

typedef enum {
    eScene_Title,    //メニュー画面
    eScene_Game,    //ゲーム画面
    eScene_Config,  //設定画面
} eScene ;

class SceneMgr : public Singleton <SceneMgr>
{
public:
	SceneMgr();
	~SceneMgr();

	// 初期化
	void SceneMgr_Instialize();
	//更新
	void SceneMgr_Update();
	//描画
	void SceneMgr_Draw();
	// 引数 nextScene にシーンを変更する
	void SceneMgr_ChangeScene(eScene nextScene);
	// シーンフェード
	void SceneMgr_Fade();
};
