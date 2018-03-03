#pragma once

#include "Object.h"

enum PlayerState {
	Wait,
	Move,
	Shot,
	Dead
};

class Player : public Object
{
public:
	Player();
	Player(float x, float y);
	~Player();

	void Update();		//�X�V
	//void Draw();		//�`��

private:
	void MoveAction();	//�ړ�
	void ShotAction();	//�ˌ�
	void DeadAction();	//���S

	PlayerState state;	//���
};