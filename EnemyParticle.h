#pragma once

#include"DxLib.h"

class Particle
{
public:
	// ������
	void Initialize();

	// �p�[�e�B�N���̓���
	void Move(char keys[], char oldkey[]);

	// �`��
	void Draw();

private:
	// �����̖_�̍��W
	int particleX;
	int particleY;
	int particleX2;
	int particleY2;

	// �_���k��ł������x
	int particleSpeed;

	// �A���t�@�l
	int alphaValue;
	// �A���t�@�l�������Ă������x
	int alphaSpeed;

	// �Ђ��`�̉摜�ǂݍ��ޕϐ�
	int efect;
	int efect2;

	//	�X�y�[�X���������Ƃ��ɗ��Ă�t���O
	bool flag;
};

