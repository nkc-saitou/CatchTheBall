#include "FileManager.h"
#include "DxLib.h"
#include "FileList.h"
#include "EffekseerForDXLib.h"

FileManager::FileManager()
{
}
FileManager::~FileManager()
{
	ResetData();
}
//---------------------------------------------------------
//	�K�v�t�@�C���̈ꊇ�ǂݍ���
//---------------------------------------------------------
void FileManager::SetData(eScene scene)
{
	/*for (string file : UseFile_Title) {
		LoadFile(file);
	}*/
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
int FileManager::GetFileHandle(string key)
{
	//��̏ꍇ
	if (fileHandleMap.empty()){
		return LoadFile(key);
	}

	//�T��
	auto handle = fileHandleMap.find(key);
	//�ǂݍ���łȂ��ꍇ
	if (handle == fileHandleMap.end()) {
		return LoadFile(key);
	}
	return handle->second;
}
//---------------------------------------------------------
//	File�̓ǂݍ���
//---------------------------------------------------------
int FileManager::LoadFile(string key)
{
	string directory, extension;
	int handle;

	//�g���q
	extension = GetExtension(key);

	//�ǂݍ���
	if (extension == "png" || extension == "jpg" || extension == "bmp") {
		//�O���t�B�b�N
		directory = GRAPH_DIRECTORY + key;
		handle = LoadGraph(directory.c_str());
	} else
	if (extension == "mp3" || extension == "wave" || extension == "ogg") {
		//�I�[�f�B�I
		directory = AUDIO_DIRECTORY + key;
		handle = LoadSoundMem(directory.c_str());
	}
	else if (extension == "efk") {
		//�G�t�F�N�g
		directory = EFFECT_DIRECTORY + key;
		handle = LoadEffekseerEffect(directory.c_str());
	}

	//�ۑ�
	fileHandleMap.emplace(key, handle);
	return handle;
}
//---------------------------------------------------------
//	�t�@�C���̕����ǂݍ���
//---------------------------------------------------------
void FileManager::LoadFile(string key, int numAll, int numX, int numY, int sizeX, int sizeY)
{
	string directory = GRAPH_DIRECTORY + key;
	int graphArr[sizeof(numAll)];
	LoadDivGraph(directory.c_str(), numAll, numX, numY, sizeX, sizeY, graphArr);

	for (int i = 0; i < numAll; i++) {

	}
}
//---------------------------------------------------------
//	�g���q�̒��o
//---------------------------------------------------------
string FileManager::GetExtension(string file)
{
	file.erase(file.begin(), file.begin() + (int)file.find(".") + 1);
	return file;
}