#pragma once

// �摜�f�[�^�� string 
#define BACKGROUND_IMAGE "test2.png"
#define PLAYER_IMAGE "frame.png"
#define BOM_IMAGE "Bom.png"

class Game
{
public:
	// ������
	static void Game_Initialize();

	//�X�V
	static void Game_Update();

	//�`��
	static void Game_Draw();
};

