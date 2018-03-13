#include "Player.h"
#include "FileManager.h"
#include "Input.h"
#include "Time.h"
#include "EntryData.h"

#pragma region P_Input

P_InputState::P_InputState()
{
	ActionKey	= ActionKeyDown = false;
	JumpKey		= JumpKeyDown   = false;
	Right		= RightDown		= false;
	Left		= LeftDown		= false;
	AngleX		= AngleY        = 0;
}

#pragma endregion

Player::Player() : Object(0)
{
	bodyHandle[RIGHT] = FileManager::Instance()->GetFileHandle("Player_A_0");
	bodyHandle[LEFT] = FileManager::Instance()->GetFileHandle("Player_A_1");
	GraphHandle(bodyHandle[RIGHT]);

	state = Wait;
	isTouchBall = false; isGround = true;
	moveSpeed = 0;
	memoryInput = P_InputState();

	collider = new Collision(GraphWidth() / 2, GraphHeight() / 2, GraphWidth(), GraphHeight(), Square, this, [this](Collision* other) { OnHit(other); });
	tag = GetTagName();
}
Player::Player(float x, float y, int order) : Object(order)
{
	bodyHandle[RIGHT] = FileManager::Instance()->GetFileHandle("Player_A_0");
	bodyHandle[LEFT]  = FileManager::Instance()->GetFileHandle("Player_A_1");
	GraphHandle(bodyHandle[RIGHT]);

	PositionX(x); PositionY(y);
	state = Wait;
	isTouchBall = false; isGround = false;
	moveSpeed = 0;
	memoryInput = P_InputState();

	collider = new Collision(GraphWidth() / 2, GraphHeight() / 2, GraphWidth(), GraphHeight(), Square, this, [this](Collision* other) { OnHit(other); });
	tag = GetTagName();
}
Player::~Player() 
{
	delete collider;
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
	if (!isGround) {
		float nextY = PositionY();
		ObjGravity();
		nextY += Fall_y();
		PositionY(nextY);
	}
}
//---------------------------------------------------------
//	�v���C���[��ݒ�
//---------------------------------------------------------
void Player::SetPadNo(int no)
{
	const char* PLAYER_1_IMAGE[2] = {
		"Player_A_0",
		"Player_A_1"
	};
	const char* PLAYER_2_IMAGE[2] = {
		"Player_B_0",
		"Player_B_1"
	};
	const char* PLAYER_3_IMAGE[2] = {
		"Player_C_0",
		"Player_C_1"
	};
	const char* PLAYER_4_IMAGE[2] = {
		"Player_D_0",
		"Player_D_1"
	};

	playerNo = no;
	//padNo = EntryData::GetController(playerNo);
	padNo = no;

	/*
	//�摜��ύX
	switch(playerNo) {
	case 0: 
		bodyHandle[RIGHT] = FileManager::Instance()->GetFileHandle(PLAYER_1_IMAGE[RIGHT]); 
		bodyHandle[LEFT] = FileManager::Instance()->GetFileHandle(PLAYER_1_IMAGE[LEFT]);
		break;
	case 1: 
		bodyHandle[RIGHT] = FileManager::Instance()->GetFileHandle(PLAYER_2_IMAGE[RIGHT]);
		bodyHandle[LEFT] = FileManager::Instance()->GetFileHandle(PLAYER_2_IMAGE[LEFT]);
		break;
	case 2:
		bodyHandle[RIGHT] = FileManager::Instance()->GetFileHandle(PLAYER_3_IMAGE[RIGHT]);
		bodyHandle[LEFT] = FileManager::Instance()->GetFileHandle(PLAYER_3_IMAGE[LEFT]);
		break;
	case 3:    
		bodyHandle[RIGHT] = FileManager::Instance()->GetFileHandle(PLAYER_4_IMAGE[RIGHT]);
		bodyHandle[LEFT] = FileManager::Instance()->GetFileHandle(PLAYER_4_IMAGE[LEFT]);
		break;
	}
	GraphHandle(bodyHandle[RIGHT]);
	*/

	state = Move;
	Input::Instance()->PadStartVibration(padNo, 1000, 500);
}
//---------------------------------------------------------
//	�ړ�
//---------------------------------------------------------
void Player::MoveAction()
{
	// �ʒu
	float nextX = PositionX();
	// ����
	P_InputState input = PlayerInput();

	// �ߋ�
	if (input.ActionKeyDown) {
		
		return;
	}

	// �W�����v
	if (isGround && input.JumpKeyDown) {
		Jump();
	}

	// �ړ�
	if (isGround && input.Right) 
	{
		if (input.RightDown) GraphHandle(bodyHandle[RIGHT]);
		moveSpeed += ADD_ACCEL * Time::GetDeltaTime();
	} else
	if (isGround && input.Left) 
	{
		if (input.LeftDown) GraphHandle(bodyHandle[LEFT]);
		moveSpeed -= ADD_ACCEL * Time::GetDeltaTime();
	} 
	else	// ���͂��Ȃ������ꍇ�A����
	{
		if (moveSpeed > 0) 
		{
			moveSpeed -= ADD_ACCEL * Time::GetDeltaTime();
			if (moveSpeed < 0) moveSpeed = 0;
		} else 
		if (moveSpeed < 0)
		{
			moveSpeed += ADD_ACCEL * Time::GetDeltaTime();
			if (moveSpeed > 0) moveSpeed = 0;
		}
	}

	// �ړ����x�̐���
	if (moveSpeed > 0) moveSpeed = (moveSpeed > MOVE_SPEED_MAX) ? MOVE_SPEED_MAX : moveSpeed;
	else if (moveSpeed < 0) moveSpeed = (moveSpeed < -MOVE_SPEED_MAX) ? -MOVE_SPEED_MAX : moveSpeed;
	
	nextX += moveSpeed * Time::GetDeltaTime();
	PositionX(nextX);
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
	/*if (PositionY() <= 240) {
		PositionY(PositionY() + Fall_y() * Time::GetDeltaTime());
	}
	else if (PositionY() >= 240) {
		PositionY(PositionY() - 200 * Time::GetDeltaTime());
	}*/
}
//---------------------------------------------------------
//	�v���C���[����̓���
//---------------------------------------------------------
P_InputState Player::PlayerInput()
{
	P_InputState input;

	// �R���g���[���[
	if (padNo != 0)	{
		const float RIGHT_PUT_ANGLE = 0.8f;		// ���͔��f
		const float LEFT_PUT_ANGLE = -0.8f;		// ���͔��f

		input.ActionKey = Input::Instance()->Button(XINPUT_BUTTON_B, padNo);
		input.ActionKeyDown = Input::Instance()->ButtonDown(XINPUT_BUTTON_B, padNo);
		input.JumpKey = Input::Instance()->Button(XINPUT_BUTTON_A, padNo);
		input.JumpKeyDown = Input::Instance()->ButtonDown(XINPUT_BUTTON_A, padNo);

		input.AngleX = Input::Instance()->AngleInputX(padNo);
		input.AngleY = Input::Instance()->AngleInputY(padNo);

		(input.AngleX > RIGHT_PUT_ANGLE) ? input.Right = true : input.Right = false;
		(input.AngleX < LEFT_PUT_ANGLE) ? input.Left = true : input.Left = false;
		(!memoryInput.Right && input.Right) ? input.RightDown = true : input.RightDown = false;
		(!memoryInput.Left && input.Left) ? input.LeftDown = true : input.LeftDown = false;
	} 
	// �L�[�{�[�h
	else {
		input.ActionKey = Input::Instance()->Button(MOUSE_INPUT_LEFT);
		input.ActionKeyDown = Input::Instance()->ButtonDown(MOUSE_INPUT_LEFT);
		input.JumpKey = Input::Instance()->Button(KEY_INPUT_SPACE);
		input.JumpKeyDown = Input::Instance()->ButtonDown(KEY_INPUT_SPACE);

		input.Right = Input::Instance()->Button(KEY_INPUT_D);
		input.RightDown = Input::Instance()->ButtonDown(KEY_INPUT_D);
		input.Left = Input::Instance()->Button(KEY_INPUT_A);
		input.LeftDown = Input::Instance()->ButtonDown(KEY_INPUT_A);
	}

	memoryInput = input;
	return input;
}
//---------------------------------------------------------
//	�����蔻��
//---------------------------------------------------------
void Player::OnHit(Collision * other)
{
	// �n��
	if (other->getObject()->GetTag() == "Wall") 
	{
		float nextX = PositionX(), nextY = PositionY();

		float myPivotX = nextX + collider->getX();							// �������S X
		float myPivotY = nextY + collider->getY();							// �������S Y
		float otherPivotX = other->getObject()->PositionX() + other->getX();// ���蒆�S X
		float otherPivotY = other->getObject()->PositionY() + other->getY();// ���蒆�S Y

		// �㉺
		if (myPivotX < otherPivotX + (otherPivotY - myPivotY) && myPivotX > otherPivotX - (otherPivotY - myPivotY))
		{
			if (myPivotY <= otherPivotY) {
				isGround = true;
				nextY = other->getObject()->PositionY() - GraphHeight();
			}
			else {
				nextY = other->getObject()->PositionY() + other->getSizeY();
			}
			// �d�͂����Z�b�g
			GravityReset();
		}
		// ���E
		else
		{
			if (myPivotX <= otherPivotX) {
				nextX = other->getObject()->PositionX() - GraphWidth();
			}
			else {
				nextX = other->getObject()->PositionX() + other->getSizeX();
			}
			// �����x�����Z�b�g
			moveSpeed = 0;
		}

		PositionX(nextX); PositionY(nextY);
	} else
	// �ԉ΋�
	if (other->getObject()->GetTag() == "Firework")
	{

	}
}