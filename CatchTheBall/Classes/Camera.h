#pragma once

#include "Object.h"
#include <vector>

const static int SCREEN_WIDTH = 640;	//‰æ–Ê”ÍˆÍ@‰¡
const static int SCREEN_HEIGHT = 480;	//‰æ–Ê”ÍˆÍ@c

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