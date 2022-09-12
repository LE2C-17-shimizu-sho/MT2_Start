#pragma once
#include "DxLib.h"

class Title
{
public:
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize(float x, float y);

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

	float titleTime;
	float blendNum = 255;
	float blendNum2;

	bool titleFlag;

	float posX = 0;
	float posY = 0;

private:
	int titleBGM;
	int titleTex;
	int titleFont;
};

