#include "Object.h"
#include "DxLib.h"
#include "ObjectManager.h"

Object::Object()
{
	Initialize();
}
Object::Object(int order)
{
	Initialize(order);
}
Object::Object(Object* parent, int order) {
	Initialize(order);
	Parent(parent);
}
Object::~Object()
{
	//�e������
	Parent(nullptr);

	//�q���ɍ폜
	for(auto item : _child) {
		delete item;
	}
	ObjectManager::Instance()->Destroy(this);
}

//---------------------------------------------------------
//	������
//---------------------------------------------------------
void Object::Initialize(int order) {
	_handle = 0; _priority = order;
	_x = 0; _y = 0;
	_rotation = 0; _scale = 1.0;
	_parent = nullptr;
	ObjectManager::Instance()->Add(this);
}
//---------------------------------------------------------
//	�X�V
//---------------------------------------------------------
void Object::Update() { }
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
void Object::Draw(float cameraX, float cameraY)
{
	if (_rotation != 0 || _scale != 1.0)
		DrawRotaGraphF(_x + cameraX, _y + cameraY, _scale, _rotation, _handle, TRUE);
	else
		DrawGraphF(_x + cameraX, _y + cameraY, _handle, TRUE);
}
//---------------------------------------------------------
//	�e�q�֌W
//---------------------------------------------------------
Object* Object::GetChild(int num) {
	if (num < 0 || num >= (int)_child.size()) return nullptr;
	return _child[num];
}
const int Object::GetChildCount() {
	return _child.size();
}
void Object::Parent(Object* parent) {

	//�e�q�֌W������
	if (_parent != nullptr) {
		
		//���[���h���W������Ă���
		float x = PositionX();
		float y = PositionY();
		float rot = Rotation();
		double scale = Scale();

		auto itr = _parent->_child.begin();
		while (itr != _parent->_child.end()) {
			if ((*itr) == this) itr = _parent->_child.erase(itr);
			else itr++;
		}

		//�K�p
		PositionX(x);
		PositionY(y);
		Rotation(rot);
		Scale(scale);
	}

	//�e�q�֌W���\�z
	if ((_parent = parent) != nullptr) {

		//���[���h���W������Ă���
		float x = PositionX();
		float y = PositionY();
		float rot = Rotation();
		double scale = Scale();

		_parent->_child.push_back(this);

		//�K�p
		PositionX(x);
		PositionY(y);
		Rotation(rot);
		Scale(scale);
	}
}
Object* Object::Parent() { return _parent; }
//---------------------------------------------------------
//	���W�ϊ��n
//---------------------------------------------------------
float Object::ConvertToWorldX() {
	float x = _x;
	Object *p = _parent;
	while (p) {
		x += p->_x;
		p = p->_parent;
	}
	return x;
}
float Object::ConvertToWorldY() {
	float y = _y;
	Object *p = _parent;
	while (p) {
		y += p->_y;
		p = p->_parent;
	}
	return y;
}
float Object::ConvertToWorldRotation() {
	float rot = _rotation;
	Object *p = _parent;
	while (p) {
		rot += p->_rotation;
		p = p->_parent;
	}
	return rot;
}
double Object::ConvertToWorldScale() {
	double scale = _scale;
	Object *p = _parent;
	while (p) {
		scale *= p->_scale;
		p = p->_parent;
	}
	return scale;
}
//---------------------------------------------------------
//	�v���p�e�B
//---------------------------------------------------------
void Object::Priority(int order) { _priority = order; }
int Object::Priority() { return _priority; }
void Object::GraphWidth(float width) { _gWidth = width; }
float Object::GraphWidth() { return _gWidth; }
void Object::GraphHeight(float height) { _gHeight = height; }
float Object::GraphHeight() { return _gHeight; }

void Object::PositionX(float posX) { _x = ConvertToWorldX() - _x + posX; }
float Object::PositionX() { return ConvertToWorldX(); }
void Object::LocalPositionX(float posX) { _x = posX; }
float Object::LocalPositionX() { return _x; }

void Object::PositionY(float posY) { _y = ConvertToWorldY() - _y + posY; }
float Object::PositionY() { return ConvertToWorldY(); }
void Object::LocalPositionY(float posY) { _y = posY; }
float Object::LocalPositionY() { return _y; }

void Object::SetPosition(float posX, float posY) { PositionX(posX); PositionY(posY); }
void Object::SetLocalPosition(float posX, float posY) { _x = posX; _y = posY; }

void Object::Rotation(double degree) { _rotation = ConvertToWorldRotation() - _rotation + degree; }
double Object::Rotation() { return ConvertToWorldRotation(); }
void Object::LocalRotation(double degree) { _rotation = degree; }
double Object::LocalRotation() { return _rotation; }

void Object::Scale(double rate) { _scale = ConvertToWorldScale() - _scale + rate; }
double Object::Scale() { return ConvertToWorldScale(); }
void Object::LocalScale(double rate) { _scale = rate; }
double Object::LocalScale() { return _scale; }

void Object::GraphHandle(int graph) { _handle = graph; }
int Object::GraphHandle() { return _handle; }