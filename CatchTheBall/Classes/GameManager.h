#pragma once
#include "DxLib.h"
#include "Singleton.h"
#include "BaseScene.h"

class GameManager : public Singleton<GameManager> 
{
public:
	void GameStart();
	void GameOver();
	void GameClear();

	void Update();
private:
	enum GameState
	{
		GAMESTART,
		GAMECLEAR,
		GAMEOVER
	};
	GameState state;
	float timeInterval;
	float timer;
	bool stateFlg = false;

};