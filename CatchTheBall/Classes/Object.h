#pragma once

#include <vector>

using namespace std;

class Object
{
public:
	Object();
	Object(int order);
	Object(Object* parent, int order = 0);
	~Object();
	virtual void Update();
	virtual void Draw();
	virtual void Draw(float cameraX, float cameraY);

	void Parent(Object* parent);	// 親オブジェクト
	Object* Parent();				// 親オブジェクト
	Object* GetChild(int num);		// 子オブジェクトの取得
	const int GetChildCount();		// 子オブジェクトの数の取得

	string GetTag() { return tag; }

	#pragma region Priority
	void Priority(int order);		// 優先順位
	int Priority();					// 優先順位
	#pragma endregion

	#pragma region Graph
	void GraphWidth(float width);	// 描画画像サイズ
	float GraphWidth();				// 描画画像サイズ
	void GraphHeight(float height);	// 描画画像サイズ
	float GraphHeight();			// 描画画像サイズ
	#pragma endregion

	#pragma region Transform
	void SetPosition(float posX, float posY);		//座標のセット
	void SetLocalPosition(float posX, float posY);	//座標のセット

	void PositionX(float posX);			// X軸の位置(絶対)
	float PositionX();					// X軸の位置(絶対)
	void LocalPositionX(float posX);	// X軸の位置(相対)
	float LocalPositionX();				// X軸の位置(相対)

	void PositionY(float posY);			// Y軸の位置(絶対)
	float PositionY();					// Y軸の位置(絶対)
	void LocalPositionY(float posX);	// X軸の位置(相対)
	float LocalPositionY();				// X軸の位置(相対)

	void Rotation(double degree);		// 回転(絶対)
	double Rotation();					// 回転(絶対)
	void LocalRotation(double degree);	// 回転(相対)
	double LocalRotation();				// 回転(相対)

	void Scale(double rate);			// 拡大率(絶対)
	double Scale();						// 拡大率(絶対)
	void LocalScale(double rate);		// 拡大率(相対)
	double LocalScale();				// 拡大率(相対)
	#pragma endregion

protected:

	string tag;						//ユーザー定義のデータ

	void GraphHandle(int graph);	// 描画画像
	int GraphHandle();				// 描画画像

private:
	Object* _parent;			// 親オブジェクト
	vector<Object*> _child;		// 子オブジェクト
	int _handle;				// 描画画像
	int _priority;				// 優先順位
	int _gWidth, _gHeight;		// 画像サイズ(ピクセル)
	float _x, _y;				// 座標(相対)
	double _rotation;			// 回転(相対)
	double _scale;				// 拡大率(相対)

	void Initialize(int order = 0);	//内部用初期化

	//座標変換系
	float ConvertToWorldX();
	float ConvertToWorldY();
	float ConvertToWorldRotation();
	double ConvertToWorldScale();
};