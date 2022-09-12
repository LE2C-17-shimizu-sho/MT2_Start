#include "Hammer.h"


void	Hammer::Initialize( float	cX_, float	cY_) {

	len = 120;
	centerX = cX_;
	centerY = cY_;
	angle[0] = 0;
	angle[1] = 120;
	angle[2] = 240;
}

void	Hammer::Update() {
	for (size_t i = 0; i < 3; i++)
	{
		radius = angle[i] * 3.14f / 180.0f;
		adX = cos(radius)*len;
		adY = sin(radius) * len;
		posX[i] = centerX + adX;
		posY[i] = centerY + adY;
		angle[i] += 1;

	}
}

void	Hammer::Draw() {	
	for (size_t i = 0; i < 3; i++)
	{
		DrawCircle(posX[i] - player->scrollX, posY[i] - player->scrollY, r, GetColor(0, 255, 0), true);
		//DrawFormatString(200, 0, GetColor(255, 255, 255), "%f", angle);
	}
}