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

	float	GetPossX();

	float	GetPossY();

private:
	float	posX;
	float	posY;
	float	r;
	bool	flag;
	float	range;
	float	move;
};