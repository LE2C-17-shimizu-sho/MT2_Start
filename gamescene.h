#pragma once
#include"player.h"
#include"enemy.h"
#include"hit.h"
#include"Map.h"
#include"box.h"

const	int	numE=14;
const	int	numB = 2;

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

	void	CheckAll();

private:
	// �ŐV�̃L�[�{�[�h���p
	char keys[256] = { 0 };

	// 1���[�v(�t���[��)�O�̃L�[�{�[�h���
	char oldkeys[256] = { 0 };
	int scene = 0;
	Player* player;
	Enemy* enemy_[numE];
	Map* map;
	Box* box[numB];
	int	groundHandle;
	int	enemyPos[numE][2] = {
		//{650, 1420},
		{620, 1420},
		{512,2816},
		{1664,17992},
		{2496,1856},
		{2432,1280},
		{1664,576},
		{3264,320},
		{3936,1024},
		{4608,384},
		{5184,1024},
		{5120,2176},
		{4096,1920},
		{4352,2752},
		{3264,2496}
	};
	int	boxPos[numB][2] = {
		//{650, 1420},
		{1024, 2688},
		{2688,512}
	};
};