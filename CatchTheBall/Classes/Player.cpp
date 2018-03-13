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
}
Player::Player(float x, float y, int order) : Object(order)
{
	bodyHandle[RIGHT] = FileManager::Instance()->GetFileHandle("Player_A_0");
	bodyHandle[LEFT]  = FileManager::Instance()->GetFileHandle("Player_A_1");
	GraphHandle(bodyHandle[RIGHT]);

	PositionX(x); PositionY(y);
	state = Wait;
	isTouchBall = false; isGround = true;
	moveSpeed = 0;
	memoryInput = P_InputState();

	collider = new Collision(16, 16, 32, 32, CollisionType::Circle, this, [this](Collision* other) { OnHit(other); });
}
Player::~Player() 
{

}
//---------------------------------------------------------
//	更新
//---------------------------------------------------------
void Player::Update()
{
	//行動
	switch (state) {
	case Wait: break;					// 待機
	case Move: MoveAction(); break;		// 移動
	case Shot: ShotAction(); break;		// 射撃
	case Dead: DeadAction(); break;		// 死亡
	}

	//float nextY = PositionY();
	////重力
	//ObjGravity();
	//nextY += Fall_y();
	//PositionY(nextY);
}
//---------------------------------------------------------
//	プレイヤーを設定
//---------------------------------------------------------
void Player::SetPadNo(int no)
{
	playerNo = no;
	padNo = EntryData::GetController(playerNo);



	state = Move;

	Input::Instance()->PadStartVibration(padNo, 1000, 500);
}
//---------------------------------------------------------
//	移動
//---------------------------------------------------------
void Player::MoveAction()
{
	// 位置
	float nextX = PositionX();
	// 入力
	P_InputState input = PlayerInput();

	// 捕球
	if (input.ActionKeyDown) {
		
		return;
	}
	// 地面に接していないなら
	if (!isGround) return;

	// ジャンプ
	if (input.JumpKeyDown) {
		Jump();
	}

	// 移動
	if (input.Right) 
	{
		if (input.RightDown) GraphHandle(bodyHandle[RIGHT]);
		moveSpeed += ADD_ACCEL * Time::GetDeltaTime();
	} else
	if (input.Left) 
	{
		if (input.LeftDown) GraphHandle(bodyHandle[LEFT]);
		moveSpeed -= ADD_ACCEL * Time::GetDeltaTime();
	} 
	else	// 入力がなかった場合、減速
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

	// 移動速度の制限
	if (moveSpeed > 0) moveSpeed = (moveSpeed > MOVE_SPEED_MAX) ? MOVE_SPEED_MAX : moveSpeed;
	else if (moveSpeed < 0) moveSpeed = (moveSpeed < -MOVE_SPEED_MAX) ? -MOVE_SPEED_MAX : moveSpeed;
	
	nextX += moveSpeed * Time::GetDeltaTime();
	PositionX(nextX);
}
//---------------------------------------------------------
//	射撃
//---------------------------------------------------------
void Player::ShotAction()
{

}
//---------------------------------------------------------
//	死亡
//---------------------------------------------------------
void Player::DeadAction()
{

}
//---------------------------------------------------------
//	ジャンプ
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
//	プレイヤーからの入力
//---------------------------------------------------------
P_InputState Player::PlayerInput()
{
	P_InputState input;

	// コントローラー
	if (padNo != 0)	{
		const float RIGHT_PUT_ANGLE = 0.8f;		// 入力判断
		const float LEFT_PUT_ANGLE = -0.8f;		// 入力判断

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
	// キーボード
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

void Player::OnHit(Collision * other)
{
}
