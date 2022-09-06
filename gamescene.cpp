#include"gamescene.h"
#include"DxLib.h"

GameScene::GameScene()
{
}

GameScene::~GameScene() {
	delete	player;
	delete	enemy;
};

void GameScene::Initialize() {
	player = new Player();
	player->Initialize();
	enemy = new	Enemy();
	
}

void GameScene::Update() {

	// 最新のキーボード情報だったものは1フレーム前のキーボード情報として保存
	for (int i = 0; i < 256; ++i)
	{
		oldkeys[i] = keys[i];
	}
	// 最新のキーボード情報を取得
	GetHitKeyStateAll(keys);
	//---------  ここからにプログラムを記述  ---------//
	switch (scene)
	{
		// タイトル
	case 0:
		if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0)
		{
			scene = 1;
			player->State();
			enemy->Initialize(600, 400);
		}
		break;

		// 操作説明
	case 1:
		if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0)
		{
			scene = 2;
		}
		break;

		// ゲーム
	case 2:

		player->Update(keys, oldkeys);
		enemy->Update();
		if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0)
		{
			scene = 3;
		}
		break;

		// リザルト(クリア)
	case 3:
		if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0)
		{
			scene = 0;
		}
		break;

		// リザルト(ゲームオーバー)
	case 4:
		if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0)
		{
			scene = 0;
		}
		break;
	}
}

void	GameScene::Draw() {
	unsigned int color = GetColor(255, 255, 255);
	switch (scene)
	{
		// タイトル
	case 0:
		DrawFormatString(0, 0, color, "タイトル");
		DrawCircle(370, 640, 20, GetColor(255, 255, 255), true);
		DrawCircle(370, 640, 120, GetColor(255, 255, 255), false);
		break;

		// 操作説明
	case 1:
		DrawFormatString(0, 0, color, " 操作説明");
		break;

		// ゲーム
	case 2:
		player->Draw();
		enemy->Draw();
		DrawFormatString(0, 0, color, "ゲーム");
		break;

		// リザルト(クリア)
	case 3:
		DrawFormatString(0, 0, color, "クリア");
		break;

		// リザルト(ゲームオーバー)
	case 4:
		DrawFormatString(0, 0, color, "オーバー");
		break;
	}
	DrawFormatString(0, 30, color, "scene = %d", scene);
}