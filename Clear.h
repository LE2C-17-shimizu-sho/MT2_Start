#pragma once
#include"DxLib.h"

class Clear
{
public:
	/// <summary>
	/// ������
	/// </summary>
	void Initialize();

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

