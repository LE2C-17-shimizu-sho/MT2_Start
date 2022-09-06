#include"enemy.h"


void	Enemy::Initialize(float	x_,float	y_) {
	move = 5;
	r = 20;
	range = 120;
	posX = x_;
	posY = y_;
}

void	Enemy::Update() {
	OuterProduct(player->x_, posX, player->y_, posY, move);
}

void	Enemy::Draw() {
	DrawCircle(posX, posY, r, GetColor(255,0,0), true);
}