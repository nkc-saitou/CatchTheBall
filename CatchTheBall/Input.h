#pragma once
#include "Dxlib.h"
#include <string>
#include "Singleton.h"

//チェックするゲームパッドの数
#define MAX_GAMEPAD_NUM 8

//ボタン総数
#define MAX_BUTTON_PAD 32

//キーボード入力用バッファサイズ
#define KEY_STATE_BUFFER_SIZE 256

//押された
#define INPUT_ON 1

//押されていない
#define INPUT_OFF 0

///////////////////////////////////////////
// 入力管理クラス
///////////////////////////////////////////
class Input : public Singleton <Input>
{
	//キーの入力状態を格納
	int key[256];
	char buf[256];

	int tempButton; //１フレーム前の入力情報(押されたかどうか)

	void ButtonSetting();

public:

	bool ButtonDown(int keyCode); //ボタンを押した瞬間
	bool Button(int keyCode); //ボタンを押しているとき
	bool ButtonPull(int keyCode); //ボタンが離されたとき
	bool ButtonFree(int keyCode); //ボタンが押されていない時
};
