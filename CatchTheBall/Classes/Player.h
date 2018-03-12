#pragma once

#include "Object.h"
#include "Gravity.h"

enum PlayerState {
	Wait,
	Move,
	Shot,
	Dead
};

class Player : public Object, public Gravity
{
public:
	Player();
	Player(float x, float y, int order = 0);
	~Player();

	void Update();		//更新
	void SetPadNo(int);	//プレイヤーを設定

private:
	PlayerState state;	//状態
	int padNo;			//操作パッド

	bool isTouchBall;	//花火玉に触れているか
	bool isGround;		//地面に接しているか
	float ballPower;	//保持した花火玉に加わっている力

	void MoveAction();	//移動
	void ShotAction();	//射撃
	void DeadAction();	//死亡
	void Jump();		//ジャンプ
};