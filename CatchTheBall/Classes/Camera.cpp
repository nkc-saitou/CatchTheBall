#include "Camera.h"
#include "ObjectManager.h"

Camera::Camera(float x, float y) 
{
	PositionX(x); PositionY(y);
}
Camera::~Camera()
{

}
//---------------------------------------------------------
//	�X�V
//---------------------------------------------------------
void Camera::Update()
{

}
//---------------------------------------------------------
//	�`��
//---------------------------------------------------------
void Camera::Draw() {}
void Camera::DrawScreen(std::vector<Object*> drawObjArry)
{
	for (Object* obj : drawObjArry) {
		

	}
}
//---------------------------------------------------------
//	�`��͈͓����ǂ���
//---------------------------------------------------------
bool Camera::DrawCheck(Object* drawObj) 
{
	if (drawObj->PositionX()						  > PositionX() + SCREEN_WIDTH ) return false;
	if (drawObj->PositionX() + drawObj->GraphWidth()  < PositionY()				   ) return false;
	if (drawObj->PositionY()						  > PositionY() + SCREEN_HEIGHT) return false;
	if (drawObj->PositionY() + drawObj->GraphHeight() < PositionY()				   ) return false;
	return true;
}