#pragma once
#include"player.h"
#include"enemy.h"
#include"hit.h"
#include"Map.h"

const	int	numE=14;

class GameScene
{
public:
	GameScene();
	~GameScene();
	/// <summary>
	/// 初期化
	/// </summary>
	void	Initialize();
	/// <summary>
	/// 更新
	/// </summary>
	void	Update();
	/// <summary>
	/// 描画
	/// </summary>
	void	Draw();

	void	CheckAll();

private:
	// 最新のキーボード情報用
	char keys[256] = { 0 };

	// 1ループ(フレーム)前のキーボード情報
	char oldkeys[256] = { 0 };
	int scene = 0;
	Player* player;
	Enemy* enemy[numE];
	Map* map;
	int	groundHandle;
	int	enemyPos[numE][2] = {
		{650, 1420},
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
};