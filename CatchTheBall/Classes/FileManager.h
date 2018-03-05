#pragma once

#include "Singleton.h"
#include <map>
#include <string>

using namespace std;

#define GRAPH_DIRECTORY "Resources\\Image\\"
#define AUDIO_DIRECTORY "Resources\\Audio\\"
#define EFFECT_DIRECTORY "Resources\\Effect\\"

class FileManager : public Singleton<FileManager>
{
public:
	FileManager();
	~FileManager();

	void Initialize();
	int GetFileHandle(string);
	//File�̓ǂݍ���
	int LoadFile(string key);
	void LoadFile(string file, int numAll, int numX, int numY, int sizeX, int sizeY);

private:
	string GetExtension(string file);	//�g���q�̒��o
	string GetFileName(string file);	//�g���q�̔r��

	map<std::string, int> fileHandleMap;
};