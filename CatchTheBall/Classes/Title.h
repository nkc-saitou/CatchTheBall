#pragma once
 
// �摜�f�[�^�� string
#define TITLE_IMAGE "TitleTest.png"
#define TITLE_TEXT "TitleText.png"
#define PLAYER_IMAGE "player.png"
#define CLOUD_IMAGE "scene_01_cloud.png"

class Title
{
public:
	// ������
	static void Title_Initialize();
	// �X�V
	static void Title_Update();
	// �`��
	static void Title_Draw();
};