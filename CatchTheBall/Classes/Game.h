#pragma once
#include "BaseScene.h"

// �摜�f�[�^�� string 
#define BACKGROUND_IMAGE "test2.png"
#define PLAYER_IMAGE "player.png"
#define BOM_IMAGE "Bom.png"

class Game : public BaseScene
{
public:
	Game();
	~Game();

	// �t�@�C���ǂݍ���
	void LoadFile();
	// �ǂݍ��񂾃t�@�C���̔j��
	void UnLoadFile();
	// ������
	void Initialize();
	//�X�V
	void Update();
	//�`��
	void Draw();
};

