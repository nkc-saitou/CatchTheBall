#include "DxLib.h"

static int m_Key[256];  // キーの入力状態格納用変数

// キーの入力状態更新
void Keyboard_Update()
{
	// 現在のキーの入力状態を格納する
    char tmpKey[256];             
	// 全てのキーの入力状態を得る
    GetHitKeyStateAll( tmpKey );  

    for( int i=0; i<256; i++ ){
		// i番のキーコードに対応するキーが押されていたら
        if( tmpKey[i] != 0 ){ 
            m_Key[i]++;   // 加算
        } 
		// 押されていなければ
		else {
            m_Key[i] = 0; // 0にする
        }
    }
}

// KeyCodeのキーの入力状態を取得する
int Keyboard_Get( int KeyCode ){
	// KeyCodeの入力状態を返す
    return m_Key[ KeyCode ]; 
}
