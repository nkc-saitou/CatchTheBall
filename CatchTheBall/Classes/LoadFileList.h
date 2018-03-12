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
	"TitleTest.png",
	"Title_Logp.png",
	"BGM_Title.mp3"
};
DivFile UseDivFile_Title[] =
{
	DivFile("Player_A.png", 2, 2, 1, 64, 64),
	DivFile("Player_B.png", 2, 2, 1, 64, 64),
	DivFile("Player_C.png", 2, 2, 1, 64, 64),
	DivFile("Player_D.png", 2, 2, 1, 64, 64)
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