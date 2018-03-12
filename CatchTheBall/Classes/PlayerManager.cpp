#include "PlayerManager.h"
#include "Camera.h"

PlayerManager::PlayerManager(int num)
{
	playerNum = num;	//プレイ人数
	nextActive = 0;		//次に有効になるプレイヤー
}
PlayerManager::~PlayerManager()
{

}
//---------------------------------------------------------
//	更新
//---------------------------------------------------------
void PlayerManager::Update()
{
	
}
//---------------------------------------------------------
//	無人戦車の追加
//---------------------------------------------------------
void PlayerManager::AddPlayerTank(Player* player)
{
	tankList.push_back(player);
}
//---------------------------------------------------------
// 操作を有効にするかどうか
//---------------------------------------------------------
bool PlayerManager::CheckActive()
{
	if (playerActiveAry[nextActive]) return false;
	
	return true;
}
//---------------------------------------------------------
//	操作を有効に
//---------------------------------------------------------
void PlayerManager::PlayerActive()
{

}