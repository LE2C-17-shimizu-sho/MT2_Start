#include "Particle.h"

void Particle::Initialize()
{
	// これもそのまま Resourcesみたいなやつ忘れないように
	efect = LoadGraph("./Resources/enemyEffect.png");
	efect2 = LoadGraph("./Resources/enemyEffect2.png");

}

void Particle::State() {
	posX = player->x_ - player->r - player->scrollX;
	posY = player->y_ - player->r - player->scrollY;
	// この二つもそのまま
	alphaValue = 255;
	r = 0;
	// これもそのまま
	flag = false;
}

void Particle::Move()
{
	// スペースを押したらフラグを立て、アルファ値をMAXに
	// ここは敵が死んだらに置き換わる
	if (!player->flag)
	{
		flag = true;
	}
	if (flag)
	{
		alphaValue -= speed;
		r += (speed/2);
	}
	if (alphaValue<0)
	{
		flag = false;
		r = 0;
		alphaValue = 0;
	}


	//// 棒が完全に縮むまで処理を行う
	//if (particleX != particleX2 && flag == true)
	//{
	//	// 棒をenemyがいた場所に向かって縮む
	//	particleX += particleSpeed;
	//	particleX2 -= particleSpeed;

	//	if (alphaValue > 0)
	//	{
	//		// アルファ値を下げる
	//		alphaValue -= alphaSpeed;
	//	}
	//}

	//// 縮んだらフラグを下ろし、初期化
	//if (particleX == particleX2)
	//{
	//	flag = false;
	//	alphaValue = 0;
	//}
}

void Particle::Draw()
{
	if (flag == true)
	{
		SetDrawBlendMode(DX_BLENDMODE_ADD, alphaValue);
		DrawCircle(posX, posY, r, GetColor(255, 100, 50), true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}

	//// 大きい方のひし形 XYはenemyXYを置いて調整
	//SetDrawBlendMode(DX_BLENDMODE_ADD, 100);
	//DrawGraph(posX, posY, efect, true);
	//SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	//// 小さい方のひし形 XYはenemyXYを置いて調整
	//SetDrawBlendMode(DX_BLENDMODE_ADD, 200);
	//DrawGraph(posX + player->r/2-5, posY + player->r/2-5, efect2, true);
	//SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	//// 長い方の棒 XYはそのままでいいはず
	//SetDrawBlendMode(DX_BLENDMODE_ADD, 100);
	//DrawBox(particleX - player->r - 15, particleY, particleX2 - player->r + 70, particleY2, GetColor(255, 255, 255), true);
	//SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	//// 短い方の棒 XYはそのままでいいはず
	//SetDrawBlendMode(DX_BLENDMODE_ADD, 200);
	//DrawBox(particleX, particleY, particleX2, particleY2, GetColor(255, 255, 255), true);
	//SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	// 赤っぽい爆発 
	// 1、2個目の引数はXとY 3、4個目はXの半径、Yの半径
	// XYは中心座標なのでenemyXYから上手く調整して
	//(DX_BLENDMODE_ADD, alphaValue);
	//, posY+30, 30, 20, GetColor(255, 100, 100), true);
	//(DX_BLENDMODE_NOBLEND, 0);
}