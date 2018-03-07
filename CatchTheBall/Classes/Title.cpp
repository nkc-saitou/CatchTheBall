#include "DxLib.h"
#include "Title.h"
#include "Input.h"
#include "AudioManager.h"
#include "FileManager.h"
#include "Player.h"

// 雲のx座標
int cloudPosX[3];

Title::Title()
{
	LoadFile();

	Player* player = new Player(0, 0);
}

Title::~Title()
{
	UnLoadFile();
}

// タイトルに使用するファイルの読み込み
void Title::LoadFile()
{
	for (char* file : UseFile) {
		FileManager::Instance()->LoadFile(file);
	}
	for (DivFile dFile : UseDivFile) {
		FileManager::Instance()->LoadFile(dFile.name, dFile.numAll, dFile.numX, dFile.numY, dFile.sizeX, dFile.sizeY);
	}
}

//タイトルで使用したファイルの破棄
void Title::UnLoadFile()
{
	FileManager::Instance()->Initialize();
}

void Title::Initialize()
{
	AudioManager::Instance()->playBGM(TITLE_BGM);

	// 座標の初期化
	cloudPosX[0] = -100;
	cloudPosX[1] = -300;
	cloudPosX[2] = -500;
}

void Title::Update()
{
	// バックの雲を動かす
	for (int i = 0; i < 3; i++) {
	cloudPosX[i] += 1;
	if (cloudPosX[i] > 640) {
		cloudPosX[i] = -100;
	    }
	}

	//エンターキーが押されたら
	if (Input::Instance()->ButtonDown(KEY_INPUT_RETURN)) {
		AudioManager::Instance()->playSE(SE_SELECT);
		// シーンフェードしてからシーンをセレクトに変更
		Scene::SceneFade(Scene::SELECT);
	}
}

void Title::Draw()
{
	DrawGraph(0, 0, FileManager::Instance()->GetFileHandle(TITLE_IMAGE), FALSE);
	DrawGraph(cloudPosX[0], 100, FileManager::Instance()->GetFileHandle(CLOUD_IMAGE), TRUE);
	DrawGraph(cloudPosX[1], 40, FileManager::Instance()->GetFileHandle(CLOUD_IMAGE), TRUE);
	DrawGraph(cloudPosX[2], 160, FileManager::Instance()->GetFileHandle(CLOUD_IMAGE), TRUE);
	DrawGraph(0, 0, FileManager::Instance()->GetFileHandle(TITLE_TEXT), TRUE);
	DrawGraph(280, 288, FileManager::Instance()->GetFileHandle(PLAYER_IMAGE), TRUE);

	DrawString(230, 410, "■", GetColor(0, 0, 0));
}