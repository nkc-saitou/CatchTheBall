#pragma once

#include <iostream>
#include "EffekseerForDXLib.h"
#include "Singleton.h"

using namespace std;

//�G�t�F�N�g�Đ��p�̃n���h��
typedef int EffectHandle;

enum class EffectType {
	ExplosionFireworkClear,		//�ԉ΂̔���(�N���A��)
	ExplosionFireworkGameOver,	//�ԉ΂̔���(�Q�[���I�[�o�[��)
	
	FireworkTrailLv1,			//�ԉ΂̑��x�m�F�pLv1
	FireworkTrailLv2,			//�ԉ΂̑��x�m�F�pLv2
	FireworkTrailLv3,			//�ԉ΂̑��x�m�F�pLv3

	MazzleFlash,				//���������̉Ή�
	PlayerActive,				//�v���C���[�����ڂ����Ƃ�
	PlayerDeath,				//�v���C���[�����񂾂Ƃ�
	PlayerMove,					//�v���C���[���������Ƃ�
	PlayerJump,					//�v���C���[���W�����v�����Ƃ�

};

//
// �G�t�F�N�g���Ǘ�����N���X
//
class EffectManager final : public Singleton<EffectManager>
{
	const char (*effectName)[];
	map

	bool isLoadEffect = false;

	EffectManager ();



public:

	~EffectManager ();

	// �G�t�F�N�g�̃��[�h
	void load ();

	// �G�t�F�N�g�̍X�V
	void update ();

	// �G�t�F�N�g�̍Đ�
	EffectHandle playEffect (string name);
};

