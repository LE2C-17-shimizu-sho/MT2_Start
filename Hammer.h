#pragma once
#include"DxLib.h"
#include"product.h"
#include"player.h"
class Player;

class Hammer
{
public:
	/// <summary>
	/// ‰Šú‰»
	/// </summary>
	void	Initialize(float	x_, float	y_,float	cX_,float	cY_);
	/// <summary>
	/// XV
	/// </summary>
	void	Update();
	/// <summary>
	/// •`‰æ
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


