#pragma once
#include"DxLib.h"
#include"player.h"

class Player;

class Particle
{
public:
	// 初期化
	void Initialize();

	// パーティクルの動き
	void Move(bool	flag);

	// 描画
	void Draw();

	void	SetPlayer(Player* player_) { player = player_; };

private:
	// 横長の棒の座標
	int particleX;
	int particleY;
	int particleX2;
	int particleY2;

	// 棒が縮んでいく速度
	int particleSpeed;

	// アルファ値
	int alphaValue;
	// アルファ値が減っていく速度
	int alphaSpeed;

	// ひし形の画像読み込む変数
	int efect;
	int efect2;

	//	スペースを押したときに立てるフラグ
	bool flag;

	Player* player;
};

