#include"enemy.h"


void	Enemy::Initialize(float	x_,float	y_) {

	posX = x_;
	posY = y_;
	flag = true;
}

void	Enemy::Update() {

	oldX[1] = oldX[0];
	oldY[1] = oldY[0];
	oldX[0] = posX;
	oldY[0] = posY;
	bFlag = 0;
}

void	Enemy::Draw() {
	if (flag)
	{
		DrawCircle(posX-player->scrollX, posY - player->scrollY, r, GetColor(0,255,0), true);
		//DrawFormatString(200, 0, GetColor(255, 255, 255), "%f", angle);
	}
}

void	Enemy::OnCollision() {
	
	OuterProduct(player->x_, posX, player->y_, posY, move,bFlag);
	
}

void	Enemy::OnCollisionX() {
	posX = oldX[1];
	bFlag = 1;
}
void	Enemy::OnCollisionY() {
	posY = oldY[1];
	bFlag = 2;
}

void	Enemy::DeathCollision() {
	flag = false;
}