#include "Player.h"
#include "FileManager.h"
#include "Input.h"

Player::Player()
{
	//GraphHandle(FileManager::Instance()->GetFileHandle("Player_01_Right.png"));
	state = Wait;
}
Player::Player(float x, float y)
{
	//GraphHandle(FileManager::Instance()->GetFileHandle("Player_01_Right.png"));
	PositionX(x); PositionY(y);
	state = Wait;
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
}
//---------------------------------------------------------
//	描画
//---------------------------------------------------------
//void Player::Draw()
//{
//	
//}
//---------------------------------------------------------
//	移動
//---------------------------------------------------------
void Player::MoveAction()
{
	float pointX = PositionX();
	float pointY = PositionY();

	//捕球
	if (Input::Instance()->ButtonDown(PAD_INPUT_B, Pad_1)) {

		return;
	}

	//ジャンプ
	if (Input::Instance()->ButtonDown(PAD_INPUT_A, Pad_1)) {

	}

	//移動	左
	if (Input::Instance()->ButtonDown(PAD_INPUT_7, Pad_1)) {

	} else
	//移動　右
	if (Input::Instance()->ButtonDown(PAD_INPUT_8, Pad_1)) {

	}
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