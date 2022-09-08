#include"player.h"

void	Player::State() {
	posX = 524.0f;
	posY = 320.0f;
	scrollX, scrollY = 0;
	flag = true;
	x_ = 0.0f;
	y_ = 0.0f;
	handle = LoadGraph("./Resources/Player.png");
}

void	Player::Update(char	key[], char	oldkey[]) {
	if (flag)
	{
		oldX = posX;
		oldY = posY;
		oldScrollX = scrollX;
		oldScrollY = scrollY;
		move = 4.0f;
		//���������ŃX�s�[�h�ύX
		if (key[KEY_INPUT_W] == 1 || key[KEY_INPUT_S] == 1)
		{
			if (key[KEY_INPUT_A] == 1 || key[KEY_INPUT_D] == 1)
			{
				move = 2.0f;
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

		//�X�N���[������
			//--�ŏ�--//
		if (posX<640)
		{
			scrollX = 0;
		}
		if (posY < 320)
		{
			scrollY = 0;
		}
			//--�ő�--//
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

		//�A�ԉ摜
		if (timer-- <= 0)
		{
			num++;
			timer = time;
			if (num == 6)
			{
				num = 0;
			}
		}

	}
}

void	Player::Draw() {
	if (flag)
	{
		//DrawCircle(posX-scrollX, posY-scrollY, r, GetColor(255,255,255), true);
		DrawRectGraph(posX - r - scrollX, posY - r - scrollY, num * (r * 2), 0, 40, 40, handle, TRUE, FALSE);
		DrawCircle(posX - scrollX, posY - scrollY, range, GetColor(255, 255, 255), false);
	}
	DrawFormatString(0, 80, GetColor(255, 255, 255), "x=%f", scrollX);
	DrawFormatString(0, 100, GetColor(255, 255, 255), "Y=%f", scrollY);
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