#pragma once
#include <string>
using namespace std;

#define STAGE_FILE_1 "Resources\\StageData.ctbst"
#define STAGE_FILE_2 "Resources\\StageLong.ctbst"
#define BACKGROUND "Resources\\image\\BackGround.png"

#define STAGE1_SIZE 20
#define STAGE_LONG_SIZE 100

#define MAP_SIZEX 100
#define MAP_SIZEY 8

/*
Mapクラス
MapChipの読み込みをする(テスト)

 使い方(例)
  include して
  Map::Open() でファイルを開き
  Map::Draw() で描画
*/

class Map
{
public:
	// ファイルを開く (string ファイル名 int マップのサイズ)
	static void Open(string);

	static void Draw(int);

	static int map_width, map_height;
};