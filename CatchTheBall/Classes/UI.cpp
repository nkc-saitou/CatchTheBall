#include "UI.h"
#include "DxLib.h"

/////////////////////////////////////////////////////
//引数			:画像のパス、ｘ座標、ｙ座標、,表示非表示(デフォルトは表示(true))、回転(デフォルトは回転無し)、サイズ(デフォルトは等身)、描画の優先度(デフォルトは20)
//戻り値		:なし
//動作			:値の初期化
/////////////////////////////////////////////////////
UI::UI(string s, float x, float y, bool drawFlg, double rotation, double scale, int priority)
{
	//初期化
	GraphHandle(FileManager::Instance()->GetFileHandle(s));
	PositionX(x);
	PositionY(y);
	DisplayFlg(drawFlg);
	Rotation(rotation);
	Scale(scale);
	Priority(priority);
}

/////////////////////////////////////////////////////
//引数			:なし
//戻り値		:なし
//動作			:画像の描画
/////////////////////////////////////////////////////
void UI::Draw()
{
	if (Rotation() != 0 || Scale() != 1.0)
		DrawRotaGraphF(PositionX(), PositionY(), Scale(), Rotation(), GraphHandle(), TRUE);
	else
		DrawGraphF(PositionX(), PositionY(), GraphHandle(), TRUE);
}

/////////////////////////////////////////////////////
//引数			:描画する、しないを判断するフラグ(デフォルトはtrue(表示))
//戻り値		:なし
//動作			:画像の表示非表示
/////////////////////////////////////////////////////
void UI::DrawDisplay(bool drawFlg)
{
	DisplayFlg(drawFlg);

	if (DisplayFlg())
	{
		Draw();
	}
}

/////////////////////////////////////////////////////
//引数			:ｘ座標、ｙ座標、表示非表示(デフォルトは表示(true))、回転(デフォルトは回転無し)、サイズ(デフォルトは等身)、描画の優先度(デフォルトは20)
//戻り値		:なし
//動作			:位置の更新
/////////////////////////////////////////////////////
void UI::UIMove(float x, float y, double rotation, double scale, int priority)
{
	PositionX(x);
	PositionY(y);
	Rotation(rotation);
	Scale(scale);
	Priority(priority);
}

/////////////////////////////////////////////////////
//引数			:なし
//戻り値		:なし
//動作			:画像データを削除
/////////////////////////////////////////////////////
void UI::Delete()
{
	DeleteGraph(GraphHandle());
}

/////////////////////////////////////////////////////
//プロパティ
/////////////////////////////////////////////////////
void UI::DisplayFlg(bool drawFlg) { _display = drawFlg; }
bool UI::DisplayFlg() { return _display; }