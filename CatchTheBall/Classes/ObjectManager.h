#pragma once

#include "Object.h"
#include "Singleton.h"
#include <vector>

using namespace std;

class ObjectManager : public Singleton<ObjectManager>
{
public:
	vector<Object*> objectArry;

	void Initialize();	//初期化
	void Finalize();	//終了処理
	void Add(Object*);	//追加
	void Update();		//更新
	void Stop();		//更新の停止
	void Reopening();	//更新の再開
	void Draw();		//表示

private:
	bool isStop;
};