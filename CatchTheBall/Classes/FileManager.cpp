#include "FileManager.h"
#include "DxLib.h"
#include "EffekseerForDXLib.h"
#include "FileList.h"

FileManager::FileManager() { }
FileManager::~FileManager() { }

//---------------------------------------------------------
//	�K�v�t�@�C���̈ꊇ�ǂݍ���
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
//	�f�[�^�̉��
//---------------------------------------------------------
void FileManager::Finalize()
{
	InitGraph();
	InitSoundMem();
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
	}
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
void FileManager::LoadFile(string file, int numAll, int numX, int numY, int sizeX, int sizeY)
{
	const int NUM_ALL_MAX = 64;	//�������̍ő�
	string directory = GRAPH_DIRECTORY + file;
	int graphArr[NUM_ALL_MAX];

	//�ǂݍ���
	LoadDivGraph(directory.c_str(), numAll, numX, numY, sizeX, sizeY, graphArr);

	//�ۑ�
	string key = GetFileName(file + "_");
	for (int i = 0; i < numAll; i++) {
		fileHandleMap.emplace(key + to_string(i), graphArr[i]);
	}
}
//---------------------------------------------------------
//	�g���q�̒��o
//---------------------------------------------------------
string FileManager::GetExtension(string file)
{
	if (file.find(".")) return "";

	file.erase(file.begin(), file.begin() + (int)file.find(".") + 1);
	return file;
}
//---------------------------------------------------------
//	�g���q�̔r��
//---------------------------------------------------------
string FileManager::GetFileName(string file)
{
	if (file.find(".")) return "";

	file.erase(file.begin() + (int)file.find(".") + 1, file.end());
	return file;
}