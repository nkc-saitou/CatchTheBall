#pragma once

#include "Player.h"
#include <vector>

const int PLAYER_NUM_MAX = 4;

class PlayerManager
{
public:
	PlayerManager(int);
	~PlayerManager();

	void Update();					//�X�V
	void AddPlayerTank(Player*);	//���l��Ԃ̒ǉ�

private:
	std::vector<Player*> tankList;			//���l��Ԃ̃��X�g
	int playerNum;							//�Q���l��
	int playerPadAry[PLAYER_NUM_MAX];		//�v���C���[�̓o�^�p�b�h
	bool playerActiveAry[PLAYER_NUM_MAX];	//�v���C���[����A�L������
	int nextActive;							//���ɗL���ɂȂ�v���C���[
	
	bool CheckActive();						//�����L���ɂ��邩�ǂ���
	void PlayerActive();					//�����L����
};