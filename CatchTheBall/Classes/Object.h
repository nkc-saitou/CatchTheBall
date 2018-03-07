#pragma once

class Object
{
public:
	Object();
	Object(int order);
	~Object();
	virtual void Update() = 0;
	virtual void Draw();
	virtual void Draw(float cameraX, float cameraY);

	void Parent(Object* parent);	// 親オブジェクト
	Object* Parent();				// 親オブジェクト
	void Priority(int order);		// 優先順位
	int Priority();					// 優先順位
	void GraphWidth(float width);	// 描画画像サイズ
	float GraphWidth();				// 描画画像サイズ
	void GraphHeight(float height);	// 描画画像サイズ
	float GraphHeight();			// 描画画像サイズ
	void PositionX(float posX);		// X軸の位置
	float PositionX();				// X軸の位置
	void PositionY(float posY);		// Y軸の位置
	float PositionY();				// Y軸の位置
	void Rotation(double degree);	// 回転
	double Rotation();				// 回転
	void Scale(double rate);		// 拡大率
	double Scale();					// 拡大率

protected:
	void GraphHandle(int graph);	// 描画画像
	int GraphHandle();				// 描画画像

private:
	Object* _parent;			// 親オブジェクト
	int _handle;				// 描画画像
	int _priority;				// 優先順位
	float _gWidth, _gHeight;	// 画像サイズ
	float _x, _y;				// 座標
	double _rotation;			// 回転
	double _scale;				// 倍率
};