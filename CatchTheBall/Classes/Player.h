#pragma once

#include "Object.h"
#include "Gravity.h"

enum PlayerState {
	Wait,
	Move,
	Shot,
	Dead
};

class Player : public Object, public Gravity
{
public:
	Player();
	Player(float x, float y, int order = 0);
	~Player();

	void Update();		//�X�V
	void SetPadNo(int);	//�v���C���[��ݒ�

private:
	PlayerState state;	//���
	int padNo;			//����p�b�h

	bool isTouchBall;	//�ԉ΋ʂɐG��Ă��邩
	bool isGround;		//�n�ʂɐڂ��Ă��邩
	float ballPower;	//�ێ������ԉ΋ʂɉ�����Ă����

	void MoveAction();	//�ړ�
	void ShotAction();	//�ˌ�
	void DeadAction();	//���S
	void Jump();		//�W�����v
};