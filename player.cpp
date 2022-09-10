#include"player.h"

void	Player::State() {
	posX = 504.0f;
	posY = 300.0f;
	scrollX, scrollY = 0;
	flag = true;
	x_ = 0.0f;
	y_ = 0.0f;
	LoadDivGraph("./Resources/Player.png",6,6,1,40,40,handle);
	lightHandle = LoadGraph("./Resources/light.png");
}

void	Player::Update(char	key[], char	oldkey[]) {
	if (flag)
	{
		oldX = posX;
		oldY = posY;
		oldScrollX = scrollX;
		oldScrollY = scrollY;
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

		//移動範囲
		if (posX<340)
		{
			posX = 320 + r;
		}
		if (posY < 160)
		{
			posY = 140 + r;
		}
		if (posX > 5412)
		{
			posX = 5432 - r;
		}
		if (posY >	2976)
		{
			posY = 2996- r;
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
		
		x_ = posX;
		y_ = posY;

		//連番画像
		if (timer-- <= 0)
		{
			num++;
			timer = time;
			if (num == 6)
			{
				num = 0;
			}
		}
		
		if (key[KEY_INPUT_W] == 1 )
		{
			angle = 0;
		}
		if (key[KEY_INPUT_S] == 1)
		{
			angle = 3;
		}
		if (key[KEY_INPUT_A] == 1 )
		{
			angle = 5;
		}
		if ( key[KEY_INPUT_D] == 1)
		{
			angle = 2;
		}
		if (key[KEY_INPUT_W] == 1 && key[KEY_INPUT_A] == 1)
		{
			angle = 6;
		}
		if (key[KEY_INPUT_W] == 1 && key[KEY_INPUT_D] == 1)
		{
			angle = 1;
		}
		if ( key[KEY_INPUT_S] == 1&&key[KEY_INPUT_A] == 1)
		{
			angle = 4;
		}
		if ( key[KEY_INPUT_S] == 1&& key[KEY_INPUT_D] == 1)
		{
			angle = 2.5;
		}
	}
}

void	Player::Draw() {
	if (flag)
	{
		DrawCircle(posX-scrollX, posY-scrollY, r, GetColor(255,255,255), true);
		//DrawGraph(posX - r - scrollX, posY - r - scrollY, handle[num], TRUE);
		DrawRotaGraph(posX - scrollX, posY - scrollY, 1.0f, angle, handle[num], true, false);
		DrawCircle(posX  - scrollX, posY  - scrollY, range, GetColor(255, 255, 255), false);
	}
	DrawGraph(posX - 1000 - scrollX, posY - 750 - scrollY, lightHandle, TRUE);
	DrawFormatString(0, 80, GetColor(255, 255, 255), "x=%f", posX);
	DrawFormatString(0, 100, GetColor(255, 255, 255), "Y=%f",posY);
	DrawFormatString(0, 120, GetColor(255, 255, 255), "%d", num);
}

void	Player::OnCollision() {
	flag = false;
}

void	Player::MapCollisionX() {
	posX = oldX;
	scrollX = oldScrollX;
}

void	Player::MapCollisionY() {
	posY = oldY;
	scrollY = oldScrollY;
}