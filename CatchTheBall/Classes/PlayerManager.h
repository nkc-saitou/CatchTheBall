#pragma once

#include "Player.h"
#include <vector>

const int PLAYER_NUM_MAX = 4;

class PlayerManager
{
public:
	PlayerManager(int);
	~PlayerManager();

	void Update();					//更新
	void AddPlayerTank(Player*);	//無人戦車の追加

private:
	std::vector<Player*> tankList;			//無人戦車のリスト
	int playerNum;							//参加人数
	int playerPadAry[PLAYER_NUM_MAX];		//プレイヤーの登録パッド
	bool playerActiveAry[PLAYER_NUM_MAX];	//プレイヤー操作、有効無効
	int nextActive;							//次に有効になるプレイヤー
	
	bool CheckActive();						//操作を有効にするかどうか
	void PlayerActive();					//操作を有効に
};