#pragma once

/*
///////////////////////////////////////////
Gravityクラス

概要　：オブジェクトに重力を与える
使い方：コンストラクタの引数に初期ｙ座標を渡す。ObjGravity()で更新をして、Fall_yの値で落下する
使用例：DrawGraph(x, fall_y(), GHandle, TRUE);
注意　：ObjGravity()は毎フレーム更新すること
///////////////////////////////////////////
*/

#include "DxLib.h"
#include "Time.h"

class Gravity
{
	//プレイヤーのy座標
	double y;

	double gravity;

public:
	Gravity();

protected:
	void ObjGravity();
	void GravityReset();

	int Fall_y(){ return y; }
};