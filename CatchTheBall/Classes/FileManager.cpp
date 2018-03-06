#include "FileManager.h"
#include "DxLib.h"
#include "EffekseerForDXLib.h"

FileManager::FileManager() { }
FileManager::~FileManager() { }

//---------------------------------------------------------
//	������
//---------------------------------------------------------
void FileManager::Initialize()
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
	//�ǂݍ��ݍς�
	if (LoadCheck(key)) return fileHandleMap.at(key);
	//�ǂݍ���łȂ��ꍇ
	return LoadFile(key);
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
	}else
	if (extension == "efk") {
		//�G�t�F�N�g
		directory = EFFECT_DIRECTORY + key;
		handle = LoadEffekseerEffect(directory.c_str());
	} else
	if (extension == "error") {
		printfDx("Load:Error");
		return -1;
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
	string key = GetFileName(file) + "_";
	for (int i = 0; i < numAll; i++) {
		DrawFormatString(10, 15 * i, GetColor(255, 255, 255), "%s", (key + to_string(i)).c_str());
		fileHandleMap.emplace(key + to_string(i), graphArr[i]);
	}
}
//---------------------------------------------------------
//	�ǂݍ��݂̗L���i�L:true ��:false�j
//---------------------------------------------------------
bool FileManager::LoadCheck(string key)
{
	//�܂������ǂݍ���łȂ���
	if (fileHandleMap.empty()) return false;
	//�T��
	auto handle = fileHandleMap.find(key);
	if (handle == fileHandleMap.end()) return false;
	return true;
}
//---------------------------------------------------------
//	�g���q�̒��o
//---------------------------------------------------------
string FileManager::GetExtension(string file)
{
	auto fileEnd = file.find(".");
	if (fileEnd == string::npos) return "error";

	file.erase(file.begin(), file.begin() + (int)fileEnd + 1);
	return file;
}
//---------------------------------------------------------
//	�g���q�̔r��
//---------------------------------------------------------
string FileManager::GetFileName(string file)
{
	auto fileEnd = file.find(".");
	if (fileEnd == string::npos) return "error";

	file.erase(file.begin() + (int)fileEnd, file.end());
	return file;
}