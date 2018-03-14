#include "Result.h"

Result::Result()
{
	gh = FileManager::Instance()->GetFileHandle("ResultFrame.png");

	x = 300;
	y = 300;

	frameX = 120;
	frameY = -300;

	filstFlg = true;

	//エフェクトマネージャーを初期化する
	EffectManager::Instance()->Initialize();
	EffectManager::Instance()->Load();
	
	trailEffect = EffectManager::CreateEffect(EffectType::FireworkTrailClear, x, y, false);
	fireworkEffect = EffectManager::CreateEffect(EffectType::ExplosionFireworkClear, x, y, false);

	trailEffect->StopEffect();
	fireworkEffect->StopEffect();
}

Result::~Result()
{
	EffectManager::Instance()->Finalize();
}

void Result::Update()
{

}

void Result::Draw()
{

	if (filstFlg)
	{
		trailEffect->PlayEffect();
		y--;
	}

	trailEffect->SetPosition(x, y);

	if (y <= 160)
	{
		trailEffect->StopEffect();

		fireworkEffect->SetPosition(x, y);
		fireworkEffect->PlayEffect();

		filstFlg = false;
	}

	if (fireworkEffect->PlayEffectFlg() == false && filstFlg == false)
	{
		DrawGraph(frameX, frameY, gh, TRUE);
		if (frameY <= 20) frameY += 7;
		else if (frameY <= 30) frameY += 6;
		else if (frameY <= 40) frameY += 5;
		else if (frameY <= 50) frameY += 4;
		else if (frameY <= 60) frameY += 3;
		else if (frameY <= 70) frameY += 2;
		else if (frameY <= 80) frameY += 1;
	}
		EffectManager::Instance()->Update();
}