#include "Hammer.h"


void	Hammer::Initialize( float	cX_, float	cY_,float	len_) {
	LoadDivGraph("./Resources/hammer.png", 4, 4, 1, 80, 80, handle);
	len = len_;
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

void	Hammer::Draw() {	
	for (size_t i = 0; i < 3; i++)
	{
		
		DrawGraph(posX[i] - r - player->scrollX, posY[i] - r - player->scrollY,handle[num], true);
	}
}