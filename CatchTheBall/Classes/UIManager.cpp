#include "UIManager.h"
#include "DxLib.h"

UIManager::UIManager()
{

}

UIManager::UIManager(eScene SceneName)
{

}

UIManager::~UIManager()
{

}

void UIManager::Initialize()
{
	//�v�f�̍폜
	while (uiArry.begin() != uiArry.end()) {
		auto ui = uiArry.end();
		uiArry.pop_back();
		delete &ui;
	}
}

//---------------------------------------------------------
//	ui�̒ǉ�
//	�EPriority(�D�揇��)���Ⴂ���̂���}��
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
//	�X�V
//---------------------------------------------------------
void UIManager::Update()
{
	//�X�V
	for (auto ui : uiArry)
	{
		ui->Update();
	}
	//�`��
	Draw();
}

//---------------------------------------------------------
//	�`��
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