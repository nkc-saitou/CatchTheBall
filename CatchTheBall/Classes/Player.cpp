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
	Fall_y();
}
//---------------------------------------------------------
//	プレイヤーを設定
//---------------------------------------------------------
void Player::SetPadNo(int no)
{
	padNo = no;
	state = Move;
}
//---------------------------------------------------------
//	移動
//---------------------------------------------------------
void Player::MoveAction()
{
	const float MOVE_SPEED = 100;
	float pointX = PositionX(), pointY = PositionY();

	//捕球
	if (isTouchBall && Input::Instance()->ButtonDown(XINPUT_BUTTON_B, padNo)) {
		//printfDx("B_BUTTON");
		return;
	}

	//ジャンプ
	if (Input::Instance()->ButtonDown(XINPUT_BUTTON_A, padNo)) {
		//printfDx("A_BUTTON");
	}

	//移動	右
	if (Input::Instance()->Button(XINPUT_BUTTON_DPAD_RIGHT, padNo)) {
		pointX += MOVE_SPEED * Time::GetDeltaTime();
	} else
	//移動　左
	if (Input::Instance()->Button(XINPUT_BUTTON_DPAD_LEFT, padNo)) {
		pointX -= MOVE_SPEED * Time::GetDeltaTime();
	}

	//pointX += 0.2;
	PositionX(pointX); PositionY(pointY);
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