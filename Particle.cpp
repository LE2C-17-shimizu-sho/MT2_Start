#include "Particle.h"

void Particle::Initialize()
{
	// enemyの座標が中心だからenemyX-100とenemyX+100みたいな感じで書く
	particleX = 580;
	particleY = 300;
	particleX2 = 700;
	particleY2 = 305;

	// これはそのまま
	particleSpeed = 10;

	// この二つもそのまま
	alphaValue = 0;
	alphaSpeed = 20;

	// これもそのまま Resourcesみたいなやつ忘れないように
	efect = LoadGraph("enemyEffect.png");
	efect2 = LoadGraph("enemyEffect2.png");

	// これもそのまま
	flag = false;
}

void Particle::Move(char keys[], char oldkey[])
{
	// スペースを押したらフラグを立て、アルファ値をMAXに
	// ここは敵が死んだらに置き換わる
	if (keys[KEY_INPUT_SPACE] == 1 && oldkey[KEY_INPUT_SPACE] == 0)
	{
		flag = true;
		alphaValue = 255;
	}

	// 棒が完全に縮むまで処理を行う
	if (particleX != particleX2 && flag == true)
	{
		// 棒をenemyがいた場所に向かって縮む
		particleX += particleSpeed;
		particleX2 -= particleSpeed;

		if (alphaValue > 0)
		{
			// アルファ値を下げる
			alphaValue -= alphaSpeed;
		}
	}

	// 縮んだらフラグを下ろし、初期化
	if (particleX == particleX2)
	{
		flag = false;
		particleX = 540;
		particleX2 = 740;// ここのXとX2は0にして敵が死んだタイミングでまた代入するほうがいいかも
		alphaValue = 0;
	}
}

void Particle::Draw()
{
	if (flag == true)
	{
		// 大きい方のひし形 XYはenemyXYを置いて調整
		SetDrawBlendMode(DX_BLENDMODE_ADD, 100);
		DrawGraph(610, 272, efect, true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		// 小さい方のひし形 XYはenemyXYを置いて調整
		SetDrawBlendMode(DX_BLENDMODE_ADD, 200);
		DrawGraph(620, 282, efect2, true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		// 長い方の棒 XYはそのままでいいはず
		SetDrawBlendMode(DX_BLENDMODE_ADD, 100);
		DrawBox(particleX - 25, particleY, particleX2 + 25, particleY2, GetColor(255, 255, 255), true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		// 短い方の棒 XYはそのままでいいはず
		SetDrawBlendMode(DX_BLENDMODE_ADD, 200);
		DrawBox(particleX, particleY, particleX2, particleY2, GetColor(255, 255, 255), true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}

	// 赤っぽい爆発 
	// 1、2個目の引数はXとY 3、4個目はXの半径、Yの半径
	// XYは中心座標なのでenemyXYから上手く調整して
	SetDrawBlendMode(DX_BLENDMODE_ADD, alphaValue);
	DrawOval(640, 300, 30, 20, GetColor(255, 100, 100), true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}