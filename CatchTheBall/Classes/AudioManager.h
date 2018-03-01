#pragma once

#include "DxLib.h"
#include "Singleton.h"
#include <vector>
using namespace std;

// BGM�̎��
typedef enum
{
	// BGM�̗�
	BGM_Menu,   // 0
	BGM_Game,  // 1

} bgmType;

// SE�̎��
typedef enum
{
	// SE�̗�
	SE_Select  // 0

} seType;

class AudioManager : public Singleton <AudioManager>
{
public:
	// �C���X�^���X�̎擾
	static AudioManager* getInstance();
	// BGM, SE�̃��X�g
	vector<int> bgmSounds;
	vector<int> seSounds;
	// ���݂�BGM
	static int bgm;

	// �ǂݍ���
	void loadFiles();
	// BGM, SE�o�^
	int setBGM(int sHandle);
	int setSE(int sHandle);
	// �Đ�
	void playSE(seType typeNum);
	// ��~
	void stopSound(int sNum);
	// BGM�̍Đ�
	void playBGM(bgmType typeNum);
	// ���ʂ̃t�F�[�h
    void VolumeFade(int volume);

private:
	AudioManager(void);
	~AudioManager(void);

	static AudioManager* Instance;
};