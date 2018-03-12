#include "DxLib.h"
#include "BaseScene.h"
#include "ObjectManager.h"
#include "EffectManager.h"
#include "Input.h"
#include "Time.h"
#include "FireworkObject.h"
#include "GoalObject.h"
#include "CollisionManager.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
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

	// ���ł������̂ŉ摜��ǂݍ��ށB
	int grBackgroundHandle = LoadGraph(_T("Texture/Background.png"));
	int grFrontHandle = LoadGraph(_T("Texture/Front.png"));

	// ���Ԃ�����������(����I�ɃG�t�F�N�g���Đ����邽��)
	int time = 0;

	// �t���X�N���[���؂�ւ��p�t���O��ݒ肷��B(F1�AF2�ŃE�C���h�E�A�t���X�N���[����؂�ւ����悤�ɂ���B)
	bool isFullScreen = false;

	//�I�u�W�F�N�g�}�l�[�W���[������������
	ObjectManager::Instance()->Initialize();

	//�G�t�F�N�g�}�l�[�W���[������������
	EffectManager::Instance()->Initialize();
	EffectManager::Instance()->Load();

	// �V�[���̏�����
	Scene* scene = new Scene();

	//�S�[���𐶐�
	new GoalObject(200, 200);

	ScreenFlip();
	WaitKey();

	//�N�����Ԃ̏�����
	Time::Initialize();

	while (!ProcessMessage() && !ClearDrawScreen() && !CheckHitKey(KEY_INPUT_ESCAPE))
	{
		// ����I�ɃG�t�F�N�g���Đ�����
		if (time % 60 == 0)
		{
			//obj->StopEffect();
			// �G�t�F�N�g�̈ʒu�����Z�b�g����B
			//obj->PositionX(100.0f);
		}

		if (Input::Instance()->ButtonDown(KEY_INPUT_G)) {
			//�ԉ΂̐���
			auto g = new FireworkObject();
			g->SetPosition(100, 100);
			g->SetForce(300, 1 / 1.4142, -1 / 1.4142);
			//g->SetForce(300, 1, 0);
		}

		//obj->PositionX(obj->PositionX() + 2);

		//---------------------------------------------
		// �V�[���̍X�V
		scene->Update();

		//�����蔻��
		CollisionManager::Instance()->HitCollision();

		// �V�[���̕`��
		scene->Draw();
		//---------------------------------------------

		// ���ł������̂ŉ摜��`�悷��B
		// �������ĕ`�悵����łȂ��ƁAEffekseer�͕`��ł��Ȃ��B
		DrawGraph(0, 0, grBackgroundHandle, TRUE);

		//���͏��̍X�V
		Input::Instance()->InputMemory();

		ObjectManager::Instance()->Update();
		ObjectManager::Instance()->Draw();

		EffectManager::Instance()->Update();

		// �G�t�F�N�g�̏�ɂ��摜��`��ł���B
		DrawGraph(0, 0, grFrontHandle, TRUE);
	
		Time::Update();
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
		Time::Wait();
	}


	EffectManager::Instance()->Finalize();
	ObjectManager::Instance()->Finalize();

	// DX���C�u�������I������B
	DxLib_End();

	return 0;
}