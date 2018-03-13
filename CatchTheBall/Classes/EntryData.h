#pragma once

class EntryData {

	static const int MAX_ENTRY = 4;

	static int entryData[MAX_ENTRY];

	static int entryCount;

public:

	//�G���g���[�����폜����
	static void ClearEntry();

	//�R���g���[���[�ƃv���C���[�ԍ���R�Â���
	//�߂�l�̓v���C���[�ԍ��A���s����-1
	static int Entry(int joystickNum);

	//�R���g���[���[���擾����
	//�߂�l�̓R���g���[���[�ԍ��A���s����-1
	static int GetController(int playerNum);

	//���݃G���g���[���Ă��鐔���擾
	static int GetEntryCount() { return entryCount; }
};