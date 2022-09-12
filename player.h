#pragma once
#include"DxLib.h"
#include<math.h>
#define	PI 3.14f

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
	const	float	r = 30.0f;;
	const	float	range = 145.0f;
	const	float	range2 = 320.0f;
	float	scrollX;
	float	scrollY;
	float	oldScrollX;
	float	oldScrollY;
	bool	flag;

private:
	int	handle;
	int	lightHandle;
	float	posX;
	float	posY;
	float	move;
	float	xd;
	float	yd;
	const	int	time = 30;
	float	angle;
	int	timer;
	int	num;
};