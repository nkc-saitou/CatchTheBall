#include "DxLib.h"
#include "Map.h"
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

struct Cell {
	int ih,oh;
	string gh,ogh;
};

Cell cell[MAP_SIZEX][MAP_SIZEY];
int chipgh[20];
int objChipgh[20];
int handle;
int Map::map_width = 0, Map::map_height = 8;

// �t�@�C�����J��
void Map::Open(string pass)
{
	LoadDivGraph("Resources\\image\\mapChip.png", 16, 4, 4, 64, 64, chipgh);
	LoadDivGraph("Resources\\image\\ObjectChip.png", 16, 4, 4, 64, 64, objChipgh);
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
				cell[obj_width][obj_height].ogh = tmp;
				// �������int�^�ɕύX
				int num = atoi(cell[obj_width][obj_height].ogh.c_str());
				// �摜�ԍ���ۑ�
				cell[obj_width][obj_height].oh = objChipgh[num];
				// ���̕�����
				obj_width++;
			}
			// �I�u�W�F�N�g(�v���C���[�z�u)
			else if(height < 9){
				// �������ۑ�
				cell[width][height].gh = tmp;
				// �������int�^�ɕύX
				int num = atoi(cell[width][height].gh.c_str());
				// �摜�ԍ���ۑ�
				cell[width][height].ih = chipgh[num];
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
}

void Map::Draw(int PosX)
{
	//DrawGraph(0, 0, handle, TRUE);
	for (int i = 0; i < map_width; i++) {
		for (int j = 0; j < map_height; j++) {
			DrawGraph(i * 64, j * 64, cell[i][j].ih, TRUE);
			DrawGraph(i * 64 + PosX, j* 64, cell[i][j].oh, TRUE);
		}
	}
}
