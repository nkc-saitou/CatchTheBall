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
//	�f�[�^�̉��
//---------------------------------------------------------
void FileManager::ResetData()
{
	InitGraph();
	fileHandleMap.clear();
}
//---------------------------------------------------------
//	File��n��
//---------------------------------------------------------
int FileManager::GetFileHandle(std::string key, FileType type)
{
	//��̏ꍇ
	if (fileHandleMap.begin() == fileHandleMap.end()){
		return LoadFile(key, type);
	}

	//�T��
	auto handle = fileHandleMap.find(key);
	//�ǂݍ���łȂ��ꍇ
	if (handle == fileHandleMap.end()) {
		return LoadFile(key, type);
	}
	return handle->second;
}
//---------------------------------------------------------
//	File�̓ǂݍ���
//---------------------------------------------------------
int FileManager::LoadFile(std::string key, FileType type)
{
	std::string directory;
	int handle;

	//�ǂݍ���
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

	//�ۑ�
	fileHandleMap.emplace(key, handle);
	return handle;
}