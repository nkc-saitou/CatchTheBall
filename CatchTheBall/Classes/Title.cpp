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
	isMovingScene = false;

	LoadFile();

	//BGM�Đ�
	AudioManager::Instance()->playBGM(TITLE_BGM);
	//Object����
	auto backGround = new Label(FileManager::Instance()->GetFileHandle(TITLE_IMAGE), 0, 0);
	auto title = new Label(FileManager::Instance()->GetFileHandle(TITLE_LOGO), (SCREEN_WIDTH - 525) / 2, 30);
	auto startText = new Label(FileManager::Instance()->GetFileHandle(START_TEXT), (SCREEN_WIDTH - 320) / 2, 380);
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
	//�V�[�����x���Ŏ���
	if (Input::Instance()->PadAnyButtonDown(MOVE_SCENE_PAD)
		|| Input::Instance()->ButtonDown(MOVE_SCENE_KEY)) {

		//printfDx("Button1\n");
		Scene::SceneFade(Scene::SELECT);
	}

	ObjectManager::Instance()->Update();
}

void Title::Draw()
{
	ObjectManager::Instance()->Draw();
}