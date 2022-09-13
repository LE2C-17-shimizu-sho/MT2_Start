#pragma once
#include"DxLib.h"

class Story
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

