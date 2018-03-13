#include "Player.h"
#include "FileManager.h"
#include "Input.h"
#include "Time.h"
#include "EntryData.h"
#include "Camera.h"

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
	isTouchBall = isGround = isJumpUp = isJump = false;
	isGravity = true;
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
	isTouchBall = isGround = isJump = isJumpUp = false;
	isGravity = true;
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

	if (state != Wait) return;

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

	// �W�����v
	if (isJumpUp) {	
		Jump();
	}

	// �d��
	if (isGravity) {
		isGround = false;
		float nextY = PositionY();
		ObjGravity();
		nextY += Fall_y();
		PositionY(nextY);
	}

	if(isTouchBall) isTouchBall = false;
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
	if (input.ActionKeyDown && isTouchBall) 
	{
		
		state = Shot;
		return;
	}

	// �W�����v
	if (input.JumpKeyDown && isJump && isGround) 
	{
		isGround = isGravity = isJump = false;
		isJumpUp = true;
		jumpStartTime = GetNowCount();
	}

	// �ړ�
	if (input.Right) 
	{
		if (input.RightDown) GraphHandle(bodyHandle[RIGHT]);
		moveSpeed += ADD_ACCEL * Time::GetDeltaTime();
	} else
	if (input.Left) 
	{
		if (input.LeftDown) GraphHandle(bodyHandle[LEFT]);
		moveSpeed -= ADD_ACCEL * Time::GetDeltaTime();
	} else
	if (isGround)// ���͂��Ȃ������ꍇ�A����
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

	// �ړ��͈͂̐���
	float LimitMinX = (Camera::MainCamera == nullptr) ? Camera::MainCamera->PositionX() : 0;
	float LimitMaxX = (Camera::MainCamera == nullptr) ? Camera::MainCamera->PositionX() + SCREEN_WIDTH - GraphWidth() : SCREEN_WIDTH - GraphWidth();

	if (nextX < LimitMinX) { 
		nextX = LimitMinX;
		moveSpeed = 0;
	}else 
	if (nextX > LimitMaxX) { 
		nextX = LimitMaxX;
		moveSpeed = 0;
	}
	
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
	const float JUMP_POWER = 1300;
	const int JUMP_UP_TIME = 100;
	const int JUMP_WAIT_TIME = 200;
	
	// �㏸
	if (GetNowCount() - jumpStartTime < JUMP_UP_TIME) {
		float nextY = PositionY();
		nextY -= JUMP_POWER * Time::GetDeltaTime();
		PositionY(nextY);
	}
	// �W�����v�I��
	if (GetNowCount() - jumpStartTime > JUMP_WAIT_TIME) {
		isJumpUp = false;
		isGravity = true;
	}
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

		float myToOtherDisY = myPivotY - otherPivotY;						// ���S�̋��� Y
		if (myToOtherDisY < 0) myToOtherDisY = -myToOtherDisY;				

		// �㉺
		if (myPivotX <= otherPivotX + myToOtherDisY && myPivotX >= otherPivotX - myToOtherDisY)
		{
			if (myPivotY <= otherPivotY) {
				isGround = true;
				if (!isJump) isJump = true;
				nextY = other->getObject()->PositionY() - GraphHeight();
			}
			else {
				isJumpUp = false;
				isGravity = true;
				nextY = other->getObject()->PositionY() + other->getSizeY();
			}
			// �d�͂����Z�b�g
			GravityReset();
		} else 
		// ���E
		if(otherPivotY - myPivotY < (collider->getSizeY() / 2 + other->getSizeY() / 2) * 0.5f)
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
		isTouchBall = true;
	}
}