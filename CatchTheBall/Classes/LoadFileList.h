#pragma once

struct DivFile {
	DivFile(char* name, int nAll, int nX, int nY, int sX, int sY);

	char* name;
	int numAll, numX, numY;
	int sizeX, sizeY;
};
DivFile::DivFile(char* file, int nAll, int nX, int nY, int sX, int sY) {
	name = file;
	numAll = nAll; numX = nX; numY = nY;
	sizeX = sX; sizeY = sY;
}

#pragma region UseFile_Title

char* UseFile_Title[] = 
{
	"TitleTes.png",
	"TitleText.png",
	"player.png",
	"scene_01_cloud.png",
	"bgm_maoudamashii_8bit02.mp3"
};
DivFile UseDivFile_Title[] =
{
	DivFile("mapChip.png", 10, 4, 4, 64, 64)
};

#pragma endregion

#pragma region UseFile_Select

char* UseFile_Select[] = 
{
	""
};
DivFile UseDivFile_Select[] = 
{
	DivFile("mapChip.png", 10, 4, 4, 64, 64)
};

#pragma endregion

#pragma region UseFile_Game

char* UseFile_Game[] = 
{
	""
};
DivFile UseDivFile_Game[] =
{
	DivFile("mapChip.png", 10, 4, 4, 64, 64)
};

#pragma endregion