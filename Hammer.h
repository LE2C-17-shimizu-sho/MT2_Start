#pragma once
#include"DxLib.h"
#include"product.h"
#include"player.h"
class Player;

class Hammer
{
public:
	/// <summary>
	/// 初期化
	/// </summary>
	void	Initialize(float	x_, float	y_,float	cX_,float	cY_);
	/// <summary>
	/// 更新
	/// </summary>
	void	Update();
	/// <summary>
	/// 描画
	/// </summary>
	void	Draw();

	void	SetPlayer(Player* player_) { player = player_; };


	float	posX;
	float	posY;
	float	r = 40.0f;
private:
	float	centerX;
	float	centerY;
	float	angle;
	float	len;
	float	adX;
	float	adY;
	float	radius;

	Player* player = nullptr;

};


