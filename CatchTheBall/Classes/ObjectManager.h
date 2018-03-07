#pragma once

#include "Object.h"
#include "Singleton.h"
#include <vector>

using namespace std;

const static int UI_NO = 20;

class ObjectManager : public Singleton<ObjectManager>
{
public:
	void Initialize();		//初期化
	void Finalize();		//終了処理
	void Add(Object*);		//追加
	void Destroy(Object*);	//削除
	void Update();			//更新
	void Stop();			//更新の停止
	void Reopening();		//更新の再開
	void Draw();			//表示

private:
	vector<Object*> objectArry;

	bool isStop;
};