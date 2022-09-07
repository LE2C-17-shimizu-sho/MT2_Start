#include"player.h"

void	Player::State() {
	posX = 640.0f;
	posY = 320.0f;
	flag = true;
	x_ = 0.0f;
	y_ = 0.0f;
}

void	Player::Update(char	key[], char	oldkey[]) {
	if (flag)
	{
		move = 4.0f;
		//���������ŃX�s�[�h�ύX
		if (key[KEY_INPUT_W] == 1 || key[KEY_INPUT_S] == 1)
		{
			if (key[KEY_INPUT_A] == 1 || key[KEY_INPUT_D] == 1)
			{
				move = 2.5f;
			}
		}

		//�ړ�����
		if (key[KEY_INPUT_W] == 1)
		{
			posY -= move;
			scrollY -= move;
		}
		if (key[KEY_INPUT_S] == 1)
		{
			posY += move;
			scrollY += move;
		}
		if (key[KEY_INPUT_A] == 1)
		{
			posX -= move;
			scrollX -= move;
		}
		if (key[KEY_INPUT_D] == 1)
		{
			posX += move;
			scrollX += move;
		}

		x_ = posX;
		y_ = posY;
	}
}

void	Player::Draw() {
	if (flag)
	{
		DrawCircle(posX-scrollX, posY-scrollY, r, GetColor(255,255,255), true);
		DrawCircle(posX - scrollX, posY - scrollY, range, GetColor(255, 255, 255), false);
	}
	DrawFormatString(0, 80, GetColor(255, 255, 255), "x=%f", scrollX);
	DrawFormatString(0, 100, GetColor(255, 255, 255), "Y=%f", scrollY);
}

void	Player::OnCollision() {
	flag = false;
}