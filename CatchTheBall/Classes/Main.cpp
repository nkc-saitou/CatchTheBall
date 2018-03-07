#include "DxLib.h"
#include "BaseScene.h"
#include "EffectManager.h"
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

	// ���ł������̂ŉ摜��ǂݍ��ށB
	int grBackgroundHandle = LoadGraph(_T("Texture/Background.png"));
	int grFrontHandle = LoadGraph(_T("Texture/Front.png"));

	// ���Ԃ�����������(����I�ɃG�t�F�N�g���Đ����邽��)
	int time = 0;

	// �t���X�N���[���؂�ւ��p�t���O��ݒ肷��B(F1�AF2�ŃE�C���h�E�A�t���X�N���[����؂�ւ����悤�ɂ���B)
	bool isFullScreen = false;

	//�G�t�F�N�g�}�l�[�W���[������������
	EffectManager::Instance()->Initialize();
	EffectManager::Instance()->Load();

	// �Đ����̃G�t�F�N�g������������B
	EffectObject *obj = EffectManager::CreateEffect(EffectType::ExplosionFireworkClear, false);
	obj->PositionX(100.0f);
	obj->PositionY(250.0f);
	obj->Scale(25.0f);

	// �V�[���̏�����
	Scene* scene = new Scene();

	ScreenFlip();
	WaitKey();

	while (!ProcessMessage() && !ClearDrawScreen() && !CheckHitKey(KEY_INPUT_ESCAPE))
	{
		// ����I�ɃG�t�F�N�g���Đ�����
		if (time % 60 == 0)
		{
			obj->StopEffect();
			obj->PlayEffect();
			// �G�t�F�N�g�̈ʒu�����Z�b�g����B
			obj->PositionX(100.0f);
		}

		obj->PositionX(obj->PositionX() + 2);

		obj->Update();

		//---------------------------------------------
		// �V�[���̍X�V
		scene->Update();
		// �V�[���̕`��
		scene->Draw();
		//---------------------------------------------

		// ���ł������̂ŉ摜��`�悷��B
		// �������ĕ`�悵����łȂ��ƁAEffekseer�͕`��ł��Ȃ��B
		DrawGraph(0, 0, grBackgroundHandle, TRUE);

		//���͏��̍X�V
		Input::Instance()->InputMemory();

		EffectManager::Instance()->Update();

		// �G�t�F�N�g�̏�ɂ��摜��`��ł���B
		DrawGraph(0, 0, grFrontHandle, TRUE);

		//FPS������ɕ\��
		Time::Draw();

		// �X�N���[�������ւ���B
		ScreenFlip();

		// ���Ԃ��o�߂�����B
		time++;


		// �t���X�N���[���̐؂�ւ����s���B
		if (CheckHitKey(KEY_INPUT_F1) && !isFullScreen)
		{
			ChangeWindowMode(FALSE);
			SetDrawScreen(DX_SCREEN_BACK);
			isFullScreen = true;
		}
		if (CheckHitKey(KEY_INPUT_F2) && isFullScreen)
		{
			ChangeWindowMode(TRUE);
			SetDrawScreen(DX_SCREEN_BACK);
			isFullScreen = false;
		}

		//-------------------------
		//FPS���肳������
		Time::Update();
		Time::Wait();
	}

	EffectManager::Instance()->Finalize();

	// DX���C�u�������I������B
	DxLib_End();

	return 0;
}