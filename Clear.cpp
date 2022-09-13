#include "Clear.h"

void Clear::Initialize()
{
	posX = 0;
	posY = 0;

	clearFlag = false;

	clear = LoadGraph("./Resources/clear.png");
	clearTex = LoadGraph("./Resources/clearTex.png");
}

void Clear::Update(int scene)
{
	if (scene == 4)
	{
		clearFlag = true;
		if (clearFlag == true)
		{
			blendNum -= 2.0f;
		}
		if (blendNum <= 0.0f)
		{
			blendNum = 0.0f;
		}

	}
	else
	{
		clearFlag == false;
	}
}

void Clear::Draw()
{
	DrawBox(posX, posY, posX + 1280, posY + 720, GetColor(0, 0, 255), true);
	//DrawGraph(posX, posY, titleTex, true);
	DrawGraph(0, 0, clear, true);
	DrawGraph(700, 140, clearTex, true);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, blendNum);
	DrawBox(posX, posY, posX + 1280, posY + 720, GetColor(0, 0, 0), true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, blendNum);
}

void Clear::Reset()
{
	blendNum = 255.0f;
	clearFlag = false;
}