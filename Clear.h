#pragma once
#include"DxLib.h"

class Clear
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

	float clearTime;
	float blendNum = 255;
	float blendNum2;

	bool clearFlag;

	float posX = 0;
	float posY = 0;

private:
	int clearBGM;
	int clearTex;
	int clear;
	int	space;
};

