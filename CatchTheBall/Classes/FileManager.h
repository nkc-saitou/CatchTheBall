#pragma once

#include "Singleton.h"
#include "SceneMgr.h"
#include <map>
#include <string>

using namespace std;

#define GRAPH_DIRECTORY "Resources\\Image\\"
#define AUDIO_DIRECTORY "Resources\\Audio\\"

class FileManager : public Singleton<FileManager>
{
public:
	FileManager();
	~FileManager();

	void SetData(eScene);
	void ResetData();
	int GetFileHandle(string);
	
private:
	int LoadFile(string key);	//File‚Ì“Ç‚İ‚İ
	string GetExtension(string);		//Šg’£q‚Ìæ‚èo‚µ

	map<std::string, int> fileHandleMap;
};