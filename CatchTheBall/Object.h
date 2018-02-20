#pragma once

class Object
{
public:
	Object();
	virtual void Update() = 0;
	virtual void Draw() = 0;
protected:
	int GraphID;				//�`��摜
	int PositionX, PositionY;	//���W
	int Rotation;				//��]
};