#pragma once
#include"DxLib.h"
#include"player.h"
#include"product.h"

class Box
{
public:
	/// <summary>
	/// 初期化
	/// </summary>
	void	Initialize(float	x_, float	y_);
	/// <summary>
	/// ゲーム内の初期化
	/// </summary>
	void	State();
	/// <summary>
	/// 更新
	/// </summary>
	void	Update();
	/// <summary>
	/// 描画
	/// </summary>
	void	Draw();

	void OnCollisionX();

	void OnCollisionY();

	void HomingCollision();
	
	void	SetPlayer(Player* player_) { player = player_; };

	float	posX;
	float	posY;
	float	width = 250;
	float	higth = 250;
	bool	flag;
	bool	rFlag;
private:
	const	float	move = 2.0f;
	float	oldX;
	float	oldY;
	float   x_;
	float	y_;

	Player* player;
};

