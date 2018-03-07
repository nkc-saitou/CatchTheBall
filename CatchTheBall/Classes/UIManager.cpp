#include "UIManager.h"
#include "DxLib.h"

UIManager::UIManager()
{

}

//UIManager::UIManager(eScene SceneName)
//{
//
//}

UIManager::~UIManager()
{

}

void UIManager::Initialize()
{
	//要素の削除
	while (uiArry.begin() != uiArry.end()) {
		auto ui = uiArry.end();
		uiArry.pop_back();
		delete &ui;
	}
}

//---------------------------------------------------------
//	uiの追加
//	・Priority(優先順位)が低いものから挿入
//---------------------------------------------------------
void UIManager::Add(UI* ui)
{
	if (&ui == nullptr) return;

	if (uiArry.begin() == uiArry.end())
	{
		uiArry.push_back(ui);
	}

	auto it = uiArry.begin();
	for (auto uiObj : uiArry)
	{
		if (uiObj->Priority() > ui->Priority())break;
		it++;
	}

	uiArry.insert(it, ui);
}

//---------------------------------------------------------
//	更新
//---------------------------------------------------------
void UIManager::Update()
{
	//更新
	for (auto ui : uiArry)
	{
		ui->Update();
	}
	//描画
	Draw();
}

//---------------------------------------------------------
//	描画
//---------------------------------------------------------
void UIManager::Draw()
{
	ClearDrawScreen();

	for (auto ui : uiArry)
	{
		ui->Draw();
	}
	ScreenFlip();
}