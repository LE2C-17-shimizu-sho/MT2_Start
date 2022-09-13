#include "Title.h"

void Title::Initialize(float x, float y)
{
	posX = x;
	posY = y;

	titleFlag = false;

	titleTex = LoadGraph("./Resources/title.png");
	titleFont = LoadGraph("./Resources/titleFont.png");
	titleLight= LoadGraph("./Resources/titleLight.png");
}

void Title::Update(int scene)
{
	if (scene == 0)
	{
		titleFlag = true;
		if (titleFlag == true)
		{
			blendNum-= 2.0f;
		}
		if (blendNum <= 0.0f)
		{
			blendNum = 0.0f;
		}

	}
	else
	{
		titleFlag == false;
	}
}

void Title::Draw()
{
	DrawBox(posX, posY, posX + 1280, posY + 720, GetColor(255, 255, 255), true);

	//DrawGraph(posX, posY, titleTex, true);
	DrawGraph(0, 0, titleLight, true);
	DrawGraph(posX + 420, posY + 290, titleFont, true);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, blendNum);
	DrawBox(posX, posY, posX + 1280, posY + 720, GetColor(0, 0, 0), true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, blendNum);
}

void Title::Reset()
{
	blendNum = 255.0f;
	titleFlag = false;
}