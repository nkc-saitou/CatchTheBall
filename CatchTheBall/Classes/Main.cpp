#include "DxLib.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{

	//�c�w���C�u��������������
	if (DxLib_Init() == -1)
	{
		return -1;
	}

	//�c�w���C�u�����I������
	DxLib_End();

	return 0;
}