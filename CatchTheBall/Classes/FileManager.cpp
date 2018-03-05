#include "FileManager.h"
#include "DxLib.h"
#include "EffekseerForDXLib.h"
#include "FileList.h"

FileManager::FileManager() { }
FileManager::~FileManager() { }

//---------------------------------------------------------
//	必要ファイルの一括読み込み
//---------------------------------------------------------
void FileManager::Initialize(eScene scene)
{
	return;

	switch (scene)
	{
	case eScene_Title:
		for (auto file : UseFile_Title) {
			LoadFile(file);
		}
		for (auto dFile : UseDivFile_Title) {
			LoadFile(dFile.name, dFile.numAll, dFile.numX, dFile.numY, dFile.sizeX, dFile.sizeY);
		}
		break;

	case eScene_Config:

		break;
		
	case eScene_Game:
		for (auto file : UseFile_Game) {
			LoadFile(file);
		}
		for (auto dFile : UseDivFile_Game) {
			LoadFile(dFile.name, dFile.numAll, dFile.numX, dFile.numY, dFile.sizeX, dFile.sizeY);
		}
		break;
	}
}
//---------------------------------------------------------
//	データの解放
//---------------------------------------------------------
void FileManager::Finalize()
{
	InitGraph();
	InitSoundMem();
	fileHandleMap.clear();
}
//---------------------------------------------------------
//	Fileを渡す
//---------------------------------------------------------
int FileManager::GetFileHandle(string key)
{
	//空の場合
	if (fileHandleMap.empty()){
		return LoadFile(key);
	}

	//探索
	auto handle = fileHandleMap.find(key);
	//読み込んでない場合
	if (handle == fileHandleMap.end()) {
		return LoadFile(key);
	}
	return handle->second;
}
//---------------------------------------------------------
//	Fileの読み込み
//---------------------------------------------------------
int FileManager::LoadFile(string key)
{
	string directory, extension;
	int handle;

	//拡張子
	extension = GetExtension(key);

	//読み込み
	if (extension == "png" || extension == "jpg" || extension == "bmp") {
		//グラフィック
		directory = GRAPH_DIRECTORY + key;
		handle = LoadGraph(directory.c_str());
	}
	if (extension == "mp3" || extension == "wave" || extension == "ogg") {
		//オーディオ
		directory = AUDIO_DIRECTORY + key;
		handle = LoadSoundMem(directory.c_str());
	}
	else if (extension == "efk") {
		//エフェクト
		directory = EFFECT_DIRECTORY + key;
		handle = LoadEffekseerEffect(directory.c_str());
	}

	//保存
	fileHandleMap.emplace(key, handle);
	return handle;
}
//---------------------------------------------------------
//	ファイルの分割読み込み
//---------------------------------------------------------
void FileManager::LoadFile(string file, int numAll, int numX, int numY, int sizeX, int sizeY)
{
	const int NUM_ALL_MAX = 64;	//分割数の最大
	string directory = GRAPH_DIRECTORY + file;
	int graphArr[NUM_ALL_MAX];

	//読み込み
	LoadDivGraph(directory.c_str(), numAll, numX, numY, sizeX, sizeY, graphArr);

	//保存
	string key = GetFileName(file + "_");
	for (int i = 0; i < numAll; i++) {
		fileHandleMap.emplace(key + to_string(i), graphArr[i]);
	}
}
//---------------------------------------------------------
//	拡張子の抽出
//---------------------------------------------------------
string FileManager::GetExtension(string file)
{
	if (file.find(".")) return "";

	file.erase(file.begin(), file.begin() + (int)file.find(".") + 1);
	return file;
}
//---------------------------------------------------------
//	拡張子の排除
//---------------------------------------------------------
string FileManager::GetFileName(string file)
{
	if (file.find(".")) return "";

	file.erase(file.begin() + (int)file.find(".") + 1, file.end());
	return file;
}