#include "PlayerManager.h"
#include "Camera.h"

PlayerManager::PlayerManager(int num)
{
	playerNum = num;	//�v���C�l��
	nextActive = 0;		//���ɗL���ɂȂ�v���C���[
}
PlayerManager::~PlayerManager()
{

}
//---------------------------------------------------------
//	�X�V
//---------------------------------------------------------
void PlayerManager::Update()
{
	
}
//---------------------------------------------------------
//	���l��Ԃ̒ǉ�
//---------------------------------------------------------
void PlayerManager::AddPlayerTank(Player* player)
{
	tankList.push_back(player);
}
//---------------------------------------------------------
// �����L���ɂ��邩�ǂ���
//---------------------------------------------------------
bool PlayerManager::CheckActive()
{
	if (playerActiveAry[nextActive]) return false;
	
	return true;
}
//---------------------------------------------------------
//	�����L����
//---------------------------------------------------------
void PlayerManager::PlayerActive()
{

}