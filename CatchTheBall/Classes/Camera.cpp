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
//	çXêV
//---------------------------------------------------------
void Camera::Update()
{

}
//---------------------------------------------------------
//	ï`âÊ
//---------------------------------------------------------
void Camera::Draw() {}
void Camera::DrawScreen(std::vector<Object*> drawObjArry)
{
	for (Object* obj : drawObjArry) {
		

	}
}
//---------------------------------------------------------
//	ï`âÊîÕàÕì‡Ç©Ç«Ç§Ç©
//---------------------------------------------------------
bool Camera::DrawCheck(Object* drawObj) 
{
	if (drawObj->PositionX()						  > PositionX() + SCREEN_WIDTH ) return false;
	if (drawObj->PositionX() + drawObj->GraphWidth()  < PositionY()				   ) return false;
	if (drawObj->PositionY()						  > PositionY() + SCREEN_HEIGHT) return false;
	if (drawObj->PositionY() + drawObj->GraphHeight() < PositionY()				   ) return false;
	return true;
}