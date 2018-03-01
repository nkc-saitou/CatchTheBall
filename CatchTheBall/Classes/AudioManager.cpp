#include "AudioManager.h"

AudioManager::AudioManager(void)
{
	this->loadFiles();
}
AudioManager::~AudioManager(void)
{
}

// �V���O���g���̂��߂̃Q�b�^�[
AudioManager* AudioManager::getInstance()
{
	// �C���X�^���X��������ΐV��������
	if (Instance == 0) {
		Instance = new AudioManager();
	}
	return Instance;
}

AudioManager* AudioManager::Instance = new AudioManager();

// �T�E���h�֘A�N���X�̃����o�֐��̋L�q
// AudioManager�N���X�̃����o�ϐ��̎���
vector<int> BGMSounds = AudioManager::getInstance()->bgmSounds;
vector<int> SESounds = AudioManager::getInstance()->seSounds;
int AudioManager::bgm = 0;

// BGM�̓o�^
int AudioManager::setBGM(int sHandle) 
{
	// �Ȃ̃��X�g�̖����ɒǉ�
	BGMSounds.push_back(sHandle);
	return (BGMSounds.size() - 1);
}

// SE�̓o�^
int AudioManager::setSE(int sHandle)
{
	// �Ȃ̃��X�g�̖����ɒǉ�
	SESounds.push_back(sHandle);
	return (SESounds.size() - 1);
}

// SE�̍Đ�
void AudioManager::playSE(seType typeNum) 
{
	// �����ɑΉ�����SE���Đ�
	PlaySoundMem(SESounds.at(typeNum), DX_PLAYTYPE_BACK);
}

// SE�̒�~
void AudioManager::stopSound(int sNum) 
{
	// �����ɑΉ�����SE���~
	StopSoundMem(SESounds.at(sNum));
}

// BGM�̍Đ�
void AudioManager::playBGM(bgmType typeNum)
{
	// �Đ�����T�E���h���擾
	int newbgm = BGMSounds.at(typeNum);
	// ���݂�BGM�Ɠ����Ȃ炻�̂܂�
	if (bgm == newbgm) {
		return;
	}
	// BGM�̒�~
	StopSoundMem(bgm);
	bgm = newbgm;
	// BGM�̓��[�v�Đ�
	PlaySoundMem(bgm, DX_PLAYTYPE_LOOP);
}

// ���ʂ̃t�F�[�h
void AudioManager::VolumeFade(int volume)
{
	// �����ɂ���ĉ��ʒ���
	ChangeVolumeSoundMem(255 - volume, bgm);
}

// �T�E���h�t�@�C���̓ǂݍ���
void AudioManager::loadFiles()
{
	int handle;

	// --------------------------------------------------BGM--------------------------------------------------------
	handle = LoadSoundMem("Resources\\Audio\\game_maoudamashii_5_town18.mp3");
	// setBGM �֐��� vector �Ɋi�[
	AudioManager::setBGM(handle); // BGM_Menu

	handle = LoadSoundMem("Resources\\Audio\\game_maoudamashii_1_battle25.mp3");
	// setBGM �֐��� vector �Ɋi�[
	AudioManager::setBGM(handle); // BGM_Game
	// ----------------------------------------------------------------------------------------------------------------


	// ---------------------------------------------------SE----------------------------------------------------------
	handle = LoadSoundMem("Resources\\Audio\\se_maoudamashii_system27.mp3");
	// setSE �֐��� vector �Ɋi�[
	AudioManager::setSE(handle); // SE_Select
	// ----------------------------------------------------------------------------------------------------------------
}