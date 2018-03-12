#pragma once
#include <string>
using namespace std;

#define STAGE_FILE_1 "Resources\\StageData\\StageData.ctbst"
#define STAGE_FILE_2 "Resources\\StageData\\StageLong.ctbst"
#define BACKGROUND "Resources\\image\\BackGround.png"

#define STAGE1_SIZE 20
#define STAGE_LONG_SIZE 100

#define MAP_SIZEX 100
#define MAP_SIZEY 8

/*
Map�N���X
MapChip�̓ǂݍ��݂�����(�e�X�g)

 �g����(��)
  include ����
  Map::Open() �Ńt�@�C�����J��
  Map::Draw() �ŕ`��
*/

class Map
{
public:
	// �t�@�C�����J�� (string �t�@�C���� int �}�b�v�̃T�C�Y)
	static void Open(string);

	static void Draw(int);

	static int map_width, map_height;
};