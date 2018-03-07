#pragma once

#define FADE_IMAGE "test1.png"

// シーンのもととなるクラス(継承させる)
class BaseScene
{
public:
	// 初期化
	virtual void Initialize() = 0; 

	// 更新
	virtual void Update() = 0;

	// 描画
	virtual void Draw() = 0;
};

// シーンを管理するクラス
class Scene
{
public:
	Scene();
	~Scene();

	// シーンタイプ
	enum SCENE {
		TITLE,
		SELECT,
		GAME
	};

	// シーン変更
	static void ChangeScene(SCENE scene);
	// シーンフェード
	static void SceneFade(SCENE nextScene);
	// 更新
	static void Update();
	// 描画
	static void Draw();
private:
	// 現在のシーン
	static BaseScene* c_Scene;
};
