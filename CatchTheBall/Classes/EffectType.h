#pragma once

enum class EffectType {
	ExplosionFireworkClear = 0,		//�ԉ΂̔���(�N���A��)
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