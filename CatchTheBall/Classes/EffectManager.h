#pragma once

//�G�t�F�N�g�Đ��p�̃n���h��
typedef int EffectHandle;

#include <iostream>
#include "EffekseerForDXLib.h"
#include "Singleton.h"
#include "FileManager.h"
#include "EffectType.h"
#include "EffectObject.h"
#include "Camera.h"

using namespace std;

//
// �G�t�F�N�g���Ǘ�����N���X
//
class EffectManager final : public Singleton<EffectManager>
{
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;

	EffekseerRenderer::Renderer* renderer;

	EffectHandle loadedEffect[static_cast<int>(EffectType::MuzzleFlash) + 1];

	bool isLoadEffect = false;

	//�^�C�v����G�t�F�N�g�̃t�@�C������Ԃ�
	string GetEffectName(EffectType type);


public:

	EffectManager();
	~EffectManager ();

	//�G�t�F�N�g�̏�����
	void Initialize();
	//�G�t�F�N�g�̏I��
	void Finalize();

	// �G�t�F�N�g�̃��[�h
	void Load ();

	// �G�t�F�N�g�̍X�V
	void Update ();

	// �G�t�F�N�g�̍Đ�
	static void CreateEffect(EffectType effectType, float x, float y);
	static EffectObject* CreateEffect(EffectType effectType, float x, float y, bool autoDestroy = false);
};

