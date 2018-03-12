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
	printfDx("デス");
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

	//重力
	ObjGravity();
}
//---------------------------------------------------------
//	プレイヤーを設定
//---------------------------------------------------------
void Player::SetPadNo(int no)
{
	padNo = no;
	state = Move;

	Input::Instance()->PadStartVibration(no, 1000, 500);
}
//---------------------------------------------------------
//	移動
//---------------------------------------------------------
void Player::MoveAction()
{
	const float MOVE_SPEED = 200;
	float pointX = PositionX();

	//捕球
	if (isTouchBall && Input::Instance()->ButtonDown(XINPUT_BUTTON_B, padNo)) {
		//printfDx("B_BUTTON");
		return;
	}
	//地面に接していないなら
	if (!isGround) return;

	//ジャンプ
	if (Input::Instance()->Button(XINPUT_BUTTON_A, padNo)) {
		Jump();
	}

	//移動	右
	if (Input::Instance()->AngleInputX(padNo) > 0.8f) {
		pointX += MOVE_SPEED * Time::GetDeltaTime();
	} else
	//移動　左
	if (Input::Instance()->AngleInputX(padNo) < -0.8f) {
		pointX -= MOVE_SPEED * Time::GetDeltaTime();
	}

	PositionX(pointX);
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
	if (PositionY() <= 240) {
		PositionY(PositionY() + Fall_y() * Time::GetDeltaTime());
	}
	else if (PositionY() >= 240) {
		PositionY(PositionY() - 200 * Time::GetDeltaTime());
	}
}