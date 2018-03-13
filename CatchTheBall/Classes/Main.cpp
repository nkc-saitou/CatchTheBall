#include "DxLib.h"
#include "BaseScene.h"
#include "FileManager.h"
#include "ObjectManager.h"
#include "EffectManager.h"
#include "Input.h"
#include "Time.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	#pragma region DX���C�u�����̏����ݒ�
	// DX���C�u�����̕\�����@���E�B���h�E���[�h�ɕύX����B
	ChangeWindowMode(true);

	// DirectX9���g�p����悤�ɂ���B(DirectX11����)
	// Effekseer���g�p����ɂ͕K���ݒ肷��B
	SetUseDirect3DVersion(DX_DIRECT3D_9);

	SetWaitVSyncFlag(FALSE);

	// DX���C�u����������������B
	if (DxLib_Init() == -1) return -1;

	//�`���𗠉�ʂɕύX����B
	SetDrawScreen(DX_SCREEN_BACK);
	#pragma endregion

	#pragma region ������
	//�}�l�[�W���[�̏�����
	FileManager::Instance()->Initialize();

	ObjectManager::Instance()->Initialize();

	EffectManager::Instance()->Initialize();
	EffectManager::Instance()->Load();

	//�N�����Ԃ̏�����
	Time::Initialize();

	// �V�[���̏�����
	Scene* scene = new Scene();
	#pragma endregion

	//���C�����[�v
	while (!ProcessMessage() && !ClearDrawScreen() && !CheckHitKey(KEY_INPUT_ESCAPE))
	{
		#pragma region ���[�v�̏��߂Ɏ��s����
		//���͂̍X�V
		Input::Instance()->InputMemory();
		//���Ԃ̌v��
		Time::Update();
		#pragma endregion

		#pragma region �X�V����
		//�A�N�e�B�u�V�[���̍X�V
		scene->Update();
		// �V�[���̕`��
		scene->Draw();
		//FPS������ɕ\��
		Time::Draw();
		#pragma endregion

		// �X�N���[�������ւ���B
		ScreenFlip();

		#pragma region ���[�v�̍Ō�Ɏ��s����
		//FPS�������Ȃ�Ȃ��悤�ɑ҂�
		Time::Wait();
		#pragma endregion

	}

	#pragma region �}�l�[�W���[�̏I������
	EffectManager::Instance()->Finalize();
	ObjectManager::Instance()->Finalize();
	#pragma endregion

	// DX���C�u�������I������B
	DxLib_End();

	return 0;
}