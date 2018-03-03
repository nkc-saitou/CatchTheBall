#include "CollisionManager.h"

void CollisionManager::HitCollision()
{
	//getType 0 -> Square,
	//        1 -> Circle
	for (unsigned int i = 0; i < collision.size(); i++)
	{
		for (unsigned int j = i + 1; j < collision.size(); j++)
		{
			//��`���m
			if (collision[i]->getType() == 0 && collision[j]->getType() == 0) 
			{
				if (HitBoxToBox(*collision[i], *collision[j]))
				{
					collision[i]->onHit(*collision[j]);
					collision[j]->onHit(*collision[i]);
				}
			}
			//�~�`���m
			else if (collision[i]->getType() == 1 && collision[j]->getType() == 1)
			{
				if ((HitCircleToCircle(*collision[i], *collision[j])))
				{
					collision[i]->onHit(*collision[j]);
					collision[j]->onHit(*collision[i]);
				}
			}
			//�~�`�Ƌ�`
			else 
			{
				if (collision[i]->getType() != 1)
				{
					if (HitCircleToBox(*collision[j], *collision[i]))
					{
						collision[i]->onHit(*collision[j]);
						collision[j]->onHit(*collision[i]);
					}
				}
				else
				{
					if (HitCircleToBox(*collision[i], *collision[j]))
					{
						collision[i]->onHit(*collision[j]);
						collision[j]->onHit(*collision[i]);
					}
				}
			}
		}
	}
}

void CollisionManager::hit(Collision* a,Collision* b)
{
	a->onHit(*b);
	b->onHit(*a);
}

//------------------------------
//��`���m�̂����蔻��
//------------------------------
bool CollisionManager::HitBoxToBox(Collision firstCollision,Collision secondCollision)
{
	//���W
	float firstPosX = firstCollision.getObject()->PositionX() + firstCollision.getX();
	float firstPosY = firstCollision.getObject()->PositionY() + firstCollision.getY();

	float secondPosX = secondCollision.getObject()->PositionX() + secondCollision.getX();
	float secondPosY = secondCollision.getObject()->PositionY() + secondCollision.getY();

	if ((firstPosX - firstCollision.getSizeX() / 2) < (secondPosX + secondCollision.getSizeX() / 2) &&
		(firstPosX + firstCollision.getSizeX() / 2) > (secondPosX - secondCollision.getSizeX() / 2) &&
		(firstPosY - firstCollision.getSizeY() / 2) < (secondPosY + secondCollision.getSizeY() / 2) &&
		(firstPosY + firstCollision.getSizeY() / 2) > (secondPosY - secondCollision.getSizeY() / 2))
	{
		return true;
	}
	else
	{
		return false;
	}
}

//------------------------------
//�~�`���m�̂����蔻��
//------------------------------
bool CollisionManager::HitCircleToCircle(Collision firstCollision, Collision secondCollision)
{
	//���W
	float firstPosX = firstCollision.getObject()->PositionX() + firstCollision.getX();
	float firstPosY = firstCollision.getObject()->PositionY() + firstCollision.getY();

	float secondPosX = secondCollision.getObject()->PositionX() + secondCollision.getX();
	float secondPosY = secondCollision.getObject()->PositionY() + secondCollision.getY();

	//�~���m�̂����蔻��
	if ((secondPosX - firstPosX) * (secondPosX - firstPosX) + (secondPosY - firstPosY) * (secondPosY - firstPosY)
		<= (firstCollision.getSizeX() / 2 + secondCollision.getSizeX() / 2) * (firstCollision.getSizeX() / 2 + secondCollision.getSizeX() / 2)) 
	{
		return true;
	}
	else
	{
		return false;
	}
}

//------------------------------
//�~�`�Ƌ�`�̂����蔻��
//------------------------------
bool CollisionManager::HitCircleToBox(Collision firstCollision, Collision secondCollision)
{
	//----------------------------------------
	//first  -> Circle
	//second -> Box
	//----------------------------------------

	//���W
	float firstPosX = firstCollision.getObject()->PositionX() + firstCollision.getX();
	float firstPosY = firstCollision.getObject()->PositionY() + firstCollision.getY();

	float secondPosX = secondCollision.getObject()->PositionX() + secondCollision.getX();
	float secondPosY = secondCollision.getObject()->PositionY() + secondCollision.getY();

	float pX[2] = 
	{
		secondPosX - secondCollision.getSizeX() / 2, //��
		secondPosX + secondCollision.getSizeX() / 2  //�E
	};

	float pY[2] =
	{
		secondPosY - secondCollision.getSizeY() / 2, //��
		secondPosY + secondCollision.getSizeY() / 2  //��
	};

	//�e�ӂɐG��Ă��邩�ǂ���
	if ((firstPosX > pX[0] && firstPosX < pX[1]) || (firstPosY > pY[0] && firstPosY < pY[1])) 
	{
		if ((firstPosX - firstCollision.getSizeX() / 2) < (pX[1]) &&
			(firstPosX + firstCollision.getSizeX() / 2) > (pX[0]) &&
			(firstPosX - firstCollision.getSizeX() / 2) < (pY[1]) &&
			(firstPosX + firstCollision.getSizeX() / 2) > (pY[0]))
		{
			return true;
		}
	}
	//�e���_�ɐG��Ă��邩�ǂ���
	else
	{
		for (int y = 0; y < sizeof(pY); y++)
		{
			for (int x = 0; x < sizeof(pX); x++)
			{
				if ((pX[x] - firstPosX) * (pX[x] - firstPosX) + (pY[y] - firstPosY) * (pY[y] - firstPosY)
					<= (firstCollision.getSizeX() / 2) * (firstCollision.getSizeX() / 2))
				{
					//�������Ă����ď�����Ԃ�
					return true;
					break;
				}
			}
		}
	}

	return false;

}


