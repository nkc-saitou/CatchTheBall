#pragma once

class Object
{
public:
	Object();
	virtual void Update() = 0;
	virtual void Draw() = 0;
protected:
	int GraphID;				//•`‰æ‰æ‘œ
	int PositionX, PositionY;	//À•W
	int Rotation;				//‰ñ“]
};