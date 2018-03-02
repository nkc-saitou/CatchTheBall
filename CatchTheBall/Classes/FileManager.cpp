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
//	ÉfÅ[É^ÇÃâï˙
//---------------------------------------------------------
void FileManager::ResetData()
{
	InitGraph();
	fileHandleMap.clear();
}
//---------------------------------------------------------
//	FileÇìnÇ∑
//---------------------------------------------------------
int FileManager::GetFileHandle(std::string key, FileType type)
{
	//ãÛÇÃèÍçá
	if (fileHandleMap.begin() == fileHandleMap.end()){
		return LoadFile(key, type);
	}

	//íTçı
	auto handle = fileHandleMap.find(key);
	//ì«Ç›çûÇÒÇ≈Ç»Ç¢èÍçá
	if (handle == fileHandleMap.end()) {
		return LoadFile(key, type);
	}
	return handle->second;
}
//---------------------------------------------------------
//	FileÇÃì«Ç›çûÇ›
//---------------------------------------------------------
int FileManager::LoadFile(std::string key, FileType type)
{
	std::string directory;
	int handle;

	//ì«Ç›çûÇ›
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

	//ï€ë∂
	fileHandleMap.emplace(key, handle);
	return handle;
}