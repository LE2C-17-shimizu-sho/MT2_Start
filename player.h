#pragma once
#include"DxLib.h"

class Player
{
public:

	/// <summary>
	/// ƒQ[ƒ€“à‚Ì‰Šú‰»
	/// </summary>
	void	State();
	/// <summary>
	/// XV
	/// </summary>
	void	Update(char	key[],char	oldkey[]);
	/// <summary>
	/// •`‰æ
	/// </summary>
	void	Draw();

	void OnCollision();

	float	x_;
	float	y_;
	const	float	r = 20.0f;;
	const	float	range = 120.0f;
	float	scrollX;
	float	scrollY;

private:
	float	posX;
	float	posY;
	bool	flag;
	float	move = 5.0f;
};