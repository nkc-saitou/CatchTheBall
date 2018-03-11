#pragma once

#include "FileManager.h"
#include "Object.h"

class UI : public Object
{
	bool _display;

	void Draw() override;


public:
	UI(string s, float x, float y, bool drawFlg = true, double rotation = 0, double scale = 1.0, int priority = 20);
	~UI() {};

	void UIMove(float x , float y , double rotation = 0, double scale = 1.0, int priority = 20);
	void Update() override {};
	void DrawDisplay(bool drawFlg = true);
	void Delete();

	void DisplayFlg(bool drawFlg);
	bool DisplayFlg();
};