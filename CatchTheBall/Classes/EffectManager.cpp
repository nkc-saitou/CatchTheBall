#include "EffectManager.h"



EffectManager::EffectManager () {

	// Effekseer������������B
	// �����ɂ͉�ʂɕ\������ő�p�[�e�B�N������ݒ肷��B
	if (Effkseer_Init (2000) == -1) {
		cout << "�x�� : Effekseer�̏������Ɏ��s���܂���" << endl;
		return;
	}

	// �t���X�N���[���E�C���h�E�̐؂�ւ��Ń��\�[�X��������̂�h���B
	// Effekseer���g�p����ꍇ�͕K���ݒ肷��B
	SetChangeScreenModeGraphicsSystemResetFlag (FALSE);

	// DX���C�u�����̃f�o�C�X���X�g�������̃R�[���o�b�N��ݒ肷��B
	// �E�C���h�E�ƃt���X�N���[���̐؂�ւ�����������ꍇ�͕K�����s����B
	// �������ADirectX11���g�p����ꍇ�͎��s����K�v�͂Ȃ��B
	Effekseer_SetGraphicsDeviceLostCallbackFunctions ();

	// Effekseer��2D�`��̐ݒ������B
	Effekseer_Set2DSetting (640, 480);
}

EffectManager::~EffectManager () {

	// Effekseer���I������B
	Effkseer_End ();
}

void EffectManager::load() {

	// �G�t�F�N�g��ǂݍ��ށB
	EffectHandle effectHandle = LoadEffekseerEffect ("laser.efk");

	cout << "Effect loaded." << endl;
}


void EffectManager::update () {

	// �Đ����̃G�t�F�N�g���ړ�����B
	SetPosPlayingEffekseer2DEffect (playingEffectHandle, position_x, position_y, 0);
	position_x += 2.0f;

	// Effekseer�ɂ��Đ����̃G�t�F�N�g���X�V����B
	UpdateEffekseer2D ();

	// Effekseer�ɂ��Đ����̃G�t�F�N�g��`�悷��B
	DrawEffekseer2D ();

}

EffectHandle EffectManager::playEffect (string name) {

}