#pragma once

class Player
{
public:
	/// <summary>
	/// 初期化
	/// </summary>
	void	Initialize();
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

};