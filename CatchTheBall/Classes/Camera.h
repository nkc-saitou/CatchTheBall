#pragma once

#include "Object.h"
#include <vector>

class Camera : public Object
{
public:
	Camera(float x, float y);
	~Camera();

	void Update();
	void Draw();
	void DrawScreen(std::vector<Object*>);
	bool DrawCheck(Object*);

	static Camera* MainCamera;

private:
	int SCREEN_WIDTH;	//��ʔ͈́@��
	int SCREEN_HEIGHT;	//��ʔ͈́@�c
};