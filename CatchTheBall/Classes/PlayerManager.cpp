#include "PlayerManager.h"
#include "Camera.h"

PlayerManager::PlayerManager(int num)
{
	playerNum = num;	//�v���C�l��
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
//	�X�V
//---------------------------------------------------------
void PlayerManager::Update()
{
	if (isFreeze || CheckFull()) return;

	vector<Player*> canActivePlayer;

	//�J�����ɓ����Ă��ēo�^����Ă��Ȃ����̂𒊏o
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

		//��ԍ�����v���C���[�𑀍�\��
		Player *nearTank = nullptr;
		float x;
		for (auto item : canActivePlayer) {
			if (nearTank == nullptr || item->PositionX() < x) {
				nearTank = item;
			}
			x = nearTank->PositionX();
		}

		//�z�Ɋ��蓖�Ă�
		PlayerActive(GetNextPlayer(), nearTank);

		//�v���C���[���폜
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
//	���l��Ԃ̒ǉ�
//---------------------------------------------------------
void PlayerManager::AddPlayerTank(Player* player)
{
	tankList.push_back(player);
}
//---------------------------------------------------------
//	���l��Ԃ̍폜
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
// �����L���ɂ��邩�ǂ���
//---------------------------------------------------------
bool PlayerManager::CheckFull()
{
	for (int i = 0; i < playerNum; i++) {
		if (!activePlayer[i]) return false;
	}
	
	return true;
}
//---------------------------------------------------------
//	�����L����
//---------------------------------------------------------
void PlayerManager::PlayerActive(int playerNum, Player *player)
{
	if (playerNum < 0 || playerNum >= PlayerManager::playerNum) return;
	if (activePlayer[playerNum]) return;

	//��������蓖�Ă�
	activePlayer[playerNum] = player;
	activePlayer[playerNum]->SetPadNo(playerNum);
}

void PlayerManager::PlayerNonActive(int playerNum) {

	if (!activePlayer[playerNum]) return;

	//����𖳌��ɂ�����
	//activePlayer[playerNum]->SetPadNo(-1);
	activePlayer[playerNum] = nullptr;
}

int PlayerManager::GetNextPlayer() {

	auto next = playerStock[0];

	//���Ɉړ�
	for (int i = 1; i < PlayerManager::playerNum; i++) {
		playerStock[i - 1] = playerStock[i];
	}
	playerStock[PlayerManager::playerNum - 1] = next;
	
	return next;
}