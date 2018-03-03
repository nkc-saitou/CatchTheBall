#pragma once

#include "DxLib.h"
#include "Singleton.h"
#include <vector>
using namespace std;

#define TITLE_BGM "bgm_maoudamashii_8bit02.mp3"
#define GAME_BGM "bgm_maoudamashii_8bit13.mp3"
#define SE_MOVE "se_maoudamashii_se_syber02.ogg"
#define SE_SHOT "se_maoudamashii_battle18.mp3"
#define SE_SELECT "se_maoudamashii_retro03.mp3"
#define SE_DESTROY "se_maoudamashii_retro12.mp3"

class AudioManager : public Singleton <AudioManager>
{
public:
	AudioManager();
	~AudioManager();

	// 現在のBGM
	static string bgm;
	// 再生
	void playSE(string typeNum);
	// 停止
	void stopSound(string sNum);
	// BGMの再生
	void playBGM(string typeNum);
	// 音量のフェード
    void VolumeFade(int volume);
};