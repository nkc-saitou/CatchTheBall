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

	void Initialize(); //������
	void Update();     //�X�V
	void Add(UI*);     //�ǉ�
	void Draw();       //�\��

private:
	std::vector<UI*> uiArry;
};