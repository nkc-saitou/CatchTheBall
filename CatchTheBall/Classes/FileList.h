#pragma once

#include <string>

struct DivFile {
	DivFile(std::string name, int nAll, int nX, int nY, int sX, int sY);

	std::string name;
	int numAll, numX, numY;
	int sizeX, sizeY;
};
DivFile::DivFile(std::string file, int nAll, int nX, int nY, int sX, int sY)
{
	name = file;
	numAll = nAll; numX = nX; numY = nY;
	sizeX = sX; sizeY = sY;
}

// Title
std::string UseFile_Title[] = {
	"bgm_maoudamashii_8bit02.mp3",
};
DivFile UseDivFile_Title[] = {
	DivFile("mapChip.png", 10, 4, 4, 64, 64)
};

// Select
std::string UseFile_Select[] = {
	"bgm_maoudamashii_8bit13.mp3"
};
DivFile UseDivFile_Select[] = {
	DivFile("mapChip.png", 10, 4, 4, 64, 64)
};

// Game
std::string UseFile_Game[] = {
	"bgm_maoudamashii_8bit13.mp3"
};
DivFile UseDivFile_Game[] = {
	DivFile("mapChip.png", 10, 4, 4, 64, 64)
};