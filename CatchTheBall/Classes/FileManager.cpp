#include "FileManager.h"
#include "DxLib.h"
#include "FileList.h"
#include "EffekseerForDXLib.h"

int cnt;
FileManager::FileManager()
{
	cnt = 0;
}
FileManager::~FileManager()
{
	ResetData();
}
//---------------------------------------------------------
//	必要ファイルの一括読み込み
//---------------------------------------------------------
void FileManager::SetData(eScene scene)
{
	/*for (string file : UseFile_Title) {
		LoadFile(file);
	}*/
}
//---------------------------------------------------------
//	データの解放
//---------------------------------------------------------
void FileManager::ResetData()
{
	InitGraph();
	fileHandleMap.clear();
}
//---------------------------------------------------------
//	Fileを渡す
//---------------------------------------------------------
int FileManager::GetFileHandle(string key)
{
	//空の場合
	if (fileHandleMap.empty()){
		return LoadFile(key);
	}

	//探索
	auto handle = fileHandleMap.find(key);
	//読み込んでない場合
	if (handle == fileHandleMap.end()) {
		return LoadFile(key);
	}
	return handle->second;
}
//---------------------------------------------------------
//	Fileの読み込み
//---------------------------------------------------------
int FileManager::LoadFile(string key)
{
	string directory, extension;
	int handle;

	//拡張子
	extension = GetExtension(key);

	//読み込み
	if (extension == "png" || extension == "jpg" || extension == "bmp") {
		//グラフィック
		directory = GRAPH_DIRECTORY + key;
		handle = LoadGraph(directory.c_str());
	} else
	if (extension == "mp3" || extension == "wave" || extension == "ogg") {
		//オーディオ
		directory = AUDIO_DIRECTORY + key;
		handle = LoadSoundMem(directory.c_str());
	}
	else if (extension == "efk") {
		//エフェクト
		directory = EFFECT_DIRECTORY + key;
		handle = LoadEffekseerEffect(directory.c_str ());
	}

	//保存
	fileHandleMap.emplace(key, handle);
	return handle;
}
//---------------------------------------------------------
//	拡張子の抽出
//---------------------------------------------------------
string FileManager::GetExtension(string file)
{
	file.erase(file.begin(), file.begin() + (int)file.find(".") + 1);
	return file;
}