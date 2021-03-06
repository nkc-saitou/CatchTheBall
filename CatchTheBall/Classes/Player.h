#pragma once

#include "Object.h"
#include "Gravity.h"
#include "Collision.h"

#pragma region 定数

const int RIGHT = 0;	// 右
const int LEFT = 1;	// 左

const float MOVE_SPEED_MAX = 300;	// 最高移動速度
const float ADD_ACCEL = 450;		// 加速度

#pragma endregion

enum PlayerState {
	Wait,
	Move,
	Shot,
	Dead
};

struct P_InputState {
	P_InputState();
	bool ActionKey;
	bool ActionKeyDown;
	bool JumpKey;
	bool JumpKeyDown;

	bool Right;
	bool RightDown;
	bool Left;
	bool LeftDown;

	float AngleX;
	float AngleY;
};

class Player : public Object, Gravity
{
public:
	static const string GetTagName() { return "Player"; }

	Player();
	Player(float x, float y, int order = 0);
	~Player();

	void SetPadNo(int);	// プレイヤーを設定
	void Update();		// 更新

private:
	PlayerState state;	// 状態
	int playerNo;		// プレイヤー番号
	int padNo;			// 操作パッド
	int bodyHandle[2];	// 本体画像ハンドル
	P_InputState memoryInput;// 入力情報の記憶

	bool isTouchBall;	// 花火玉に触れているか
	bool isGround;		// 地面に接しているか
	bool isGravity;		// 重力の有効の有無
	bool isJump;		// ジャンプ可能かどうか
	bool isJumpUp;		// ジャンプ中
	float moveSpeed;	// 移動速度
	int jumpStartTime;	// ジャンプ開始時間
	float ballPower;	// 保持した花火玉に加わっている力

	Collision *collider;	// 当たり判定

	void MoveAction();	// 移動
	void ShotAction();	// 射撃
	void DeadAction();	// 死亡
	void Jump();		// ジャンプ
	P_InputState PlayerInput();	// プレイヤーからの入力

	void OnHit(Collision *other);
};