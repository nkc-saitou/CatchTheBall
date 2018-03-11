#include "Player.h"
#include "FileManager.h"
#include "Input.h"
#include "Time.h"

Player::Player() : Object(0)
{
	GraphHandle(FileManager::Instance()->GetFileHandle("player.png"));
	state = Move;
}
Player::Player(float x, float y, int order) : Object(order)
{
	GraphHandle(FileManager::Instance()->GetFileHandle("player.png"));

	PositionX(x); PositionY(y);
	state = Move;
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
}
//---------------------------------------------------------
//	�v���C���[��ݒ�
//---------------------------------------------------------
void Player::SetPadNo(int no)
{
	padNo = no;
}
//---------------------------------------------------------
//	�ړ�
//---------------------------------------------------------
void Player::MoveAction()
{
	float pointX = PositionX();
	float pointY = PositionY();

	//�ߋ�
	if (Input::Instance()->ButtonDown(XINPUT_BUTTON_B, padNo)) {
		printfDx("B_BUTTON");
		return;
	}

	//�W�����v
	if (Input::Instance()->ButtonDown(XINPUT_BUTTON_A, padNo)) {
		printfDx("A_BUTTON");
	}

	//�ړ�	�E
	if (Input::Instance()->Button(XINPUT_BUTTON_DPAD_RIGHT, padNo)) {
		pointX += 3;
	} else
	//�ړ��@��
	if (Input::Instance()->Button(XINPUT_BUTTON_DPAD_LEFT, padNo)) {
		pointX -= 3;
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