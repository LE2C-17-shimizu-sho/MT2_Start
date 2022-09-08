#include"player.h"

void	Player::State() {
	posX = 524.0f;
	posY = 320.0f;
	scrollX, scrollY = 0;
	flag = true;
	x_ = 0.0f;
	y_ = 0.0f;
}

void	Player::Update(char	key[], char	oldkey[]) {
	if (flag)
	{
		x_ = posX;
		y_ = posY;
		move = 4.0f;
		//同時押しでスピード変更
		if (key[KEY_INPUT_W] == 1 || key[KEY_INPUT_S] == 1)
		{
			if (key[KEY_INPUT_A] == 1 || key[KEY_INPUT_D] == 1)
			{
				move = 2.5f;
			}
		}

		//移動処理
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

		//スクロール処理
			//--最小--//
		if (posX<640)
		{
			scrollX = 0;
		}
		if (posY < 320)
		{
			scrollY = 0;
		}
			//--最大--//
		if (posX >5120)
		{
			scrollX = 4480;
		}
		if (posY >2736)
		{
			scrollY = 2416;
		}
		
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
	DrawFormatString(0, 120, GetColor(255, 255, 255), "Y=%f", posX);
}

void	Player::OnCollision() {
	flag = false;
}