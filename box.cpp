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
	x_ = posX - width / 2;
	y_ = posY - higth / 2;
}

void	Box::Draw() {
	DrawBox(posX - player->scrollX, posY - player->scrollY, posX + width - player->scrollX, posY + higth - player->scrollY, GetColor(170, 70, 0), true);
	//DrawFormatString(200, 0, GetColor(255, 255, 255), "%f", angle);
}

void	Box::OnCollisionX() {
	posX = oldX;
}

void	Box::OnCollisionY() {
	posY = oldY;
}

void	Box::HomingCollision() {
	posX -= move;
}