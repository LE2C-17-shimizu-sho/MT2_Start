#pragma once
#include"DxLib.h"
#include"player.h"

class Player;

class Particle
{
public:
	// 初期化
	void Initialize();

	void	State();

	// パーティクルの動き
	void Move();

	// 描画
	void Draw();

	void	SetPlayer(Player* player_) { player = player_; };

private:
	float	posX;
	float	posY;

	float	r;
	// 横長の棒の座標
	//float particleX;
	//float particleY;
	//float particleX2;
	//float particleY2;

	// 棒が縮んでいく速度
	const	int speed=10;

	// アルファ値
	int alphaValue;
	// アルファ値が減っていく速度
	const	int alphaSpeed=20;

	// ひし形の画像読み込む変数
	int efect;
	int efect2;

	//	スペースを押したときに立てるフラグ
	bool flag;

	Player* player;
};

