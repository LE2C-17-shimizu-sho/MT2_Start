#pragma once
#include"DxLib.h"
#include"player.h"

class Player;

class Goal
{
public:
	/// <summary>
	/// �Q�[�����̏�����
	/// </summary>
	void	Initialize();
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

	void	SetPlayer(Player* player_) { player = player_; };

	void OnCollision();

	const	float	w = 192.0f;
	const	float	h = 384.0f;
	bool	flag;
	float	posX;
	float	posY;

private:
	Player* player;
	int	handle;
	const	int	time = 30;
	int	timer;
	int	num;
};

