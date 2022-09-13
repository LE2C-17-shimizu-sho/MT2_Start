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
	void	Initialize(float	cX_,float	cY_);
	/// <summary>
	/// 更新
	/// </summary>
	void	Update();
	/// <summary>
	/// 描画
	/// </summary>
	void	Draw();

	void	SetPlayer(Player* player_) { player = player_; };


	float	posX[3];
	float	posY[3];
	float	r = 40.0f;
private:
	int	handle[4];
	float	centerX;
	float	centerY;
	float	angle[3];
	float	len;
	float	adX;
	float	adY;
	float	radius;

	const	int	time = 5;
	int	timer;
	int	num;

	Player* player = nullptr;

};


