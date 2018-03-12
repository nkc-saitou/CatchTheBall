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

// �t�@�C�����J��
void Map::Open(string pass)
{
	LoadDivGraph("Resources\\Image\\mapChip.png", 16, 4, 4, 64, 64, chipgh);
	LoadDivGraph("Resources\\Image\\ObjectChip.png", 16, 4, 4, 64, 64, objChipgh);
	handle = LoadGraph(BACKGROUND);
	
	// �t�@�C���̗�
	int width = 0, obj_width = 0;
	// �t�@�C���̍s
	int height = -1, obj_height = 1;

	ifstream ifs(pass);
	string str = "";

	// �t�@�C���̒��g����s���ǂݎ��
	while (getline(ifs, str)) {
		string tmp = "";
		istringstream stream(str);
		while (getline(stream, tmp, ',')) {
			// �}�b�v�`�b�v�z�u
			if (height > 8) {
				// �������ۑ�
				cell[obj_width][obj_height].obj_str = tmp;
				// �������int�^�ɕύX
				int num = atoi(cell[obj_width][obj_height].obj_str.c_str());
				// �摜�ԍ���ۑ�
				cell[obj_width][obj_height].obj_gh = objChipgh[num];
				// ���̕�����
				obj_width++;
			}
			// �I�u�W�F�N�g(�v���C���[�z�u)
			else if(height < 9){
				// �������ۑ�
				cell[width][height].map_str = tmp;
				// �������int�^�ɕύX
				int num = atoi(cell[width][height].map_str.c_str());
				// �摜�ԍ���ۑ�
				cell[width][height].map_gh = chipgh[num];
				// ���̕�����
				width++;
			}
		}

		if (height > 8) {
			// �擪��
			obj_width = 0;
			// ���s
			obj_height++;
		}
		else if (height < 9) {
			map_width = width;
			// �擪��
			width = 0;
			// ���s
			height++;
		}
	}

	// MapObject�ɓo�^
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
