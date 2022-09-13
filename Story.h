#pragma once
#include"DxLib.h"

class Story
{
public:
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 更新処理
	/// </summary>
	void Update(int scene);

	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw();

	/// <summary>
	/// リセット関数
	/// </summary>
	void Reset();

	float storyTime;
	float blendNum = 255;
	float blendNum2;

	bool storyFlag;

	float posX = 0;
	float posY = 0;

private:
	int storyBGM;
	int storyTex;
	int story;
};

