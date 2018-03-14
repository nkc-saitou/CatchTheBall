#include "GameManager.h"
#include "UI.h"
#include "Time.h"
#include "PlayerManager.h"

PlayerManager *playerMana;

void GameManager::GameStart()
{
	if (!stateFlg) 
	{
		state = GameState::GAMESTART;
		timeInterval = 5.0f;
		timer = 0.0f;
		stateFlg = true;
	}
}

void GameManager::GameClear()
{
	if (!stateFlg) 
	{
		state = GameState::GAMECLEAR;
		timeInterval = 3.0f;
		timer = 0.0f;
		stateFlg = true;
	}
}

void GameManager::GameOver()
{
	if (!stateFlg) 
	{
		new UI("GameOver.png", 320.0f, 200.0f, true, 0.0, 1.0, 20);
		state = GameState::GAMEOVER;
		timeInterval = 3.0f;
		timer = 0.0f;
		stateFlg = true;
	}
}

void GameManager::Update()
{
	timer += Time::GetDeltaTime();

	if (timeInterval < timer && stateFlg) 
	{
		switch (GameState())
		{
		case GameState::GAMESTART:
			stateFlg = false;
			playerMana->isFreeze = true;
			break;
		case GameState::GAMECLEAR:
			stateFlg = false;
			Scene::SceneFade(Scene::SELECT);
			break;
		case GameState::GAMEOVER:
			stateFlg = false;
			Scene::SceneFade(Scene::SELECT);
			break;
		default:
			break;
		}
	}
}