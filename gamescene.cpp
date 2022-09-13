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
	//プレイヤー
	player = new Player();
	//敵
	for (size_t i = 0; i < numE; i++)
	{
		enemy_[i] = new	Enemy();
		enemy_[i]->Initialize();
	}
	//マップ
	map = new	Map();
	map->Initialize();
	for (size_t i = 0; i < numB; i++)
	{
		box[i] = new	Box();
		box[i]->Initialize();
	}
	//ゴール
	goal = new	Goal;
	goal->Initialize();
	//回転するやつ
	hammer = new	Hammer;
	hammer->Initialize( 520, 380);
	//タイトル
	title = new	Title;
	title->Initialize(0, 0);
	//クリア
	clear = new	Clear;
	clear->Initialize();
	//ストーリー
	story = new	Story;
	story->Initialize();
	//オーバー
	over = new	Over;
	//over->Initialize();
	//BGMのフラグ
	soundFlag = 0;
	//SEフラグ
	seFlag = 0;
	//プレイ画面の背景
	groundHandle = LoadGraph("./Resources/backGround.png");
	//BGM
	titleHandle = LoadSoundMem("./music/title.wav");
	gamesceneHandle = LoadSoundMem("./music/gamescene.wav");
	clearHandle = LoadSoundMem("./music/clear.mp3");
	//SE
	bikkuriHandle = LoadSoundMem("./music/bikkuri.mp3");
	questionHandle = LoadSoundMem("./music/question.mp3");
	kibakoHandle = LoadSoundMem("./music/kibako.mp3");
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
		title->Update(scene);
		if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0)
		{
			scene = 1;
			player->State();
			for (size_t i = 0; i < numE; i++)
			{
				enemy_[i]->State(enemyPos[i][0], enemyPos[i][1]);
				enemy_[i]->SetPlayer(player);
				map->SetEnemy(enemy_[i], i);
			}
			map->SetPlayer(player);
			for (size_t i = 0; i < numB; i++)
			{
				box[i]->State(boxPos[i][0], boxPos[i][1]);
				box[i]->SetPlayer(player);
				map->SetBox(box[i], i);
			}
			goal->State();
			goal->SetPlayer(player);
			hammer->SetPlayer(player);
			story->Reset();
		}
		break;
		//ストーリー
	case 1:
		story->Update(scene);
		if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0)
		{
			scene = 2;
		}
		break;
		// 操作説明
	case 2:
		if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0)
		{
			scene = 3;
		}
		break;

		// ゲーム
	case 3:
		#pragma	region	アップデート
		for (size_t i = 0; i < numE; i++)
		{
			enemy_[i]->markFlag = 0;
		}
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
		map->Update();
		CheckAll();
		#pragma	endregion

		if (goal->flag)//クリア
		{
			scene = 4;
			clear->Reset();
		}
		if (!player->flag)//オーバー
		{
			scene = 5;
		}
		if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0)
		{
			scene = 4;
		}
		break;

		// リザルト(クリア)
	case 4:
		clear->Update(scene);
		if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0)
		{
			scene = 0;
			title->Reset();
		}
		break;

		// リザルト(ゲームオーバー)
	case 5:
		if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0)
		{
			scene = 0;
			title->Reset();
		}
		break;
	}

	//BGM、効果音
	switch (scene)
	{
		case 0:
			if (soundFlag == 0) 
			{
				StopSoundMem(gamesceneHandle);
				if (CheckSoundMem(titleHandle) == 0)
				{
					PlaySoundMem(titleHandle, DX_PLAYTYPE_BACK, true);
					ChangeVolumeSoundMem(256, titleHandle);
				}
				soundFlag += 1;
			}

			break;

		case 1:
			if (soundFlag == 1)
			{
				ChangeVolumeSoundMem(200, titleHandle);
				soundFlag += 1;
			}

			break;

		case 2:

			break;

		case 3:
			if (soundFlag == 2)
			{
				StopSoundMem(titleHandle);
				if (CheckSoundMem(gamesceneHandle) == 0)
				{
					PlaySoundMem(gamesceneHandle, DX_PLAYTYPE_BACK, true);
				}
				ChangeVolumeSoundMem(180, gamesceneHandle);
				soundFlag += 1;
			}

			break;

		case 4:
			if (soundFlag == 3) 
			{
				StopSoundMem(gamesceneHandle);
				if (CheckSoundMem(clearHandle) == 0)
				{
					PlaySoundMem(clearHandle, DX_PLAYTYPE_BACK, true);
				}
				soundFlag = 0;
			}

			break;

		case 5:

			soundFlag = 0;

			break;
	}
}

void	GameScene::Draw() {
	unsigned int color = GetColor(255, 255, 255);
	switch (scene)
	{
		// タイトル
	case 0:
		title->Draw();
		DrawFormatString(0, 0, color, "タイトル");

		break;
	case 1:
		story->Draw();
		DrawFormatString(0, 0, color, "ストーリー");
		break;
		// 操作説明
	case 2:
		DrawFormatString(0, 0, color, " 操作説明");
		break;

		// ゲーム
	case 3:
		map->Draw();
		DrawGraph(0 - player->scrollX, 0 - player->scrollY, groundHandle, true);
		for (size_t i = 0; i < numE; i++)
		{
			enemy_[i]->Draw();
		}
		for (size_t i = 0; i < numB; i++)
		{
			box[i]->Draw();
		}
		hammer->Draw();

		goal->Draw();
		player->Draw();
		DrawFormatString(0, 0, color, "ゲーム");
		DrawFormatString(0, 10, color, "%d",enemy_[0]->markFlag);
		break;

		// リザルト(クリア)
	case 4:
		clear->Draw();
		DrawFormatString(0, 0, color, "クリア");
		break;

		// リザルト(ゲームオーバー)
	case 5:
		DrawFormatString(0, 0, color, "オーバー");
		map->Draw();
		DrawGraph(0 - player->scrollX, 0 - player->scrollY, groundHandle, true);
		for (size_t i = 0; i < numE; i++)
		{
			enemy_[i]->Draw();
		}
		for (size_t i = 0; i < numB; i++)
		{
			box[i]->Draw();
		}
		hammer->Draw();

		goal->Draw();
		player->Draw();
		over->Draw();
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
			//敵と?を出す範囲の当たり判定
			{
				r1_ = player->range2;
				x2_ = enemy_[i]->posX;
				y2_ = enemy_[i]->posY;
				r2_ = enemy_[i]->r;
				if (CheckCircle(x1_, y1_, r1_, x2_, y2_, r2_))
				{
					enemy_[i]->markCollision();
				}
			}
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
				r1_ = player->r;
				x2_ = enemy_[i]->posX;
				y2_ = enemy_[i]->posY;
				r2_ = enemy_[i]->r;
				if (CheckCircle(x1_, y1_, r1_, x2_, y2_, r2_))
				{
					player->OnCollision();
				}

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
		for (size_t j = 0; j < numE; j++)
		{
			r1_ = enemy_[j]->r;
			x2_ = box[i]->posX;
			y2_ = box[i]->posY;
			w_ = box[i]->width;
			h_ = box[i]->higth;
			if (CheckBoxCircle(enemy_[j]->posX, enemy_[j]->posY,r1_,x2_,y2_,w_,h_))
			{
				enemy_[j]->OnCollisionXY();
				box[i]->OnCollisionX();
				box[i]->OnCollisionY();
			}

		}
	}
	//ゴールとプレイヤー
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