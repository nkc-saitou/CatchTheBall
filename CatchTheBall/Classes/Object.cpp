#include "Object.h"
#include "DxLib.h"
#include "ObjectManager.h"

Object::Object()
{
	//初期化
	_handle = 0;
	_priority = 0;
	_x = 0; _y = 0;
	_rotation = 0;
	_scale = 1.0;
}
Object::~Object()
{
	auto itr = ObjectManager::Instance()->objectArry.begin();
	while (itr != ObjectManager::Instance()->objectArry.end()) 
	{
		if ((*itr) == this) 
		{
			itr = ObjectManager::Instance()->objectArry.erase(itr);
		}
		else 
		{
			itr++;
		}
	}
}
//---------------------------------------------------------
//	描画
//---------------------------------------------------------
void Object::Draw()
{
	if (_rotation != 0 || _scale != 1.0)
		DrawRotaGraphF(_x, _y, _scale, _rotation, _handle, TRUE);
	else
		DrawGraphF(_x, _y, _handle, TRUE);
}
void Object::Draw(float cameraX, float cameraY)
{
	if (_rotation != 0 || _scale != 1.0)
		DrawRotaGraphF(_x + cameraX, _y + cameraY, _scale, _rotation, _handle, TRUE);
	else
		DrawGraphF(_x + cameraX, _y + cameraY, _handle, TRUE);
}
//---------------------------------------------------------
//	プロパティ
//---------------------------------------------------------
void Object::Parent(Object* parent) { _parent = parent; }
Object* Object::Parent() { return _parent; }
void Object::Priority(int order) { _priority = order; }
int Object::Priority() { return _priority; }
void Object::GraphWidth(float width) { _gWidth = width; }
float Object::GraphWidth() { return _gWidth; }
void Object::GraphHeight(float height) { _gHeight = height; }
float Object::GraphHeight() { return _gHeight; }
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