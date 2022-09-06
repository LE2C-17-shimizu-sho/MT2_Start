#pragma once
#include"player.h"

class GameScene
{
public:
	GameScene();
	~GameScene();
	/// <summary>
	/// ������
	/// </summary>
	void	Initialize();
	/// <summary>
	/// �X�V
	/// </summary>
	void	Update();
	/// <summary>
	/// �`��
	/// </summary>
	void	Draw();
private:
	// �ŐV�̃L�[�{�[�h���p
	char keys[256] = { 0 };

	// 1���[�v(�t���[��)�O�̃L�[�{�[�h���
	char oldkeys[256] = { 0 };
	int scene = 0;
	Player* player;
};