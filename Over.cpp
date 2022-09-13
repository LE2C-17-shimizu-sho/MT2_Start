#include "Over.h"

void Over::Initialize()
{
	title = LoadGraph("./Resources/titleTex.png");
	retry = LoadGraph("./Resources/RetryTex.png");
}

void Over::Draw()
{
	DrawBox(160, 520, 600, 650, GetColor(255, 255, 255), true);
	DrawBox(680, 520, 1120, 650, GetColor(255, 255, 255), true);

	DrawGraph(160, 520, retry, true);
	DrawGraph(680, 520, title, true);
}