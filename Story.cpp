#include "Story.h"

void Story::Initialize()
{
	posX = 0;
	posY = 0;

	storyFlag = false;

	story = LoadGraph("./Resources/storyBg.png");
	storyTex = LoadGraph("./Resources/story.png");
}

void Story::Update(int scene)
{
	if (scene == 1)
	{
		storyFlag = true;
		if (storyFlag == true)
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
		storyFlag == false;
	}
}

void Story::Draw()
{
	DrawBox(posX, posY, posX + 1280, posY + 720, GetColor(0, 0, 255), true);
	//DrawGraph(posX, posY, titleTex, true);
	DrawGraph(0, 0, story, true);
	DrawGraph(0, 0, storyTex, true);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, blendNum);
	DrawBox(posX, posY, posX + 1280, posY + 720, GetColor(0, 0, 0), true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, blendNum);
}

void Story::Reset()
{
	blendNum = 255.0f;
	storyFlag = false;
}