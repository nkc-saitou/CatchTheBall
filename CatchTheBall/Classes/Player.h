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
	//void Draw();		//�`��

	void SetPadNo(int);	//�v���C���[��ݒ�

private:
	void MoveAction();	//�ړ�
	void ShotAction();	//�ˌ�
	void DeadAction();	//���S

	PlayerState state;	//���
	int padNo;			//����p�b�h

	bool isTouchBall;	//�ԉ΋ʂɐG��Ă��邩
	float ballPower;	//�ێ������ԉ΋ʂɉ�����Ă����
};