#pragma once

class Player
{
public:
	/// <summary>
	/// ������
	/// </summary>
	void	Initialize();
	/// <summary>
	/// �X�V
	/// </summary>
	void	Update();
	/// <summary>
	/// �`��
	/// </summary>
	void	Draw();
private:
	float	posX;
	float	posY;
	float	r;
	bool	flag;

};