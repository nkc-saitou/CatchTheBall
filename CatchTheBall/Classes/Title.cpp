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

	//BGM再生
	AudioManager::Instance()->playBGM(TITLE_BGM);
	//Object生成
	auto backGround = new Label(FileManager::Instance()->GetFileHandle(TITLE_IMAGE), 0, 0);
	auto title = new Label(FileManager::Instance()->GetFileHandle(TITLE_LOGO), (SCREEN_WIDTH - 525) / 2, 30);
	auto startText = new Label(FileManager::Instance()->GetFileHandle(START_TEXT), (SCREEN_WIDTH - 320) / 2, 380);
	auto camera = new Camera(0, 0);
}

Title::~Title()
{
	UnLoadFile();
}

// タイトルに使用するファイルの読み込み
void Title::LoadFile()
{
	for (char* file : UseFile_Title) {
		FileManager::Instance()->LoadFile(file);
	}
	for (DivFile dFile : UseDivFile_Title) {
		FileManager::Instance()->LoadFile(dFile.name, dFile.numAll, dFile.numX, dFile.numY, dFile.sizeX, dFile.sizeY);
	}
}

//タイトルで使用したファイルの破棄
void Title::UnLoadFile()
{
	FileManager::Instance()->Initialize();
}

void Title::Initialize()
{
	
}

void Title::Update()
{
	//シーンレベルで実装
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