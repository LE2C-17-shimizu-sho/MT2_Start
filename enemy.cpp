#include"enemy.h"


void	Enemy::Initialize(float	x_,float	y_) {
	move = 3.4;
	r = 20;
	range = 120;
	posX = x_;
	posY = y_;
	collisionFlag = false;
}

void	Enemy::Update() {

}

void	Enemy::Draw() {
	DrawCircle(posX, posY, r, GetColor(255,0,0), true);
}

void	Enemy::OnCollision() {
	OuterProduct(player->x_, posX, player->y_, posY, move);
}