#include "Particle.h"

void Particle::Initialize()
{
	// ��������̂܂� Resources�݂����Ȃ�Y��Ȃ��悤��
	efect = LoadGraph("./Resources/enemyEffect.png");
	efect2 = LoadGraph("./Resources/enemyEffect2.png");

}

void Particle::State() {
	posX = player->x_ - player->r - player->scrollX;
	posY = player->y_ - player->r - player->scrollY;
	// ���̓�����̂܂�
	alphaValue = 255;
	r = 0;
	// ��������̂܂�
	flag = false;
}

void Particle::Move()
{
	// �X�y�[�X����������t���O�𗧂āA�A���t�@�l��MAX��
	// �����͓G�����񂾂�ɒu�������
	if (!player->flag)
	{
		flag = true;
	}
	if (flag)
	{
		alphaValue -= speed;
		r += (speed/2);
	}
	if (alphaValue<0)
	{
		flag = false;
		r = 0;
		alphaValue = 0;
	}


	//// �_�����S�ɏk�ނ܂ŏ������s��
	//if (particleX != particleX2 && flag == true)
	//{
	//	// �_��enemy�������ꏊ�Ɍ������ďk��
	//	particleX += particleSpeed;
	//	particleX2 -= particleSpeed;

	//	if (alphaValue > 0)
	//	{
	//		// �A���t�@�l��������
	//		alphaValue -= alphaSpeed;
	//	}
	//}

	//// �k�񂾂�t���O�����낵�A������
	//if (particleX == particleX2)
	//{
	//	flag = false;
	//	alphaValue = 0;
	//}
}

void Particle::Draw()
{
	if (flag == true)
	{
		SetDrawBlendMode(DX_BLENDMODE_ADD, alphaValue);
		DrawCircle(posX, posY, r, GetColor(255, 100, 50), true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}

	//// �傫�����̂Ђ��` XY��enemyXY��u���Ē���
	//SetDrawBlendMode(DX_BLENDMODE_ADD, 100);
	//DrawGraph(posX, posY, efect, true);
	//SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	//// ���������̂Ђ��` XY��enemyXY��u���Ē���
	//SetDrawBlendMode(DX_BLENDMODE_ADD, 200);
	//DrawGraph(posX + player->r/2-5, posY + player->r/2-5, efect2, true);
	//SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	//// �������̖_ XY�͂��̂܂܂ł����͂�
	//SetDrawBlendMode(DX_BLENDMODE_ADD, 100);
	//DrawBox(particleX - player->r - 15, particleY, particleX2 - player->r + 70, particleY2, GetColor(255, 255, 255), true);
	//SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	//// �Z�����̖_ XY�͂��̂܂܂ł����͂�
	//SetDrawBlendMode(DX_BLENDMODE_ADD, 200);
	//DrawBox(particleX, particleY, particleX2, particleY2, GetColor(255, 255, 255), true);
	//SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	// �Ԃ��ۂ����� 
	// 1�A2�ڂ̈�����X��Y 3�A4�ڂ�X�̔��a�AY�̔��a
	// XY�͒��S���W�Ȃ̂�enemyXY�����肭��������
	//(DX_BLENDMODE_ADD, alphaValue);
	//, posY+30, 30, 20, GetColor(255, 100, 100), true);
	//(DX_BLENDMODE_NOBLEND, 0);
}