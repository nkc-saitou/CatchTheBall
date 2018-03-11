#pragma once

#include "Object.h"

enum PlayerState {
	Wait,
	Move,
	Shot,
	Dead
};

class Player : public Object
{
public:
	Player();
	Player(float x, float y, int order = 0);
	~Player();

	void Update();		//更新
	//void Draw();		//描画

	void SetPadNo(int);	//プレイヤーを設定

private:
	void MoveAction();	//移動
	void ShotAction();	//射撃
	void DeadAction();	//死亡

	PlayerState state;	//状態
	int padNo;			//操作パッド
};