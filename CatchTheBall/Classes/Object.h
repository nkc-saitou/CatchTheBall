#pragma once

class Object
{
public:
	Object();
	Object(int order = 0);
	~Object();
	virtual void Update() = 0;
	virtual void Draw();
	virtual void Draw(float cameraX, float cameraY);

	void Parent(Object* parent);	// �e�I�u�W�F�N�g
	Object* Parent();				// �e�I�u�W�F�N�g
	void Priority(int order);		// �D�揇��
	int Priority();					// �D�揇��
	void GraphWidth(float width);	// �`��摜�T�C�Y
	float GraphWidth();				// �`��摜�T�C�Y
	void GraphHeight(float height);	// �`��摜�T�C�Y
	float GraphHeight();			// �`��摜�T�C�Y
	void PositionX(float posX);		// X���̈ʒu
	float PositionX();				// X���̈ʒu
	void PositionY(float posY);		// Y���̈ʒu
	float PositionY();				// Y���̈ʒu
	void Rotation(double degree);	// ��]
	double Rotation();				// ��]
	void Scale(double rate);		// �g�嗦
	double Scale();					// �g�嗦

protected:
	void GraphHandle(int graph);	// �`��摜
	int GraphHandle();				// �`��摜

private:
	Object* _parent;			// �e�I�u�W�F�N�g
	int _handle;				// �`��摜
	int _priority;				// �D�揇��
	float _gWidth, _gHeight;	// �摜�T�C�Y
	float _x, _y;				// ���W
	double _rotation;			// ��]
	double _scale;				// �{��
};