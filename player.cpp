#include"player.h"


void	Player::Initialize() {
	move = 5;
	r = 20;
	range = 120;
}

void	Player::State() {
	posX = 580;
	posY = 260;
	flag = true;
	x_ = 0;
	y_ = 0;
}

void	Player::Update(char	key[], char	oldkey[]) {
	move = 4;
	//���������ŃX�s�[�h�ύX
	if (key[KEY_INPUT_W]==1|| key[KEY_INPUT_S] == 1)
	{
		if ( key[KEY_INPUT_A] == 1 || key[KEY_INPUT_D] == 1)
		{
			move = 2;
		}
	}

	//�ړ�����
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

void	Player::Draw() {
	DrawCircle(posX, posY, r, GetColor(255, 255, 255), true);
	DrawCircle(posX, posY, range, GetColor(255, 255, 255), false);
	DrawFormatString(0, 80, GetColor(255, 255, 255), "x=%f", posX);
	DrawFormatString(0, 100, GetColor(255, 255, 255), "Y=%f", posY);
}