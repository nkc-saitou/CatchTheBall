#pragma once

/*
///////////////////////////////////////////
Singleton�N���X
�V���O���g���ɂ������N���X�Ɍp��������

�g�p��FInput�N���X��ButtonDown���g�������ꍇ
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