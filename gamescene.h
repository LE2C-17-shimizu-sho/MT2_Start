#pragma once
#include"player.h"
#include"enemy.h"
#include"hit.h"

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
	Enemy* enemy;
	int	groundHandle;
};