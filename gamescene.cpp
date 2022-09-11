#include"gamescene.h"
#include"DxLib.h"

GameScene::GameScene()
{
}

GameScene::~GameScene() {
	delete	player;
	for (size_t i = 0; i < numE; i++)
	{
		delete	enemy_[i];
	}
	delete	map;
	for (size_t i = 0; i < numB; i++)
	{
		delete	box[i];
	}
	delete	goal;
};

void GameScene::Initialize() {
	player = new Player();
	for (size_t i = 0; i < numE; i++)
	{
		enemy_[i] = new	Enemy();
	}
	map = new	Map();
	map->Initialize();
	for (size_t i = 0; i < numB; i++)
	{
		box[i] = new	Box();
	}

	goal = new	Goal;
	goal->Initialize();

	hammer = new	Hammer;
	hammer->Initialize(620, 1420, 620, 1480);
	groundHandle = LoadGraph("./Resources/backGround.png");
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
			for (size_t i = 0; i < numE; i++)
			{
				enemy_[i]->Initialize(enemyPos[i][0], enemyPos[i][1]);
				enemy_[i]->SetPlayer(player);
				map->SetEnemy(enemy_[i], i);
			}
			map->SetPlayer(player);
			for (size_t i = 0; i < numB; i++)
			{
				box[i]->Initialize(boxPos[i][0], boxPos[i][1]);
				box[i]->SetPlayer(player);
				map->SetBox(box[i], i);
			}
			goal->State();
			goal->SetPlayer(player);
			hammer->SetPlayer(player);
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
		map->Update();
		CheckAll();
		player->Update(keys, oldkeys);
		for (size_t i = 0; i < numE; i++)
		{
			enemy_[i]->Update();
		}
		for (size_t i = 0; i < numB; i++)
		{
			box[i]->Update();
		}
		//enemy_[0]->Update();
		
		hammer->Update();

		goal->Update();

		if (goal->flag)
		{
			scene = 3;
		}
		if (!player->flag)
		{
			scene = 4;
		}
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

		break;

		// 操作説明
	case 1:
		DrawFormatString(0, 0, color, " 操作説明");
		break;

		// ゲーム
	case 2:
		player->Draw();
		map->Draw();
		//DrawGraph(0 - player->scrollX, 0 - player->scrollY, groundHandle, true);
		for (size_t i = 0; i < numE; i++)
		{
			enemy_[i]->Draw();
		}
		for (size_t i = 0; i < numB; i++)
		{
			box[i]->Draw();
		}
		//hammer->Draw();

		goal->Draw();
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

void	GameScene::CheckAll() {
	float	x1_ = player->x_;
	float	y1_ = player->y_;
	float	r1_;
	float	x2_;
	float	y2_;
	float	r2_;
	float	w_;
	float	h_;
	for (size_t i = 0; i < numE; i++)
	{
		if (player->flag && enemy_[i]->flag)
		{
			//敵と吸い込む範囲の当たり判定
			{
				r1_ = player->range;
				x2_ = enemy_[i]->posX;
				y2_ = enemy_[i]->posY;
				r2_ = enemy_[i]->r;
				if (CheckCircle(x1_, y1_, r1_, x2_, y2_, r2_))
				{
					enemy_[i]->OnCollision();
				}
			}
			//敵と自機の当たり判定
			{
				//r1_ = player->r;
				//x2_ = enemy_[i]->posX;
				//y2_ = enemy_[i]->posY;
				//r2_ = enemy_[i]->r;
				//if (CheckCircle(x1_, y1_, r1_, x2_, y2_, r2_))
				//{
				//	player->OnCollision();
				//}

			}
		}
	}
	for (size_t i = 0; i < numB; i++)
	{
		if (player->flag)
		{
			//箱と吸い込む範囲の当たり判定
			{
				r1_ = player->range;
				x2_ = box[i]->posX;
				y2_ = box[i]->posY;
				w_ = box[i]->width;
				h_ = box[i]->higth;
				if (CheckCircleDotL(x1_, y1_, r1_, x2_, y2_,w_,h_))
				{
					box[i]->HomingCollision();
					DrawFormatString(200, 200, GetColor(255, 255, 255), "3");
				}
				
			}
			//箱と自機の当たり判定
			{
				r1_ = player->r;
				x2_ = box[i]->posX;
				y2_ = box[i]->posY;
				w_ = box[i]->width;
				h_ = box[i]->higth;
				if (CheckSide1(x1_, y1_, r1_, x2_,y2_,w_,h_) &&
					CheckSide3(x1_, y1_, r1_, x2_, y2_, w_, h_))
				{
					player->MapCollisionX();
					box[i]->OnCollisionX();

				}
				if (CheckSide2(x1_, y1_, r1_, x2_, y2_, w_, h_) &&
					CheckSide4(x1_, y1_, r1_, x2_, y2_, w_, h_))
				{
					player->MapCollisionY();
					box[i]->OnCollisionY();
				}
			}
		}
	}
	{
		r1_ = player->r;
		r2_ = 95;
		x2_ = goal->posX + 95;
		y2_ = goal->posY + 288;
		w_ =  goal->w;
		h_ =  goal->h;

		if (CheckCircle(x1_,y1_,r1_,x2_,y2_,r2_))
		{
			goal->flag = true;
		}
	}
}