#include "AudioManager.h"
#include "FileManager.h"

AudioManager::AudioManager(void)
{
	bgm = GAME_BGM;
}
AudioManager::~AudioManager(void)
{

}

// �T�E���h�֘A�N���X�̃����o�֐��̋L�q
// AudioManager�N���X�̃����o�ϐ��̎���
string AudioManager::bgm;

// SE�̍Đ�
void AudioManager::playSE(string pass) 
{
	// �����ɑΉ�����SE���Đ�
	PlaySoundMem(FileManager::Instance()->GetFileHandle(pass), DX_PLAYTYPE_BACK);
}

// SE�̒�~
void AudioManager::stopSound(string pass) 
{
	// �����ɑΉ�����SE���~
	StopSoundMem(FileManager::Instance()->GetFileHandle(pass));
}

// BGM�̍Đ�
void AudioManager::playBGM(string pass)
{
	// �Đ�����T�E���h���擾
	string newbgm = pass;
	// ���݂�BGM�Ɠ����Ȃ炻�̂܂�
	if (bgm == newbgm) {
		return;
	}
	// BGM�̒�~
	StopSoundMem(FileManager::Instance()->GetFileHandle(bgm));
	bgm = newbgm;
	// BGM�̓��[�v�Đ�
	PlaySoundMem(FileManager::Instance()->GetFileHandle(bgm), DX_PLAYTYPE_LOOP);
}

// ���ʂ̃t�F�[�h
void AudioManager::VolumeFade(int volume)
{
	// �����ɂ���ĉ��ʒ���
	ChangeVolumeSoundMem(255 - volume, FileManager::Instance()->GetFileHandle(bgm));
}