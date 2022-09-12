#include "Particle.h"

void Particle::Initialize()
{
	// enemy�̍��W�����S������enemyX-100��enemyX+100�݂����Ȋ����ŏ���
	particleX = 580;
	particleY = 300;
	particleX2 = 700;
	particleY2 = 305;

	// ����͂��̂܂�
	particleSpeed = 10;

	// ���̓�����̂܂�
	alphaValue = 0;
	alphaSpeed = 20;

	// ��������̂܂� Resources�݂����Ȃ�Y��Ȃ��悤��
	efect = LoadGraph("enemyEffect.png");
	efect2 = LoadGraph("enemyEffect2.png");

	// ��������̂܂�
	flag = false;
}

void Particle::Move(char keys[], char oldkey[])
{
	// �X�y�[�X����������t���O�𗧂āA�A���t�@�l��MAX��
	// �����͓G�����񂾂�ɒu�������
	if (keys[KEY_INPUT_SPACE] == 1 && oldkey[KEY_INPUT_SPACE] == 0)
	{
		flag = true;
		alphaValue = 255;
	}

	// �_�����S�ɏk�ނ܂ŏ������s��
	if (particleX != particleX2 && flag == true)
	{
		// �_��enemy�������ꏊ�Ɍ������ďk��
		particleX += particleSpeed;
		particleX2 -= particleSpeed;

		if (alphaValue > 0)
		{
			// �A���t�@�l��������
			alphaValue -= alphaSpeed;
		}
	}

	// �k�񂾂�t���O�����낵�A������
	if (particleX == particleX2)
	{
		flag = false;
		particleX = 540;
		particleX2 = 740;// ������X��X2��0�ɂ��ēG�����񂾃^�C�~���O�ł܂��������ق�����������
		alphaValue = 0;
	}
}

void Particle::Draw()
{
	if (flag == true)
	{
		// �傫�����̂Ђ��` XY��enemyXY��u���Ē���
		SetDrawBlendMode(DX_BLENDMODE_ADD, 100);
		DrawGraph(610, 272, efect, true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		// ���������̂Ђ��` XY��enemyXY��u���Ē���
		SetDrawBlendMode(DX_BLENDMODE_ADD, 200);
		DrawGraph(620, 282, efect2, true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		// �������̖_ XY�͂��̂܂܂ł����͂�
		SetDrawBlendMode(DX_BLENDMODE_ADD, 100);
		DrawBox(particleX - 25, particleY, particleX2 + 25, particleY2, GetColor(255, 255, 255), true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		// �Z�����̖_ XY�͂��̂܂܂ł����͂�
		SetDrawBlendMode(DX_BLENDMODE_ADD, 200);
		DrawBox(particleX, particleY, particleX2, particleY2, GetColor(255, 255, 255), true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}

	// �Ԃ��ۂ����� 
	// 1�A2�ڂ̈�����X��Y 3�A4�ڂ�X�̔��a�AY�̔��a
	// XY�͒��S���W�Ȃ̂�enemyXY�����肭��������
	SetDrawBlendMode(DX_BLENDMODE_ADD, alphaValue);
	DrawOval(640, 300, 30, 20, GetColor(255, 100, 100), true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}