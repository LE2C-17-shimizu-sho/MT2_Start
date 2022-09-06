#pragma once

class enemy
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
	void	Update();
	/// <summary>
	/// •`‰æ
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