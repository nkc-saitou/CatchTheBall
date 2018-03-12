#include "EffectManager.h"

EffectManager::EffectManager() {}

EffectManager::~EffectManager() {}

void EffectManager::Initialize() {

	// Effekseer������������B
	// �����ɂ͉�ʂɕ\������ő�p�[�e�B�N������ݒ肷��B
	if (Effkseer_Init(10000) == -1) {
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

	//�����_���[���擾
	renderer = GetEffekseer2DRenderer();

	cout << "Effect initialized." << endl;
}

void EffectManager::Finalize() {

	// �G�t�F�N�g���폜����B(Effekseer�I�����ɔj�������̂ō폜���Ȃ��Ă�����)
	for (auto i = 0; i < sizeof(loadedEffect) / sizeof(EffectHandle); i++) {
		DeleteEffekseerEffect(loadedEffect[i]);
	}

	// Effekseer���I������B
	Effkseer_End();

	cout << "Effect finalized." << endl;
}

string EffectManager::GetEffectName(EffectType type) {
	switch (type) {
		case EffectType::ExplosionFireworkClear:
			return "ClearFirework.efk";
		case EffectType::ExplosionFireworkGameOver:
			return "GameOverFirework.efk";
		case EffectType::FireworkTrailLv1:
			return "Trail1.efk";
		case EffectType::FireworkTrailLv2:
			return "Trail2.efk";
		case EffectType::FireworkTrailLv3:
			return "Trail3.efk";
		case EffectType::FireworkTrailClear:
			return "TrailClear.efk";
		case EffectType::Player1Active:
			return "Player1Active.efk";
		case EffectType::Player2Active:
			return "Player2Active.efk";
		case EffectType::Player3Active:
			return "Player3Active.efk";
		case EffectType::Player4Active:
			return "Player4Active.efk";
		case EffectType::PlayerDeath:
			return "PlayerDeath.efk";
		case EffectType::PlayerMove:
			return "PlayerMove.efk";
		case EffectType::PlayerJump:
			return "PlayerJump.efk";
		case EffectType::MuzzleFlash:
			return "MuzzleFlash.efk";
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

	//�J�����ʒu�̐ݒ�
	auto mainCam = Camera::MainCamera;
	if (mainCam != nullptr) {
		float x = mainCam->PositionX();
		float y = mainCam->PositionY();

		//Effekseer�̃����_���[�ɃZ�b�g
		Effekseer::Matrix44* m = new Effekseer::Matrix44();
		m->Translation(-SCREEN_WIDTH / 2 - x, +SCREEN_HEIGHT / 2 + y, 10);
		renderer->SetCameraMatrix(*m);
		delete m;
	}

	// Effekseer�ɂ��Đ����̃G�t�F�N�g���X�V����B
	UpdateEffekseer2D();

	// Effekseer�ɂ��Đ����̃G�t�F�N�g��`�悷��B
	DrawEffekseer2D();

}

void EffectManager::CreateEffect(EffectType effectType, float x, float y){
	CreateEffect(effectType, x, y, true);
}
EffectObject* EffectManager::CreateEffect(EffectType effectType, float x, float y, bool autoDestroy){

	if (Instance()->isLoadEffect == false) return nullptr;

	EffectObject *effectObject = new EffectObject(Instance()->loadedEffect[static_cast<int>(effectType)]);

	effectObject->PositionX(x);
	effectObject->PositionY(y);
	effectObject->PlayEffect();
	
	effectObject->autoDestroy = autoDestroy;

	return effectObject;
}

