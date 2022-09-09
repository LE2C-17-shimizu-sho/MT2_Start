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

	void OnCollision();
	
	void	SetPlayer(Player* player_) { player = player_; };

	float	posX;
	float	posY;
	const	float	width = 256;
	const	float	higth = 256;
	bool	flag;
	bool	rFlag;
private:
	const	float	move = 3.4f;
	float	oldX;
	float	oldY;

	Player* player;
};

