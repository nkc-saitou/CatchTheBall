#include "UI.h"
#include "DxLib.h"

UI::UI()
{
	//初期化
	_handle = 0;
	_priority = 0;
	_x = 0; _y = 0;
	_rotation = 0;
	_scale = 1.0;
}

UI::~UI()
{

}
//---------------------------------------------------------
//	描画
//---------------------------------------------------------
void UI::Draw()
{
	if (_rotation != 0 || _scale != 1.0)
		DrawRotaGraphF(_x, _y, _scale, _rotation, _handle, TRUE);
	else
		DrawGraphF(_x, _y, _handle, TRUE);
}
//---------------------------------------------------------
//	プロパティ
//---------------------------------------------------------
void UI::Priority(int order) { _priority = order; }
int UI::Priority() { return _priority; }
void UI::PositionX(float posX) { _x = posX; }
float UI::PositionX() { return _x; }
void UI::PositionY(float posY) { _y = posY; }
float UI::PositionY() { return _y; }
void UI::Rotation(double degree) { _rotation = degree; }
double UI::Rotation() { return _rotation; }
void UI::Scale(double rate) { _scale = rate; }
double UI::Scale() { return _scale; }
void UI::GraphHandle(int graph) { _handle = graph; }
int UI::GraphHandle() { return _handle; }