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

	void Initialize(eScene);
	void Finalize();
	int GetFileHandle(string);
	
private:
	//File‚Ì“Ç‚İ‚İ
	int LoadFile(string key);		
	void LoadFile(string file, int numAll, int numX, int numY, int sizeX, int sizeY);
	
	string GetExtension(string file);	//Šg’£q‚Ì’Šo
	string GetFileName(string file);		//Šg’£q‚Ì”rœ

	map<std::string, int> fileHandleMap;
};