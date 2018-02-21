#pragma once

class Object
{
public:
	Object();
	~Object();
	virtual void Update() = 0;
	virtual void Draw() = 0;

	void PositionX(int posX);
	int PositionX();
	void PositionY(int posY);
	int PositionY();
	void Rotation(int degree);
	int Rotation();

protected:
	void GraphHandle(int graph);
	int GraphHandle();

private:
	int handle;		//•`‰æ‰æ‘œ
	int x, y;		//À•W
	int rotation;	//‰ñ“]
};