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
	void	Initialize();
	/// <summary>
	/// ƒQ[ƒ€“à‚Ì‰Šú‰»
	/// </summary>
	void	State(float	x_, float	y_);
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

	void OnCollisionX();
	void OnCollisionY();
	void OnCollisionX2();
	void OnCollisionY2();

	void OnCollisionXY();

	void	DeathCollision();

	void markCollision();


	float	posX;
	float	posY;
	float	r = 40.0f;
	bool	flag;
	int	bFlag;
	int	markFlag;
private:
	int	handle[4];
	int	hatenaHandle;
	int	bikkuriHandle;
	float	move = 3.0f;

	float	oldX[2];
	float	oldY[2];
	const	int	time = 15;
	int	timer;
	int	num;

	Player* player = nullptr;
};