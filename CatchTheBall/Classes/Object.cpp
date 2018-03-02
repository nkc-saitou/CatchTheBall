#include "Object.h"
#include "DxLib.h"

Object::Object() 
{
	//������
	_handle = 0;
	_priority = 0;
	_x = 0; _y = 0;
	_rotation = 0;
	_scale = 1.0;
}

Object::~Object()
{
	
}
//---------------------------------------------------------
//	�`��
//---------------------------------------------------------
void Object::Draw()
{
	if (_rotation != 0 || _scale != 1.0)
		DrawRotaGraphF(_x, _y, _scale, _rotation, _handle, TRUE);
	else
		DrawGraphF(_x, _y, _handle, TRUE);
}
//---------------------------------------------------------
//	�v���p�e�B
//---------------------------------------------------------
void Object::Priority(int order) { _priority = order; }
int Object::Priority() { return _priority; }
void Object::PositionX(float posX) { _x = posX; }
float Object::PositionX() { return _x; }
void Object::PositionY(float posY) { _y = posY; }
float Object::PositionY() { return _y; }
void Object::Rotation(double degree) { _rotation = degree; }
double Object::Rotation() { return _rotation; }
void Object::Scale(double rate) { _scale = rate; }
double Object::Scale() { return _scale; }
void Object::GraphHandle(int graph) { _handle = graph; }
int Object::GraphHandle() { return _handle; }