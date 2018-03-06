#pragma once

#include "UI.h"
#include "SceneMgr.h"
#include <vector>

class UIManager
{
public:
	UIManager();
	UIManager(eScene SceneName);
	~UIManager();

	void Initialize(); //初期化
	void Update();     //更新
	void Add(UI*);     //追加
	void Draw();       //表示

private:
	std::vector<UI*> uiArry;
};