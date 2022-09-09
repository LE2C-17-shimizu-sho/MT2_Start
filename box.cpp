#include "box.h"

void	Box::Initialize(float	x_, float	y_) {

	posX = x_;
	posY = y_;
	flag = true;
	rFlag = false;
}

void	Box::Update() {
	oldX = posX;
	oldY = posY;
}

void	Box::Draw() {
	DrawBox(posX - player->scrollX, posY - player->scrollY, posX + width - player->scrollX, posY + higth - player->scrollY, GetColor(170, 70, 0), true);
	//DrawFormatString(200, 0, GetColor(255, 255, 255), "%f", angle);
}

void	Box::OnCollision() {
	OuterProduct(player->x_, posX, player->y_, posY, move);
}