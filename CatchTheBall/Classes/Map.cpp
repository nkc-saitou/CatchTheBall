#include "DxLib.h"
#include "Map.h"
#include "MapObject.h"
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

struct Cell {
	int map_gh,obj_gh;
	string map_str,obj_str;
};

Cell cell[MAP_SIZEX][MAP_SIZEY];
int chipgh[20];
int objChipgh[20];
int handle;
int Map::map_width = 0, Map::map_height = 8;

// ファイルを開く
void Map::Open(string pass)
{
	LoadDivGraph("Resources\\Image\\mapChip.png", 16, 4, 4, 64, 64, chipgh);
	LoadDivGraph("Resources\\Image\\ObjectChip.png", 16, 4, 4, 64, 64, objChipgh);
	handle = LoadGraph(BACKGROUND);
	
	// ファイルの列
	int width = 0, obj_width = 0;
	// ファイルの行
	int height = -1, obj_height = 1;

	ifstream ifs(pass);
	string str = "";

	// ファイルの中身を一行ずつ読み取る
	while (getline(ifs, str)) {
		string tmp = "";
		istringstream stream(str);
		while (getline(stream, tmp, ',')) {
			// マップチップ配置
			if (height > 8) {
				// 文字列を保存
				cell[obj_width][obj_height].obj_str = tmp;
				// 文字列をint型に変更
				int num = atoi(cell[obj_width][obj_height].obj_str.c_str());
				// 画像番号を保存
				cell[obj_width][obj_height].obj_gh = objChipgh[num];
				// 次の文字へ
				obj_width++;
			}
			// オブジェクト(プレイヤー配置)
			else if(height < 9){
				// 文字列を保存
				cell[width][height].map_str = tmp;
				// 文字列をint型に変更
				int num = atoi(cell[width][height].map_str.c_str());
				// 画像番号を保存
				cell[width][height].map_gh = chipgh[num];
				// 次の文字へ
				width++;
			}
		}

		if (height > 8) {
			// 先頭へ
			obj_width = 0;
			// 改行
			obj_height++;
		}
		else if (height < 9) {
			map_width = width;
			// 先頭へ
			width = 0;
			// 改行
			height++;
		}
	}

	// MapObjectに登録
	for (int i = 0; i < map_width; i++) {
		for (int j = 0; j < map_height; j++) {
			new MapObject(i * 64, j * 64, 1, cell[i][j].map_gh);
			new MapObject(i * 64, j * 64, 1, cell[i][j].obj_gh);
			/*DrawGraph(i * 64, j * 64, cell[i][j].ih, TRUE);
			DrawGraph(i * 64 + PosX, j* 64, cell[i][j].oh, TRUE);*/
		}
	}
}

void Map::Draw(int PosX)
{
	
}
