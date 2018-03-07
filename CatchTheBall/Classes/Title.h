#pragma once
#include "BaseScene.h"
 
// �摜�f�[�^�� string
#define TITLE_IMAGE "TitleTest.png"
#define TITLE_TEXT "TitleText.png"
#define PLAYER_IMAGE "player.png"
#define CLOUD_IMAGE "scene_01_cloud.png"

class Title : public BaseScene
{
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