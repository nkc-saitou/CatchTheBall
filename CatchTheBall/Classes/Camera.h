#pragma once

#include "Object.h"
#include <vector>

const static int SCREEN_WIDTH = 640;	//��ʔ͈́@��
const static int SCREEN_HEIGHT = 480;	//��ʔ͈́@�c

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
};