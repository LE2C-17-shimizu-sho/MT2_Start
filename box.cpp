#include "box.h"

void	Box::Initialize() {
	handle = LoadGraph("./Resources/box.png");

}

void	Box::State(float	x_, float	y_) {
	posX = x_;
	posY = y_;
	flag = true;
	mapFlag = false;
	moveFlag = false;
}

void	Box::Update() {
	oldX = posX;
	oldY = posY;
	
	mapFlag = false;
	if (posX < 320)
	{
		posX = 320;
		mapFlag = true;
	}
	if (!moveFlag||mapFlag)
	{
		move = 0.0f;
	}
	moveFlag = false;
}

void	Box::Draw() {
	DrawBox(posX - player->scrollX, posY - player->scrollY, posX + width - player->scrollX, posY + higth - player->scrollY, GetColor(170, 70, 0), true);
	DrawGraph(posX - player->scrollX, posY - player->scrollY, handle, true);
	//DrawFormatString(200, 0, GetColor(255, 255, 255), "%f", angle);
}

void	Box::OnCollisionX() {
	posX = oldX;
	mapFlag = true;
}

void	Box::OnCollisionY() {
	posY = oldY;
	mapFlag = true;
}

void	Box::HomingCollision() {
	moveFlag = true;
	if (!mapFlag&&moveFlag)
	{
		move += 0.05f;
		if (move>2.5f)
		{
			move = 2.5f;
		}
		posX -= move;
		//OuterProduct(player->x_, posX, player->y_, posY, move);
	}

}