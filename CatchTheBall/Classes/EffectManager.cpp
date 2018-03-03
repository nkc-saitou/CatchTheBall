#include "EffectManager.h"

EffectManager::EffectManager() {}

EffectManager::~EffectManager() {

	// Effekseer���I������B
	Effkseer_End();
}

void EffectManager::Initialize() {

	// Effekseer������������B
	// �����ɂ͉�ʂɕ\������ő�p�[�e�B�N������ݒ肷��B
	if (Effkseer_Init(2000) == -1) {
		cout << "�x�� : Effekseer�̏������Ɏ��s���܂���" << endl;
		return;
	}

	// �t���X�N���[���E�C���h�E�̐؂�ւ��Ń��\�[�X��������̂�h���B
	// Effekseer���g�p����ꍇ�͕K���ݒ肷��B
	SetChangeScreenModeGraphicsSystemResetFlag(FALSE);

	// DX���C�u�����̃f�o�C�X���X�g�������̃R�[���o�b�N��ݒ肷��B
	// �E�C���h�E�ƃt���X�N���[���̐؂�ւ�����������ꍇ�͕K�����s����B
	// �������ADirectX11���g�p����ꍇ�͎��s����K�v�͂Ȃ��B
	Effekseer_SetGraphicsDeviceLostCallbackFunctions();

	// Effekseer��2D�`��̐ݒ������B
	Effekseer_Set2DSetting(640, 480);

	// Z�o�b�t�@��L���ɂ���B
	// Effekseer���g�p����ꍇ�A2D�Q�[���ł�Z�o�b�t�@���g�p����B
	SetUseZBuffer3D(TRUE);

	// Z�o�b�t�@�ւ̏������݂�L���ɂ���B
	// Effekseer���g�p����ꍇ�A2D�Q�[���ł�Z�o�b�t�@���g�p����B
	SetWriteZBuffer3D(TRUE);

	cout << "Effect initialized." << endl;
}

string EffectManager::GetEffectName(EffectType type) {
	switch (type) {
		case EffectType::ExplosionFireworkClear:
		case EffectType::ExplosionFireworkGameOver:
		case EffectType::FireworkTrailLv1:
		case EffectType::FireworkTrailLv2:
		case EffectType::FireworkTrailLv3:
		case EffectType::MazzleFlash:
		case EffectType::PlayerActive:
		case EffectType::PlayerDeath:
		case EffectType::PlayerMove:
		case EffectType::PlayerJump:
			return "laser.efk";
		default:
			return "";
	}
}

void EffectManager::Load() {

	// �G�t�F�N�g��ǂݍ��ށB
	for (auto i = 0; i < sizeof(loadedEffect) / sizeof(EffectHandle); i++) {
		loadedEffect[i] = FileManager::Instance()->GetFileHandle(GetEffectName(static_cast<EffectType>(i)));
	}

	isLoadEffect = true;
	cout << "Effect loaded." << endl;
}


void EffectManager::Update() {

	// Effekseer�ɂ��Đ����̃G�t�F�N�g���X�V����B
	UpdateEffekseer2D();

	// Effekseer�ɂ��Đ����̃G�t�F�N�g��`�悷��B
	DrawEffekseer2D();

}

EffectObject* EffectManager::CreateEffect(EffectType effectType) {
	return CreateEffect(effectType, true);
}

EffectObject* EffectManager::CreateEffect(EffectType effectType, bool autoPlay){

	if (Instance()->isLoadEffect == false) return NULL;

	EffectObject *effectObject = new EffectObject(Instance()->loadedEffect[static_cast<int>(effectType)]);

	if (autoPlay) effectObject->PlayEffect();

	return effectObject;
}

