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
	void PositionX(float posX);
	float PositionX();
	void PositionY(float posY);
	float PositionY();
	void Rotation(double degree);
	double Rotation();
	void Scale(double rate);
	double Scale();

protected:
	void GraphHandle(int graph);
	int GraphHandle();

private:
	int _handle;		//�`��摜
	int _priority;		//�D�揇��
	float _x, _y;			//���W
	double _rotation;	//��]
	double _scale;		//�{��
};