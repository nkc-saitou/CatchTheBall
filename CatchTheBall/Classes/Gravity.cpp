#include "Gravity.h"

/////////////////////////////////////////////////////
//����			:�������������I�u�W�F�N�g�̍ŏ���Y���W
//�߂�l		:�Ȃ�
//����			:�l�̏�����
/////////////////////////////////////////////////////
Gravity::Gravity(int startY)
{
	//�������W
	y = startY;

	//������
	y_prev = y;
	y_temp = 0;
}

/////////////////////////////////////////////////////
//����			:�Ȃ�
//�߂�l		:�Ȃ�
//����			:��������
/////////////////////////////////////////////////////
void Gravity::ObjGravity()
{
	if (y < 360)
	{
		//Verlet�@
		//http://d.hatena.ne.jp/Gemma/20080517/1211010942
		y_temp = y;
		y += (y - y_prev) + 1;
		y_prev = y_temp;

		//���̈ʒu�ɖ߂��Ă�����ĂуW�����v�ł���悤�ɂ���
		if (y >= 360)
		{
			y = 360;
		}
	}
}