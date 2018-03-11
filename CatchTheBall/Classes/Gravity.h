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
#include "Input.h"

class Gravity
{
	//プレイヤーのy座標
	int y;

	//落下した際の前回のy座標を保存
	int y_prev;

	//現在のy座標を保存
	int y_temp;

public:
	Gravity();

protected:
	void ObjGravity();
	void GravityReset();

	int Fall_y(){ return y; }
	void Fall_y(int fallY) { y = fallY; }
};