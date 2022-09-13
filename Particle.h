#pragma once
#include"DxLib.h"
#include"player.h"

class Player;

class Particle
{
public:
	// ������
	void Initialize();

	void	State();

	// �p�[�e�B�N���̓���
	void Move();

	// �`��
	void Draw();

	void	SetPlayer(Player* player_) { player = player_; };

private:
	float	posX;
	float	posY;

	float	r;
	// �����̖_�̍��W
	//float particleX;
	//float particleY;
	//float particleX2;
	//float particleY2;

	// �_���k��ł������x
	const	int speed=10;

	// �A���t�@�l
	int alphaValue;
	// �A���t�@�l�������Ă������x
	const	int alphaSpeed=20;

	// �Ђ��`�̉摜�ǂݍ��ޕϐ�
	int efect;
	int efect2;

	//	�X�y�[�X���������Ƃ��ɗ��Ă�t���O
	bool flag;

	Player* player;
};

