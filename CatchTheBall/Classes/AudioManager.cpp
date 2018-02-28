#include "AudioManager.h"

AudioManager::AudioManager(void)
{
	this->loadFiles();
}
AudioManager::~AudioManager(void)
{
}

// シングルトンのためのゲッター
AudioManager* AudioManager::getInstance()
{
	// インスタンスが無ければ新しく生成
	if (Instance == 0) {
		Instance = new AudioManager();
	}
	return Instance;
}

AudioManager* AudioManager::Instance = new AudioManager();

// サウンド関連クラスのメンバ関数の記述
// AudioManagerクラスのメンバ変数の実態
vector<int> BGMSounds = AudioManager::getInstance()->bgmSounds;
vector<int> SESounds = AudioManager::getInstance()->seSounds;
int AudioManager::bgm = 0;

// BGMの登録
int AudioManager::setBGM(int sHandle) 
{
	// 曲のリストの末尾に追加
	BGMSounds.push_back(sHandle);
	return (BGMSounds.size() - 1);
}

// SEの登録
int AudioManager::setSE(int sHandle)
{
	// 曲のリストの末尾に追加
	SESounds.push_back(sHandle);
	return (SESounds.size() - 1);
}

// SEの再生
void AudioManager::playSE(seType typeNum) 
{
	// 引数に対応したSEを再生
	PlaySoundMem(SESounds.at(typeNum), DX_PLAYTYPE_BACK);
}

// SEの停止
void AudioManager::stopSound(int sNum) 
{
	// 引数に対応したSEを停止
	StopSoundMem(SESounds.at(sNum));
}

// BGMの再生
void AudioManager::playBGM(bgmType typeNum)
{
	// 再生するサウンドを取得
	int newbgm = BGMSounds.at(typeNum);
	// 現在のBGMと同じならそのまま
	if (bgm == newbgm) {
		return;
	}
	// BGMの停止
	StopSoundMem(bgm);
	bgm = newbgm;
	// BGMはループ再生
	PlaySoundMem(bgm, DX_PLAYTYPE_LOOP);
}

// 音量のフェード
void AudioManager::VolumeFade(int volume)
{
	// 引数によって音量調節
	ChangeVolumeSoundMem(255 - volume, bgm);
}

// サウンドファイルの読み込み
void AudioManager::loadFiles()
{
	int handle;

	// --------------------------------------------------BGM--------------------------------------------------------
	handle = LoadSoundMem("Resources\\Audio\\game_maoudamashii_5_town18.mp3");
	// setBGM 関数で vector に格納
	AudioManager::setBGM(handle); // BGM_Menu

	handle = LoadSoundMem("Resources\\Audio\\game_maoudamashii_1_battle25.mp3");
	// setBGM 関数で vector に格納
	AudioManager::setBGM(handle); // BGM_Game
	// ----------------------------------------------------------------------------------------------------------------


	// ---------------------------------------------------SE----------------------------------------------------------
	handle = LoadSoundMem("Resources\\Audio\\se_maoudamashii_system27.mp3");
	// setSE 関数で vector に格納
	AudioManager::setSE(handle); // SE_Select
	// ----------------------------------------------------------------------------------------------------------------
}