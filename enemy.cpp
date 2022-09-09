#include"enemy.h"


void	Enemy::Initialize(float	x_,float	y_) {

	posX = x_;
	posY = y_;
	flag = true;
	rFlag = false;
}

void	Enemy::Update() {
	
}

void	Enemy::Draw() {
	if (flag)
	{
		DrawCircle(posX-player->scrollX, posY - player->scrollY, r, GetColor(0,255,0), true);
		//DrawFormatString(200, 0, GetColor(255, 255, 255), "%f", angle);
	}
}

void	Enemy::OnCollision() {
	if (flag)
	{
		rFlag = false;
		OuterProduct(player->x_, posX, player->y_, posY, move);
	}
}

void	Enemy::DeathCollision() {
	flag = false;
}