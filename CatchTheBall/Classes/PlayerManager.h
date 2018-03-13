#pragma once

#include "Player.h"
#include <vector>

const int PLAYER_NUM_MAX = 4;

class PlayerManager {
public:
	PlayerManager(int);
	~PlayerManager();

	void Update();					//更新
	void AddPlayerTank(Player*);	//無人戦車の追加
	void RemovePlayerTank(Player*);	//無人戦車の削除

private:

	Player *activePlayer[PLAYER_NUM_MAX];

	std::vector<Player*> tankList;			//無人戦車のリスト
	int playerNum;							//参加人数
	int playerStock[PLAYER_NUM_MAX];
	int nextActive;							//次に有効になるプレイヤー

	bool CheckFull();						//操作を有効にするかどうか
	void PlayerActive(int playerNum, Player *player);					//操作を有効に
	void PlayerNonActive(int playerNum);
	int GetNextPlayer();
}