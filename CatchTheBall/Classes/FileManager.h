#pragma once

#include "Singleton.h"
#include <map>
#include <string>

#define GRAPH_DIRECTORY "Resources\\Image\\"
#define AUDIO_DIRECTORY "Resources\\Audio\\"

enum FileType
{
	Graph,
	Audio
};

class FileManager : public Singleton<FileManager>
{
public:
	FileManager();
	~FileManager();

	int GetFileHandle(std::string, FileType);
	void ResetData();

private:
	int LoadFile(std::string key, FileType);	//FileÇÃì«Ç›çûÇ›

	std::map<std::string, int> fileHandleMap;
};