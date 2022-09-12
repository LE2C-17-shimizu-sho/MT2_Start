#pragma once
#include"DxLib.h"
#include"player.h"
#include"product.h"

class Box
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

	void OnCollisionX();

	void OnCollisionY();

	void HomingCollision();
	
	void	SetPlayer(Player* player_) { player = player_; };

	float	posX;
	float	posY;
	float	width = 240;
	float	higth = 240;
	bool	flag;
	bool	mapFlag;
	bool	moveFlag;
private:
	int	handle;
	float	move;
	float	oldX;
	float	oldY;
	float   x_;
	float	y_;

	Player* player;
};

