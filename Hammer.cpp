#include "Hammer.h"


void	Hammer::Initialize(float	x_, float	y_, float	cX_, float	cY_) {

	posX = x_;
	posY = y_;
	len = 60;
	centerX = cX_;
	centerY = cY_;
	angle = 0;
}

void	Hammer::Update() {
	radius = angle * 3.14f;
	adX = cos(radius)*len;
	adY = sin(radius) * len;
	posX = centerX + adX;
	posY = centerY + adY;
	angle += 3;
}

void	Hammer::Draw() {	
	DrawCircle(posX - player->scrollX, posY - player->scrollY, r, GetColor(0, 255, 0), true);
	//DrawFormatString(200, 0, GetColor(255, 255, 255), "%f", angle);
	
}