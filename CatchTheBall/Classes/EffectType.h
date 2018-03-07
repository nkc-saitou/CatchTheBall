#pragma once

enum class EffectType {
	
	ExplosionFireworkClear = 0,		//�ԉ΂̔���(�N���A��)
	ExplosionFireworkGameOver,		//�ԉ΂̔���(�Q�[���I�[�o�[��)

	FireworkTrailLv1,				//�ԉ΂̑��x�m�F�pLv1
	FireworkTrailLv2,				//�ԉ΂̑��x�m�F�pLv2
	FireworkTrailLv3,				//�ԉ΂̑��x�m�F�pLv3
	FireworkTrailClear,				//�N���A���̉ԉ΂̃g���C��

	Player1Active,					//�v���C���[1�����ڂ����Ƃ�
	Player2Active,					//�v���C���[2�����ڂ����Ƃ�
	Player3Active,					//�v���C���[3�����ڂ����Ƃ�
	Player4Active,					//�v���C���[4�����ڂ����Ƃ�

	PlayerDeath,					//�v���C���[�����񂾂Ƃ�
	PlayerMove,						//�v���C���[���������Ƃ�
	PlayerJump,						//�v���C���[���W�����v�����Ƃ�
	MuzzleFlash,					//���������̉Ή�

};