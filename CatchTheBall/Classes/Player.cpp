#include "Player.h"
#include "FileManager.h"
#include "Input.h"

Player::Player() : Object(0)
{
	//GraphHandle(FileManager::Instance()->GetFileHandle("Player_01_Right.png"));
	state = Wait;
}
Player::Player(float x, float y, int order) : Object(order)
{
	//GraphHandle(FileManager::Instance()->GetFileHandle("Player_01_Right.png"));
	PositionX(x); PositionY(y);
	state = Wait;
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
//	�`��
//---------------------------------------------------------
//void Player::Draw()
//{
//	
//}
//---------------------------------------------------------
//	�ړ�
//---------------------------------------------------------
void Player::MoveAction()
{
	float pointX = PositionX();
	float pointY = PositionY();

	//�ߋ�
	if (Input::Instance()->ButtonDown(PAD_INPUT_B, Pad_1)) {

		return;
	}

	//�W�����v
	if (Input::Instance()->ButtonDown(PAD_INPUT_A, Pad_1)) {

	}

	//�ړ�	��
	if (Input::Instance()->ButtonDown(PAD_INPUT_7, Pad_1)) {

	} else
	//�ړ��@�E
	if (Input::Instance()->ButtonDown(PAD_INPUT_8, Pad_1)) {

	}
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