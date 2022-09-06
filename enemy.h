#pragma once

class enemy
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
	void	Update();
	/// <summary>
	/// 描画
	/// </summary>
	void	Draw();
private:
	float	posX;
	float	posY;
	float	r;
	bool	flag;
	float	range;
	float	move;
};