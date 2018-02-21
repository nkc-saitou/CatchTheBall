#include "Object.h"

Object::Object() 
{
	
}

Object::~Object()
{

}
//-------------------------------------------------------------------
//	プロパティ
//-------------------------------------------------------------------
void Object::PositionX(int posX) { x = posX; }
int Object::PositionX() { return x; }
void Object::PositionY(int posY) { y = posY; }
int Object::PositionY() { return y; }
void Object::Rotation(int degree) { rotation = degree; }
int Object::Rotation() { return rotation; }
void Object::GraphHandle(int graph) { handle = graph; }
int Object::GraphHandle() { return handle; }