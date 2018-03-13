#pragma once
#include "BaseScene.h"
 
// �摜�f�[�^�� string
#define TITLE_IMAGE "TitleTest.png"
#define TITLE_LOGO "Title_Logo.png"
#define START_TEXT "Start.png"
#define CLOUD_IMAGE "scene_01_cloud.png"

class Title : public BaseScene
{
	const int MOVE_SCENE_PAD = PAD_INPUT_3;
	const int MOVE_SCENE_KEY = KEY_INPUT_SPACE;

	bool isMovingScene;

public:
	Title();
	~Title();

	// �t�@�C���ǂݍ���
	void LoadFile();
	// �ǂݍ��񂾃t�@�C���̔j��
	void UnLoadFile();
	// ������
	void Initialize();
	// �X�V
	void Update();
	// �`��
	void Draw();
};