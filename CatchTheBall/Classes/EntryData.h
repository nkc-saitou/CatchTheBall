#pragma once

class EntryData {

	static const int MAX_ENTRY = 4;

	static int entryData[MAX_ENTRY];

	static int entryCount;

public:

	//エントリー情報を削除する
	static void ClearEntry();

	//コントローラーとプレイヤー番号を紐づける
	//戻り値はプレイヤー番号、失敗時は-1
	static int Entry(int joystickNum);

	//コントローラーを取得する
	//戻り値はコントローラー番号、失敗時は-1
	static int GetController(int playerNum);

	//現在エントリーしている数を取得
	static int GetEntryCount() { return entryCount; }
};