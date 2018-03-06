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

	void Initialize(); //‰Šú‰»
	void Update();     //XV
	void Add(UI*);     //’Ç‰Á
	void Draw();       //•\¦

private:
	std::vector<UI*> uiArry;
};