#include "PlayerManager.h"
#include "Camera.h"

PlayerManager::PlayerManager(int num)
{
	playerNum = num;	//プレイ人数
	isFreeze = false;

	for (int i = 0; i < PLAYER_NUM_MAX; i++) {
		playerStock[i] = i;
	}

	for (auto item : activePlayer) {
		item = nullptr;
	}
}
PlayerManager::~PlayerManager()
{

}

void PlayerManager::Reset() {

	for (int i = 0; i < playerNum; i++) {
		playerStock[i] = i;
		PlayerNonActive(i);
	}


}
//---------------------------------------------------------
//	更新
//---------------------------------------------------------
void PlayerManager::Update()
{
	if (isFreeze || CheckFull()) return;

	vector<Player*> canActivePlayer;

	//カメラに入っていて登録されていないものを抽出
	for (auto item : tankList) {
		if (Camera::MainCamera->DrawCheck(item)) {

			auto flg = true;
			for (auto item2 : activePlayer) {
				if (item2 == item) {
					flg = false;
					break;
				}
			}

			if(flg) canActivePlayer.push_back(item);
		}
	}

	while (!canActivePlayer.empty() && !CheckFull()) {

		//一番左からプレイヤーを操作可能に
		Player *nearTank = nullptr;
		float x;
		for (auto item : canActivePlayer) {
			if (nearTank == nullptr || item->PositionX < x) {
				nearTank = item;
			}
			x = nearTank->PositionX();
		}

		//奴に割り当てる
		PlayerActive(GetNextPlayer(), nearTank);

		//プレイヤーを削除
		auto itr = canActivePlayer.begin();
		while (itr != canActivePlayer.end()) {
			if (*itr == nearTank) {
				itr = canActivePlayer.erase(itr);
				break;
			}
			else itr++;
		}
	}
}
//---------------------------------------------------------
//	無人戦車の追加
//---------------------------------------------------------
void PlayerManager::AddPlayerTank(Player* player)
{
	tankList.push_back(player);
}
//---------------------------------------------------------
//	無人戦車の削除
//---------------------------------------------------------
void PlayerManager::RemovePlayerTank(Player* player) {

	if (player == nullptr) return;
	if (tankList.empty()) return;

	auto itr = tankList.begin();
	while (itr != tankList.end()) {
		if (*itr == player) {
			itr = tankList.erase(itr);
			break;
		}
		else itr++;
	}
}
//---------------------------------------------------------
// 操作を有効にするかどうか
//---------------------------------------------------------
bool PlayerManager::CheckFull()
{
	for (int i = 0; i < playerNum; i++) {
		if (!activePlayer[i]) return false;
	}
	
	return true;
}
//---------------------------------------------------------
//	操作を有効に
//---------------------------------------------------------
void PlayerManager::PlayerActive(int playerNum, Player *player)
{
	if (playerNum < 0 || playerNum >= PlayerManager::playerNum) return;
	if (activePlayer[playerNum]) return;

	//操作を割り当てる
	activePlayer[playerNum] = player;
	activePlayer[playerNum]->SetPadNo(playerNum);
}

void PlayerManager::PlayerNonActive(int playerNum) {

	if (!activePlayer[playerNum]) return;

	//操作を無効にしたい
	//activePlayer[playerNum]->SetPadNo(-1);
	activePlayer[playerNum] = nullptr;
}

int PlayerManager::GetNextPlayer() {

	auto next = playerStock[0];

	//後ろに移動
	for (int i = 1; i < PlayerManager::playerNum; i++) {
		playerStock[i - 1] = playerStock[i];
	}
	playerStock[PlayerManager::playerNum - 1] = next;
	
	return next;
}