#pragma once
#include "DxLib.h"

class Title
{
public:
	/// <summary>
	/// ������
	/// </summary>
	void Initialize(float x, float y);

	/// <summary>
	/// �X�V����
	/// </summary>
	void Update(int scene);

	/// <summary>
	/// �`�揈��
	/// </summary>
	void Draw();

	/// <summary>
	/// ���Z�b�g�֐�
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

