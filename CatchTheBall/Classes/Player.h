#pragma once

#include "Object.h"
#include "Gravity.h"
#include "Collision.h"

#pragma region �萔

const int RIGHT = 0;	// �E
const int LEFT = 1;	// ��

const float MOVE_SPEED_MAX = 300;	// �ō��ړ����x
const float ADD_ACCEL = 450;		// �����x

#pragma endregion

enum PlayerState {
	Wait,
	Move,
	Shot,
	Dead
};

struct P_InputState {
	P_InputState();
	bool ActionKey;
	bool ActionKeyDown;
	bool JumpKey;
	bool JumpKeyDown;

	bool Right;
	bool RightDown;
	bool Left;
	bool LeftDown;

	float AngleX;
	float AngleY;
};

class Player : public Object, Gravity
{
public:
	static const string GetTagName() { return "Player"; }

	Player();
	Player(float x, float y, int order = 0);
	~Player();

	void Update();		//�X�V
	void SetPadNo(int);	//�v���C���[��ݒ�

private:
	PlayerState state;	//���
	int playerNo;		//�v���C���[�ԍ�
	int padNo;			//����p�b�h
	int bodyHandle[2];	//�{�̉摜�n���h��
	P_InputState memoryInput;//���͏��̋L��

	bool isTouchBall;	//�ԉ΋ʂɐG��Ă��邩
	bool isGround;		//�n�ʂɐڂ��Ă��邩
	float moveSpeed;	//�ړ����x
	float ballPower;	//�ێ������ԉ΋ʂɉ�����Ă����

	Collision *collider;	//�����蔻��

	void MoveAction();	//�ړ�
	void ShotAction();	//�ˌ�
	void DeadAction();	//���S
	void Jump();		//�W�����v
	P_InputState PlayerInput();	//�v���C���[����̓���

	void OnHit(Collision *other);
};