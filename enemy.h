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

	void OnCollision();

	void	DeathCollision();

	float	posX;
	float	posY;
	float	r = 40.0f;
	bool	flag;
	bool	rFlag;
private:
	float	move = 3.4f;

	Player* player = nullptr;
};