#pragma once
#include"DxLib.h"

class Player
{
public:
	/// <summary>
	/// ������
	/// </summary>
	void	Initialize();
	/// <summary>
	/// �Q�[�����̏�����
	/// </summary>
	void	State();
	/// <summary>
	/// �X�V
	/// </summary>
	void	Update(char	key[],char	oldkey[]);
	/// <summary>
	/// �`��
	/// </summary>
	void	Draw();

	void OnCollision();

	float	x_;
	float	y_;
	float	r;
	float	range;

private:
	float	posX;
	float	posY;
	bool	flag;
	float	move;
};