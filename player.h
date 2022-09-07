#pragma once
#include"DxLib.h"

class Player
{
public:
	/// <summary>
	/// ‰Šú‰»
	/// </summary>
	void	Initialize();
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
	float	r = 20.0f;;
	float	range = 120.0f;

private:
	float	posX;
	float	posY;
	bool	flag;
	float	move = 5.0f;
};