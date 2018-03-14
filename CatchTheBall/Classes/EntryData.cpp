#include "EntryData.h"

int EntryData::entryData[MAX_ENTRY];
int EntryData::entryCount;

void EntryData::ClearEntry() {

	entryCount = 0;

	for (int i = 0; i < MAX_ENTRY; i++) {
		entryData[i] = -1;
	}
}

int EntryData::Entry(int joystickNum) {

	if (entryCount >= MAX_ENTRY) return -1;

	for (int i = 0; i < entryCount; i++) {
		//すでにエントリーしていた場合はそのプレイヤー番号を返す
		if (entryData[i] == joystickNum) return i;
	}

	//エントリーする
	entryData[entryCount] = joystickNum;

	auto playerNum = entryCount++;
	return playerNum;
}

int EntryData::GetController(int playerNum) {

	if (playerNum < 0 || playerNum >= MAX_ENTRY) return -1;
	return entryData[playerNum];
}