#include "DxLib.h"
#include "Game.h"
#include "AudioManager.h"
#include "FileManager.h"
#include "Input.h"
#include "GameManager.h"

// x座標
int PosX, BomPosX;
// 画像 (マップチップ)
int G_Handle[16];

Game::Game()
{
	LoadFile();
}

Game::~Game()
{
	UnLoadFile();
}

// ゲームシーンで使用するファイルの読み込み
void Game::LoadFile()
{
	FileManager::Instance()->GetFileHandle(BACKGROUND_IMAGE);
	FileManager::Instance()->GetFileHandle(PLAYER_IMAGE);

	// 読み込み終わったら初期化
	Initialize();
}

// ゲームシーンで使用したファイルの破棄
void Game::UnLoadFile()
{
	FileManager::Instance()->Initialize();
}

// 初期化
void Game::Initialize() 
{
	AudioManager::Instance()->playBGM(GAME_BGM);
	LoadDivGraph("Resources\\image\\mapChip.png", 16, 4, 4, 64, 64, G_Handle);
}

//更新
void Game::Update()
{
	//Escキーが押されていたら
    if(Input::Instance()->ButtonDown(KEY_INPUT_ESCAPE)){
		AudioManager::Instance()->playSE(SE_SELECT);
		//シーンフェードしてからシーンをタイトルに変更
		Scene::SceneFade(Scene::TITLE);
    }
	if (Input::Instance()->ButtonDown(KEY_INPUT_SPACE)) {
		AudioManager::Instance()->playSE(SE_SHOT);
	}
	if (Input::Instance()->ButtonDown(KEY_INPUT_RETURN)) {
		AudioManager::Instance()->playSE(SE_DESTROY);
	}

	// 右キーが押されていたら
	if (Input::Instance()->Button(KEY_INPUT_RIGHT)) {
		// 移動量
		PosX += 3;

		// 移動中の音楽が再生されていなかったら音楽再生
		if (CheckSoundMem(FileManager::Instance()->GetFileHandle(SE_MOVE)) == 0) {
			PlaySoundMem(FileManager::Instance()->GetFileHandle(SE_MOVE), DX_PLAYTYPE_LOOP);
		}
		// 背景スクロール
		if (PosX >= 640) {
			PosX = 0;
		}
	}
	// 右キーが押されていなかったら
	else if(Input::Instance()->Button(KEY_INPUT_LEFT)) {
		// 移動量
		PosX -= 3;

		// 移動中の音楽が再生されていなかったら音楽再生
		if (CheckSoundMem(FileManager::Instance()->GetFileHandle(SE_MOVE)) == 0) {
			PlaySoundMem(FileManager::Instance()->GetFileHandle(SE_MOVE), DX_PLAYTYPE_LOOP);
		}
		// 背景スクロール
		if (PosX <= -640) {
			PosX = 0;
		}
	}
	else {
		// 移動中の音楽を止める
		StopSoundMem(FileManager::Instance()->GetFileHandle(SE_MOVE));
	}

	GameManager::Instance()->Update();
}

//描画
void Game::Draw()
{	
	// 背景スクロール
	DrawGraph(PosX, 0, FileManager::Instance()->GetFileHandle(BACKGROUND_IMAGE), TRUE);
	DrawGraph(PosX - 640, 0, FileManager::Instance()->GetFileHandle(BACKGROUND_IMAGE), TRUE);

	// マップ画像(仮)
	DrawGraph(PosX, 352, G_Handle[0], TRUE);
	DrawGraph(PosX + 64, 352, G_Handle[0], TRUE);
	DrawGraph(PosX + 64, 416, G_Handle[1], TRUE);
	DrawGraph(PosX, 416, G_Handle[1], TRUE);
	DrawGraph(PosX, 90, FileManager::Instance()->GetFileHandle(PLAYER_IMAGE), TRUE);
    DrawString(PosX, 0,"ゲーム画面です。",GetColor(255,255,255));
    DrawString(PosX,20,"Escキーを押すとメニュー画面に戻ります。",GetColor(255,255,255));
}
