#include"enemy.h"


void	Enemy::Initialize() {
	LoadDivGraph("./Resources/enemy.png", 4, 4, 1, 80, 80, handle);
	bikkuriHandle = LoadGraph("./Resources/bikkuri.png");
	hatenaHandle= LoadGraph("./Resources/hatena.png");
}

void	Enemy::State(float	x_, float	y_) {

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
	markFlag == 0;
	if (timer-- <= 0)
	{
		num++;
		timer = time;
		if (num == 4)
		{
			num = 0;
		}
	}
}

void	Enemy::Draw() {
	if (flag)
	{
		DrawCircle(posX-player->scrollX, posY - player->scrollY, r, GetColor(0,255,0), true);
		DrawGraph(posX - r - player->scrollX, posY - r - player->scrollY, handle[num], true);
		if (markFlag == 1)
		{
			DrawGraph(posX -r - player->scrollX, posY - (r+10)- player->scrollY, hatenaHandle, true);
		}
		else if (markFlag == 2)
		{
			DrawGraph(posX - r- player->scrollX, posY - (r+10)- player->scrollY, bikkuriHandle, true);
		}
		//DrawFormatString(200, 0, GetColor(255, 255, 255), "%f", angle);
	}
}

void	Enemy::OnCollision() {
	markFlag = 2;
	OuterProduct(player->x_, posX, player->y_, posY, move,bFlag);
	
}

void	Enemy::OnCollisionX() {
	posX = posX+0.5;
	bFlag = 1;
}
void	Enemy::OnCollisionY() {
	posY = posY + +0.5;
	bFlag = 2;
}
void	Enemy::OnCollisionX2() {
	posX = posX - +0.5;
	bFlag = 1;
}
void	Enemy::OnCollisionY2() {
	posY = posY - +0.5;
	bFlag = 2;
}

void	Enemy::DeathCollision() {
	flag = false;
}
void	Enemy::OnCollisionXY() {
	posX = oldX[1];
	posY = oldY[1];
	bFlag = 3;
}

void	Enemy::markCollision() {
	markFlag = 1;
}