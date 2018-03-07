#include "DxLib.h"
#include "Select.h"
#include "AudioManager.h"
#include "FileManager.h"
#include "Input.h"

// 画面の横サイズ
#define SCREEN_WIDTH 640
// ボードの1回ごとの移動量
#define BOARD_MOVE 8
// 矢印の移動限界
#define ARROW_LIMIT 42
// 矢印の原点
#define ARROW_ORIGIN 16
// 矢印の移動量
#define ARROW_MOVE 0.5f

// 矢印の座標
float ArrowPos[2];
// ボードの座標
int BoardPos;
// ボードの移動量
int MoveDistance;

// 移動したかどうか
bool isMove;
// 移動方向 (0 → 左、1 → 右)
int direction;

Select::Select()
{
	LoadFile();
}

Select::~Select()
{
	UnLoadFile();
}

// セレクトシーンで使用するファイルの読み込み
void Select::LoadFile()
{
	FileManager::Instance()->GetFileHandle(STAGESELECT_TEXT);
	FileManager::Instance()->GetFileHandle(STAGESELECT_BACK);
	FileManager::Instance()->GetFileHandle(SELECT_RIGHTARROW);
	FileManager::Instance()->GetFileHandle(SELECT_LEFTARROW);
	FileManager::Instance()->GetFileHandle(STAGE_BOARD);
	FileManager::Instance()->GetFileHandle(START_TEXT);

	// 読み込み終わったら初期化
	Initialize();
}

// セレクトシーンで使用したファイルの破棄
void Select::UnLoadFile()
{
	FileManager::Instance()->ResetData();
}

// 初期化
void Select::Initialize()
{
	AudioManager::Instance()->playBGM(SELECT_BGM);

	isMove = FALSE;

	// 初期座標の設定
	BoardPos = 120;
	ArrowPos[0] = 32;
	ArrowPos[1] = 576;
}

// 更新
void Select::Update()
{
	if (Input::Instance()->ButtonDown(KEY_INPUT_RETURN)) {
		// シーンフェードしてからシーンをゲームに変更
		Scene::SceneFade(Scene::GAME);
	}

	if (Input::Instance()->ButtonDown(KEY_INPUT_RIGHT)) {
		// 移動中でなければ
		if (!isMove) {
			direction = 1;
			isMove = TRUE;
		}
	}

	if (Input::Instance()->ButtonDown(KEY_INPUT_LEFT)) {
		// 移動中でなければ
		if (!isMove) {
			direction = 0;
			isMove = TRUE;
		}
	}

	if (isMove){
		switch (direction) {
		// 左移動
		case 0:
			// 移動量を計測
			MoveDistance += BOARD_MOVE;
			// 実際の座標の変更
			BoardPos += BOARD_MOVE;
			// 移動量がスクリーン1つ分を超えたら移動終了
			if (MoveDistance >= SCREEN_WIDTH) {
				MoveDistance = 0;
				isMove = FALSE;
			}
			break;
		// 右移動
		case 1:
			// 移動量を計測
			MoveDistance -= BOARD_MOVE;
			// 実際の座標の変更
			BoardPos -= BOARD_MOVE;
			// 移動量がスクリーン1つ分を超えたら移動終了
			if (MoveDistance <= -SCREEN_WIDTH) {
				MoveDistance = 0;
				isMove = FALSE;

			}
			break;
		}
	}

	ArrowPos[0] += ARROW_MOVE;
	if (ArrowPos[0] >= ARROW_LIMIT) {
		ArrowPos[0] = ARROW_ORIGIN;
	}
}

// 描画
void Select::Draw()
{
	DrawGraph(0, 0, FileManager::Instance()->GetFileHandle(STAGESELECT_BACK), TRUE);
	DrawGraph(ArrowPos[0], 200, FileManager::Instance()->GetFileHandle(SELECT_LEFTARROW), TRUE);
	DrawGraph(ArrowPos[1] - ArrowPos[0], 200, FileManager::Instance()->GetFileHandle(SELECT_RIGHTARROW), TRUE);
	DrawGraph(160, 10, FileManager::Instance()->GetFileHandle(STAGESELECT_TEXT), TRUE);
	DrawGraph(160, 406, FileManager::Instance()->GetFileHandle(START_TEXT), TRUE);
	DrawGraph(BoardPos, 90, FileManager::Instance()->GetFileHandle(STAGE_BOARD), TRUE);
	DrawGraph(BoardPos - 640, 90, FileManager::Instance()->GetFileHandle(STAGE_BOARD), TRUE);
	DrawGraph(BoardPos + 640, 90, FileManager::Instance()->GetFileHandle(STAGE_BOARD), TRUE);
}