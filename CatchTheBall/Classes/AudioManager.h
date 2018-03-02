#pragma once

#include "DxLib.h"
#include "Singleton.h"
#include <vector>
using namespace std;

// BGMの種類
typedef enum
{
	// BGMの列挙
	BGM_Menu,   // 0
	BGM_Game,  // 1

} bgmType;

// SEの種類
typedef enum
{
	// SEの列挙
	SE_Select  // 0

} seType;

class AudioManager : public Singleton <AudioManager>
{
public:
	// インスタンスの取得
	static AudioManager* getInstance();
	// BGM, SEのリスト
	vector<int> bgmSounds;
	vector<int> seSounds;
	// 現在のBGM
	static int bgm;

	// 読み込み
	void loadFiles();
	// BGM, SE登録
	int setBGM(int sHandle);
	int setSE(int sHandle);
	// 再生
	void playSE(seType typeNum);
	// 停止
	void stopSound(int sNum);
	// BGMの再生
	void playBGM(bgmType typeNum);
	// 音量のフェード
    void VolumeFade(int volume);

private:
	AudioManager(void);
	~AudioManager(void);

	static AudioManager* Instance;
};