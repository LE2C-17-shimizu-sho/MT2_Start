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

	void	MapCollisionX();

	void	MapCollisionY();

	float	x_;
	float	y_;
	float	oldX;
	float	oldY;
	const	float	r = 20.0f;;
	const	float	range = 145.0f;
	float	scrollX;
	float	scrollY;
	float	oldScrollX;
	float	oldScrollY;

private:
	float	posX;
	float	posY;
	bool	flag;
	float	move;
};