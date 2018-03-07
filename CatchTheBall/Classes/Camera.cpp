#include "Camera.h"
#include "ObjectManager.h"

Camera* Camera::MainCamera;

Camera::Camera(float x, float y) : Object(15)
{
	if (MainCamera == nullptr) {
		MainCamera = this;
	}

	SCREEN_WIDTH = 640;
	SCREEN_HEIGHT = 480;
	PositionX(x); PositionY(y);
}
Camera::~Camera()
{
	if (MainCamera == this) {
		MainCamera = nullptr;
	}
}
//---------------------------------------------------------
//	�X�V
//---------------------------------------------------------
void Camera::Update()
{
	float posX = PositionX();
	posX += 1;
	if (posX > 320) posX = 0;
	PositionX(posX);
}
//---------------------------------------------------------
//	�`��
//---------------------------------------------------------
void Camera::Draw() {}
void Camera::DrawScreen(std::vector<Object*> drawObjArry)
{
	for (Object* obj : drawObjArry) 
	{
		if (obj->Priority() >= UI_NO) obj->Draw();
		else if (DrawCheck(obj)) obj->Draw(PositionX(), PositionY());
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