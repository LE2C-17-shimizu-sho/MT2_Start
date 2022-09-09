#pragma once
#include"DxLib.h"
#include"player.h"
#include"product.h"

class Box
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

