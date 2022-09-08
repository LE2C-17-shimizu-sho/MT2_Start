#include "Title.h"

void Title::Initialize()
{
	title = LoadGraph("./Resources/title.png");
}

void Title::Update()
{
}

void Title::Draw()
{
	DrawGraph(0, 0, title, true);
}
