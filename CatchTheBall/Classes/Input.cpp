#include "Input.h"

/////////////////////////////////////////////////////
//引数			:入力キーコード
//戻り値		:引数のキーが押されていればtrue
//動作			:引数のキーが押されているかを判定
/////////////////////////////////////////////////////
bool Input::Button(int keyCode)
{
	if (CheckHitKey(keyCode) == INPUT_ON)
	{
		return true;
	}
	return false;
}

/////////////////////////////////////////////////////
//引数			:入力キーコード
//戻り値		:引数のキーが押された瞬間のみtrue
//動作			:引数のキーが押された瞬間を判定
/////////////////////////////////////////////////////
bool Input::ButtonDown(int keyCode)
{
	Input::ButtonSetting();

	if (key[keyCode] == INPUT_ON) return true;
	else return false;
}


/////////////////////////////////////////////////////
//引数			:入力キーコード
//戻り値		:引数のキーが離された瞬間のみtrue
//動作			:引数のキーが離された瞬間を判定
/////////////////////////////////////////////////////
bool Input::ButtonPull(int keyCode)
{
	Input::ButtonSetting();

	if (tempButton > key[keyCode] && key[keyCode] == INPUT_OFF)
	{
		tempButton = 0;
		return true;
	}

	tempButton = key[keyCode];
	
	return false;
}

/////////////////////////////////////////////////////
//引数			:入力キーコード
//戻り値		:引数のキーが押されていなければtrue
//動作			:引数のキーが離されている状態かを判定
/////////////////////////////////////////////////////
bool Input::ButtonFree(int keyCode)
{
	if (CheckHitKey(keyCode) == INPUT_OFF)
	{
		return true;
	}
	return false;
}

/////////////////////////////////////////////////////
//引数			:なし
//戻り値		:なし
//動作			:現在のキー入力状態を管理
/////////////////////////////////////////////////////
void Input::ButtonSetting()
{

	//キーの入力状態を得る
	GetHitKeyStateAll(buf);

	//キーコードに対応するキーが押されていたら
	for (int i = 0; i < 256; i++)
	{
		if (buf[i] != INPUT_OFF) key[i]++;
		else key[i] = 0;
	}
}
