#include "DxLib.h"
#include "Title.h"
#include "Input.h"
#include "AudioManager.h"
#include "LoadFileList.h"
#include "FileManager.h"
#include "ObjectManager.h"
#include "Label.h"
#include "Camera.h"

Title::Title()
{
	LoadFile();

	//BGM�Đ�
	AudioManager::Instance()->playBGM(TITLE_BGM);
	//Object����
	auto backGround = new Label(FileManager::Instance()->GetFileHandle(TITLE_IMAGE), 0, 0);
	auto Title = new Label(FileManager::Instance()->GetFileHandle(TITLE_TEXT), 0, 0);
	auto PlayerImage = new Label(FileManager::Instance()->GetFileHandle(PLAYER_IMAGE), 280, 288);
	auto camera = new Camera(0, 0);
}

Title::~Title()
{
	UnLoadFile();
}

// �^�C�g���Ɏg�p����t�@�C���̓ǂݍ���
void Title::LoadFile()
{
	for (char* file : UseFile_Title) {
		FileManager::Instance()->LoadFile(file);
	}
	for (DivFile dFile : UseDivFile_Title) {
		FileManager::Instance()->LoadFile(dFile.name, dFile.numAll, dFile.numX, dFile.numY, dFile.sizeX, dFile.sizeY);
	}
}

//�^�C�g���Ŏg�p�����t�@�C���̔j��
void Title::UnLoadFile()
{
	FileManager::Instance()->Initialize();
}

void Title::Initialize()
{
	
}

void Title::Update()
{
	ObjectManager::Instance()->Update();
}

void Title::Draw()
{
	ObjectManager::Instance()->Draw();

	//DrawGraph(cloudPosX[0], 100, FileManager::Instance()->GetFileHandle(CLOUD_IMAGE), TRUE);
	//DrawGraph(cloudPosX[1], 40, FileManager::Instance()->GetFileHandle(CLOUD_IMAGE), TRUE);
	//DrawGraph(cloudPosX[2], 160, FileManager::Instance()->GetFileHandle(CLOUD_IMAGE), TRUE);

	//DrawString(230, 410, "��", GetColor(0, 0, 0));
}