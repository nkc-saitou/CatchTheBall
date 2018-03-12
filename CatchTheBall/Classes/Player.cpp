#include "Player.h"
#include "FileManager.h"
#include "Input.h"
#include "Time.h"

Player::Player() : Object(0)
{
	GraphHandle(FileManager::Instance()->GetFileHandle("player.png"));
	state = Wait;
}
Player::Player(float x, float y, int order) : Object(order)
{
	GraphHandle(FileManager::Instance()->GetFileHandle("player.png"));

	PositionX(x); PositionY(y);
	state = Wait;
	isTouchBall = false;
}
Player::~Player()
{

}
//---------------------------------------------------------
//	�X�V
//---------------------------------------------------------
void Player::Update()
{
	//�s��
	switch (state) {
	case Wait: break;					// �ҋ@
	case Move: MoveAction(); break;		// �ړ�
	case Shot: ShotAction(); break;		// �ˌ�
	case Dead: DeadAction(); break;		// ���S
	}

	//�d��
	Fall_y();
}
//---------------------------------------------------------
//	�v���C���[��ݒ�
//---------------------------------------------------------
void Player::SetPadNo(int no)
{
	padNo = no;
	state = Move;
}
//---------------------------------------------------------
//	�ړ�
//---------------------------------------------------------
void Player::MoveAction()
{
	const float MOVE_SPEED = 100;
	float pointX = PositionX(), pointY = PositionY();

	//�ߋ�
	if (isTouchBall && Input::Instance()->ButtonDown(XINPUT_BUTTON_B, padNo)) {
		//printfDx("B_BUTTON");
		return;
	}

	//�W�����v
	if (Input::Instance()->ButtonDown(XINPUT_BUTTON_A, padNo)) {
		//printfDx("A_BUTTON");
	}

	//�ړ�	�E
	if (Input::Instance()->Button(XINPUT_BUTTON_DPAD_RIGHT, padNo)) {
		pointX += MOVE_SPEED * Time::GetDeltaTime();
	} else
	//�ړ��@��
	if (Input::Instance()->Button(XINPUT_BUTTON_DPAD_LEFT, padNo)) {
		pointX -= MOVE_SPEED * Time::GetDeltaTime();
	}

	//pointX += 0.2;
	PositionX(pointX); PositionY(pointY);
}
//---------------------------------------------------------
//	�ˌ�
//---------------------------------------------------------
void Player::ShotAction()
{

}
//---------------------------------------------------------
//	���S
//---------------------------------------------------------
void Player::DeadAction()
{

}