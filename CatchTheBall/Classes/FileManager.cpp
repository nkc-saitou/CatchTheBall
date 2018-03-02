#include "FileManager.h"
#include "DxLib.h"

FileManager::FileManager()
{

}
FileManager::~FileManager()
{
	ResetData();
}
//---------------------------------------------------------
//	データの解放
//---------------------------------------------------------
void FileManager::ResetData()
{
	InitGraph();
	fileHandleMap.clear();
}
//---------------------------------------------------------
//	Fileを渡す
//---------------------------------------------------------
int FileManager::GetFileHandle(std::string key, FileType type)
{
	//空の場合
	if (fileHandleMap.begin() == fileHandleMap.end()){
		return LoadFile(key, type);
	}

	//探索
	auto handle = fileHandleMap.find(key);
	//読み込んでない場合
	if (handle == fileHandleMap.end()) {
		return LoadFile(key, type);
	}
	return handle->second;
}
//---------------------------------------------------------
//	Fileの読み込み
//---------------------------------------------------------
int FileManager::LoadFile(std::string key, FileType type)
{
	std::string directory;
	int handle;

	//読み込み
	switch (type) {
	case Graph:
		directory = GRAPH_DIRECTORY + key; 
		handle = LoadGraph(directory.c_str());
		break;

	case Audio:
		directory = AUDIO_DIRECTORY + key; 
		handle = LoadSoundMem(directory.c_str());
		break;
	}

	//保存
	fileHandleMap.emplace(key, handle);
	return handle;
}