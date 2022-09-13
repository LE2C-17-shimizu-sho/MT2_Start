#include "Over.h"

void Over::Initialize()
{
	//over = LoadGraph("./Resources/clear.png");
	//overTex = LoadGraph("./Resources/clearTex.png");
}

void Over::Draw()
{
	DrawBox(160, 520, 600, 650, GetColor(255, 255, 255), true);
	DrawBox(680, 520, 1120, 650, GetColor(255, 255, 255), true);

	//DrawGraph(0, 0, over, true);
	//DrawGraph(700, 140, overTex, true);
}