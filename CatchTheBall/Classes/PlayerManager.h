#pragma once

#include "Player.h"
#include <vector>

const int PLAYER_NUM_MAX = 4;

class PlayerManager {
public:

	bool isFreeze;					//�X�V���邩�ǂ���

	PlayerManager(int);
	~PlayerManager();

	void Reset();					//���������ׂă��Z�b�g
	void Update();					//�X�V
	void AddPlayerTank(Player*);	//���l��Ԃ̒ǉ�
	void RemovePlayerTank(Player*);	//���l��Ԃ̍폜

private:

	Player *activePlayer[PLAYER_NUM_MAX];

	std::vector<Player*> tankList;			//���l��Ԃ̃��X�g
	int playerNum;							//�Q���l��
	int playerStock[PLAYER_NUM_MAX];
	int nextActive;							//���ɗL���ɂȂ�v���C���[

	bool CheckFull();						//�����L���ɂ��邩�ǂ���
	void PlayerActive(int playerNum, Player *player);					//�����L����
	void PlayerNonActive(int playerNum);
	int GetNextPlayer();
};