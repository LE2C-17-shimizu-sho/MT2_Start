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

	void OnCollisionX();

	void OnCollisionY();

	void HomingCollision();
	
	void	SetPlayer(Player* player_) { player = player_; };

	float	posX;
	float	posY;
	float	width = 250;
	float	higth = 250;
	bool	flag;
	bool	rFlag;
private:
	const	float	move = 2.0f;
	float	oldX;
	float	oldY;
	float   x_;
	float	y_;

	Player* player;
};

