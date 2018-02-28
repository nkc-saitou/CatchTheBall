#pragma once

class Object
{
public:
	Object();
	~Object();
	virtual void Update() = 0;
	virtual void Draw();

	void Priority(int order);
	int Priority();
	void PositionX(int posX);
	int PositionX();
	void PositionY(int posY);
	int PositionY();
	void Rotation(double degree);
	double Rotation();
	void Scale(double rate);
	double Scale();

protected:
	void GraphHandle(int graph);
	int GraphHandle();

private:
	int _handle;		//•`‰æ‰æ‘œ
	int _priority;		//—Dæ‡ˆÊ
	int _x, _y;			//À•W
	double _rotation;	//‰ñ“]
	double _scale;		//”{—¦
};