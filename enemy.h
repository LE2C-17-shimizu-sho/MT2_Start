#pragma once
#include"DxLib.h"
#include"product.h"
#include"player.h"

class Player;


class Enemy
{
public:
	/// <summary>
	/// ‰Šú‰»
	/// </summary>
	void	Initialize(float	x_, float	y_);
	/// <summary>
	/// ƒQ[ƒ€“à‚Ì‰Šú‰»
	/// </summary>
	void	State();
	/// <summary>
	/// XV
	/// </summary>
	void	Update();
	/// <summary>
	/// •`‰æ
	/// </summary>
	void	Draw();

	void	SetPlayer(Player* player_) {  player = player_; };

private:
	float	posX;
	float	posY;
	float	r;
	bool	flag;
	float	range;
	float	move;

	Player* player = nullptr;
};