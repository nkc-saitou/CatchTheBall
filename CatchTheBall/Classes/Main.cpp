#include "DxLib.h"
#include "BaseScene.h"
#include "Input.h"
#include "Time.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	// DX���C�u�����̕\�����@���E�B���h�E���[�h�ɕύX����B
	ChangeWindowMode(true);

	// DirectX9���g�p����悤�ɂ���B(DirectX11����)
	// Effekseer���g�p����ɂ͕K���ݒ肷��B
	SetUseDirect3DVersion(DX_DIRECT3D_9);

	// DX���C�u����������������B
	if (DxLib_Init() == -1) return -1;

	//�`���𗠉�ʂɕύX����B
	SetDrawScreen(DX_SCREEN_BACK);

	// �V�[���̏�����
	Scene* scene = new Scene();

	while (!ProcessMessage() && !ClearDrawScreen() && !CheckHitKey(KEY_INPUT_ESCAPE))
	{

		//---------------------------------------------
		// �V�[���̍X�V
		scene->Update();
		// �V�[���̕`��
		scene->Draw();
		//---------------------------------------------

		//���͏��̍X�V
		Input::Instance()->InputMemory();

		//FPS������ɕ\��
		Time::Draw();

		// �X�N���[�������ւ���B
		ScreenFlip();

		//-------------------------
		//FPS���肳������
		Time::Update();
		Time::Wait();
	}

	// DX���C�u�������I������B
	DxLib_End();

	return 0;
}