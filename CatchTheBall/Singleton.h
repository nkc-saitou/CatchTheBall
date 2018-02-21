#pragma once

/*
///////////////////////////////////////////
Singletonクラス
シングルトンにしたいクラスに継承させる

使用例：InputクラスのButtonDownを使いたい場合
Input::Instance()->ButtonDown(keyCode)
///////////////////////////////////////////
*/

template <typename _T>
class Singleton
{
protected:
	Singleton(){}
	virtual ~Singleton(){}
	Singleton(const Singleton& r){}
	Singleton& operator = (const Singleton& r){}

public:
	static _T* Instance() {
		static _T inst;
		return &inst;
	};
};