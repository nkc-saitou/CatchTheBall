#pragma once

//�G�t�F�N�g�Đ��p�̃n���h��
typedef int EffectHandle;

#include <iostream>
#include <map>
#include "EffekseerForDXLib.h"
#include "Singleton.h"
#include "FileManager.h"
#include "EffectType.h"
#include "EffectObject.h"

using namespace std;

//
// �G�t�F�N�g���Ǘ�����N���X
//
class EffectManager final : public Singleton<EffectManager>
{
	EffectHandle loadedEffect[static_cast<int>(EffectType::PlayerJump)];

	bool isLoadEffect = false;

	
	//�G�t�F�N�g�̏�����
	void Initialize();

	//�^�C�v����G�t�F�N�g�̃t�@�C������Ԃ�
	string GetEffectName(EffectType type);

public:

	EffectManager();
	~EffectManager ();

	// �G�t�F�N�g�̃��[�h
	void Load ();

	// �G�t�F�N�g�̍X�V
	void Update ();

	// �G�t�F�N�g�̍Đ�
	static EffectObject* CreateEffect(EffectType effectType);
	static EffectObject* CreateEffect(EffectType effectType, bool autoPlay);
};

