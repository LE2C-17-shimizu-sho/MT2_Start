#include"player.h"
#include"DxLib.h"

void	Player::Initialize() {
	move = 10;
	r = 20;
	range = 120;
}

void	Player::State() {
	posX = 300;
	posY = 300;
	flag = true;
}

void	Player::Update(char	key[], char	oldkey[]) {
	if (key[KEY_INPUT_W]==1)
	{
		posY -= move;
	}
	if (key[KEY_INPUT_S]==1)
	{
		posY += move;
	}
	if (key[KEY_INPUT_A]==1)
	{
		posX -= move;
	}
	if (key[KEY_INPUT_D] ==1)
	{
		posX += move;
	}
}

void	Player::Draw() {
	DrawCircle(posX, posY, r, GetColor(255, 255, 255), true);
	DrawCircle(posX, posY, range, GetColor(255, 255, 255), false);
}