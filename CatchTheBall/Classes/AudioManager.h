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

	// ���݂�BGM
	static string bgm;
	// �Đ�
	void playSE(string typeNum);
	// ��~
	void stopSound(string sNum);
	// BGM�̍Đ�
	void playBGM(string typeNum);
	// ���ʂ̃t�F�[�h
    void VolumeFade(int volume);
};