#include"player.h"

void	Player::State() {
	posX = 580.0f;
	posY = 260.0f;
	flag = true;
	x_ = 0.0f;
	y_ = 0.0f;
}

void	Player::Update(char	key[], char	oldkey[]) {
	if (flag)
	{
		move = 4.0f;
		//同時押しでスピード変更
		if (key[KEY_INPUT_W] == 1 || key[KEY_INPUT_S] == 1)
		{
			if (key[KEY_INPUT_A] == 1 || key[KEY_INPUT_D] == 1)
			{
				move = 2.0f;
			}
		}

		//移動処理
		if (key[KEY_INPUT_W] == 1)
		{
			posY -= move;
		}
		if (key[KEY_INPUT_S] == 1)
		{
			posY += move;
		}
		if (key[KEY_INPUT_A] == 1)
		{
			posX -= move;
		}
		if (key[KEY_INPUT_D] == 1)
		{
			posX += move;
		}

		x_ = posX;
		y_ = posY;
	}
}

void	Player::Draw() {
	if (flag)
	{
		DrawCircle(posX, posY, r, GetColor(255, 255, 255), true);
		DrawCircle(posX, posY, range, GetColor(255, 255, 255), false);
	}
	DrawFormatString(0, 80, GetColor(255, 255, 255), "x=%f", posX);
	DrawFormatString(0, 100, GetColor(255, 255, 255), "Y=%f", posY);
}

void	Player::OnCollision() {
	flag = false;
}