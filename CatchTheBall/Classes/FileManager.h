#pragma once

#include "Singleton.h"
#include "SceneMgr.h"
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

	void SetData(eScene);
	void ResetData();
	int GetFileHandle(string);
	
private:
	int LoadFile(string key);		//File‚Ì“Ç‚İ‚İ
	void LoadFile(string key, int numAll, int numX, int numY, int sizeX, int sizeY);
	string GetExtension(string key);	//Šg’£q‚Ìæ‚èo‚µ

	map<std::string, int> fileHandleMap;
};