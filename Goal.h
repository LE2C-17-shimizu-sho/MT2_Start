#pragma once
#include"DxLib.h"
#include"player.h"

class Player;

class Goal
{
public:
	/// <summary>
	/// ƒQ[ƒ€“à‚Ì‰Šú‰»
	/// </summary>
	void	Initialize();
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

	void	SetPlayer(Player* player_) { player = player_; };

	void OnCollision();

	const	float	w = 192.0f;
	const	float	h = 384.0f;
	bool	flag;
	float	posX;
	float	posY;

private:
	Player* player;
	int	handle;
	const	int	time = 30;
	int	timer;
	int	num;
};

