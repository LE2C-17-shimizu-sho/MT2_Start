#pragma once
#include"DxLib.h"

class Player
{
public:
	/// <summary>
	/// 初期化
	/// </summary>
	void	Initialize();
	/// <summary>
	/// ゲーム内の初期化
	/// </summary>
	void	State();
	/// <summary>
	/// 更新
	/// </summary>
	void	Update(char	key[],char	oldkey[]);
	/// <summary>
	/// 描画
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