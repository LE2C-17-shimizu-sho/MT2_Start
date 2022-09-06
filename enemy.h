#pragma once
#include"DxLib.h"
#include"product.h"
#include"player.h"

class Player;


class Enemy
{
public:
	/// <summary>
	/// ������
	/// </summary>
	void	Initialize(float	x_, float	y_);
	/// <summary>
	/// �Q�[�����̏�����
	/// </summary>
	void	State();
	/// <summary>
	/// �X�V
	/// </summary>
	void	Update();
	/// <summary>
	/// �`��
	/// </summary>
	void	Draw();

	void	SetPlayer(Player* player_) {  player = player_; };

private:
	float	posX;
	float	posY;
	float	r;
	bool	flag;
	float	range;
	float	move;

	Player* player = nullptr;
};