#include "Player.h"
#include "FileManager.h"
#include "Input.h"
#include "Time.h"

Player::Player() : Object(0)
{
	GraphHandle(FileManager::Instance()->GetFileHandle("Player_A_0"));
	state = Wait;
}
Player::Player(float x, float y, int order) : Object(order)
{
	GraphHandle(FileManager::Instance()->GetFileHandle("Player_A_0"));

	PositionX(x); PositionY(y);
	state = Wait;
	isTouchBall = false; isGround = true;

}
Player::~Player()
{
	printfDx("�f�X");
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
	ObjGravity();
}
//---------------------------------------------------------
//	�v���C���[��ݒ�
//---------------------------------------------------------
void Player::SetPadNo(int no)
{
	padNo = no;
	state = Move;

	Input::Instance()->PadStartVibration(no, 1000, 500);
}
//---------------------------------------------------------
//	�ړ�
//---------------------------------------------------------
void Player::MoveAction()
{
	const float MOVE_SPEED = 200;
	float pointX = PositionX();

	//�ߋ�
	if (isTouchBall && Input::Instance()->ButtonDown(XINPUT_BUTTON_B, padNo)) {
		//printfDx("B_BUTTON");
		return;
	}
	//�n�ʂɐڂ��Ă��Ȃ��Ȃ�
	if (!isGround) return;

	//�W�����v
	if (Input::Instance()->Button(XINPUT_BUTTON_A, padNo)) {
		Jump();
	}

	//�ړ�	�E
	if (Input::Instance()->AngleInputX(padNo) > 0.8f) {
		pointX += MOVE_SPEED * Time::GetDeltaTime();
	} else
	//�ړ��@��
	if (Input::Instance()->AngleInputX(padNo) < -0.8f) {
		pointX -= MOVE_SPEED * Time::GetDeltaTime();
	}

	PositionX(pointX);
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
//---------------------------------------------------------
//	�W�����v
//---------------------------------------------------------
void Player::Jump()
{
	if (PositionY() <= 240) {
		PositionY(PositionY() + Fall_y() * Time::GetDeltaTime());
	}
	else if (PositionY() >= 240) {
		PositionY(PositionY() - 200 * Time::GetDeltaTime());
	}
}