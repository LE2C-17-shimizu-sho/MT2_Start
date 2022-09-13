#pragma once
#include"player.h"
#include"enemy.h"
#include"hit.h"
#include"Map.h"
#include"box.h"
#include"Goal.h"
#include"Hammer.h"
#include"Title.h"
#include"Clear.h"
#include"Story.h"
#include"Over.h"
#include"Particle.h"

const	int	numE=14;
const	int	numB = 2;
const	int	numH = 3;

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
	Goal* goal;
	Hammer* hammer[numH];
	Title* title;
	Clear* clear;
	Story* story;
	Over* over;
	Particle* particle;

	//��
	int titleHandle;
	int gamesceneHandle;
	int clearHandle;
	int bikkuriHandle;
	int questionHandle;
	int kibakoHandle;
	//�t���O
	int soundFlag;

	int	seFlag;
	int	seFlagE[numE];
	int	seFlagB[numB];

	//�摜
	int	groundHandle;
	int	opeHandle;
	int	bgHandle;


	int	time[numE];
	int	time2[numE];
	int	time3[numB];

	int	enemyPos[numE][2] = {
		//{650, 1420},
		{620, 1420},
		{542,2816},
		{2584 ,750},
		{2584,400},
		{1916,1806},
		{3722,340},
		{3454,442},
		{4542,288},
		{4720,544},
		{5300,1024},
		{4984,1880},
		{4210,2078},
		{3962,1754},
		{3578,2738}
	};
	int	boxPos[numB][2] = {
		//{650, 1420},
		{1030, 2694},
		{2688,448}
	};
	int	hammerPos[numH][2] = {
		{4984, 1858},
		{4210,2078},
		{3578,2738}
	};
};