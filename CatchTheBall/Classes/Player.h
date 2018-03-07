#pragma once

#include "Object.h"

enum PlayerState {
	Wait,
	Move,
	Shot,
	Dead
};

class Player : public Object
{
public:
	Player();
	Player(float x, float y, int order = 0);
	~Player();

	void Update();		//XV
	//void Draw();		//•`‰æ

private:
	void MoveAction();	//ˆÚ“®
	void ShotAction();	//ËŒ‚
	void DeadAction();	//€–S

	PlayerState state;	//ó‘Ô
};