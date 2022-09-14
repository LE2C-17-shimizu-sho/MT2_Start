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
	for (size_t i = 0; i < numH; i++)
	{
		delete	hammer[i];
	}
};

void GameScene::Initialize() {
	//プレイヤー
	player = new Player();

	//敵
	for (size_t i = 0; i < numE; i++)
	{
		enemy_[i] = new	Enemy();
		enemy_[i]->Initialize();
		time[i] = 0;
		time2[i] = 0;
		seFlagE[i] = 0;
	}

	//マップ
	map = new	Map();
	map->Initialize();

	//木箱
	for (size_t i = 0; i < numB; i++)
	{
		box[i] = new	Box();
		box[i]->Initialize();
		time3[i] = 0;
		seFlagB[i] = 0;
	}

	//ゴール
	goal = new	Goal;
	goal->Initialize();

	//回転するやつ
	for (size_t i = 0; i < numH; i++)
	{
		hammer[i] = new	Hammer;
		hammer[i]->Initialize(hammerPos[i][0], hammerPos[i][1], 200);
	}

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
	over->Initialize();

	//パーティクル
	particle = new	Particle;
	particle->Initialize();

	//BGMのフラグ
	soundFlag = 0;
	//SEフラグ
	seFlag = 0;
	
	//画像
	groundHandle = LoadGraph("./Resources/backGround.png");
	opeHandle= LoadGraph("./Resources/ope.png");
	bgHandle= LoadGraph("./Resources/storyBg.png");

	//BGM
	titleHandle = LoadSoundMem("./music/title.wav");
	gamesceneHandle = LoadSoundMem("./music/gamescene.wav");
	clearHandle = LoadSoundMem("./music/clear.mp3");
	//SE
	bikkuriHandle = LoadSoundMem("./music/bikkuri.mp3");	//1
	questionHandle = LoadSoundMem("./music/question.mp3");	//2
	kibakoHandle = LoadSoundMem("./music/kibako.mp3");		//3
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
			for (size_t i = 0; i < numH; i++)
			{
				hammer[i]->SetPlayer(player);
			}
			story->Reset();
			particle->SetPlayer(player);
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
		particle->State();
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
		for (size_t i = 0; i < numH; i++)
		{
			hammer[i]->Update();
		}

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
		break;

		// リザルト(クリア)
	case 4:
		StopSoundMem(kibakoHandle);
		StopSoundMem(questionHandle);
		StopSoundMem(bikkuriHandle);
		clear->Update(scene);
		if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0)
		{
			scene = 0;
			title->Reset();
		}
		break;

		// リザルト(ゲームオーバー)
	case 5:
		particle->Move();
		StopSoundMem(kibakoHandle);
		StopSoundMem(questionHandle);
		StopSoundMem(bikkuriHandle);
		if (keys[KEY_INPUT_R] == 1 && oldkeys[KEY_INPUT_R] == 0)
		{
			soundFlag = 2;
			scene = 3;
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
			for (size_t i = 0; i < numH; i++)
			{
				hammer[i]->SetPlayer(player);
			}
			story->Reset();
		}
		if (keys[KEY_INPUT_T] == 1 && oldkeys[KEY_INPUT_T] == 0)
		{
			scene = 0;
			title->Reset();
		}
		break;
	}

	//BGM
	switch (scene)
	{
		case 0:
			if (soundFlag == 0) 
			{
				StopSoundMem(gamesceneHandle);
				if (CheckSoundMem(titleHandle) == 0)
				{
					PlaySoundMem(titleHandle, DX_PLAYTYPE_LOOP, true);
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
					PlaySoundMem(gamesceneHandle, DX_PLAYTYPE_LOOP, true);
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
	//SE
	switch (seFlag)
	{
	case	1:
		for (size_t i = 0; i < numE; i++)
		{
			if (time2[i] == 5 && CheckSoundMem(bikkuriHandle) == 0)
			{
				PlaySoundMem(bikkuriHandle, DX_PLAYTYPE_BACK, true);
				ChangeVolumeSoundMem(80, bikkuriHandle);
				seFlag = 0;
			}
		}
		break;
	case	2:
		for (size_t i = 0; i < numE; i++)
		{
				
			if (time[i] == 5 && CheckSoundMem(questionHandle) == 0)
			{
				PlaySoundMem(questionHandle, DX_PLAYTYPE_BACK, true);
				ChangeVolumeSoundMem(80, questionHandle);
				seFlag = 0;
			}
		}
		break;
	case	3:
		for (size_t i = 0; i < numB; i++)
		{
			if (time3[i] == 5 && CheckSoundMem(questionHandle) == 0)
			{
				PlaySoundMem(kibakoHandle, DX_PLAYTYPE_BACK, true);
				ChangeVolumeSoundMem(100, kibakoHandle);
				seFlag = 0;
			}
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
		title->Draw();

		break;
	case 1:
		story->Draw();
		break;
		// 操作説明
	case 2:
		DrawGraph(0, 0,bgHandle , true);
		DrawGraph(0, 0, opeHandle, true);
		break;

		// ゲーム
	case 3:
		map->Draw();
		DrawGraph(0 - player->scrollX, 0 - player->scrollY, groundHandle, true);
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
		DrawCircle(player->x_ - player->scrollX, player->y_ - player->scrollY, player->range, GetColor(120, 120, 255), true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 100);
		for (size_t i = 0; i < numE; i++)
		{
			enemy_[i]->Draw();
		}
		for (size_t i = 0; i < numB; i++)
		{
			box[i]->Draw();
		}
		for (size_t i = 0; i < numH; i++)
		{
			hammer[i]->Draw();
		}

		goal->Draw();
		player->Draw();
		break;

		// リザルト(クリア)
	case 4:
		clear->Draw();
		break;

		// リザルト(ゲームオーバー)
	case 5:
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
		for (size_t i = 0; i < numH; i++)
		{
			hammer[i]->Draw();
		}

		goal->Draw();
		player->Draw();
		over->Draw();
		particle->Draw();
		break;
	}
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
	//敵とプレイヤー
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
					seFlag = 2;
					time[i]++;
				}
				else
				{
					time[i] = 0;
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
					if (seFlag == 2)
					{
						seFlag = 1;
					}
					time2[i]++;
					seFlagE[i] = 1;
				}
				else
				{
					if (seFlagE[i])
					{
						StopSoundMem(bikkuriHandle);
						seFlagE[i] = 0;
					}
					//seFlag=0
					time2[i] = 0;
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
	//木箱とプレイヤー
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
					seFlag = 3;
					seFlagB[i] = 1;
					time3[i]++;
				}
				else
				{
					if (seFlagB[i])
					{
						StopSoundMem(kibakoHandle);
						seFlagB[i] = 0;
					}
					time3[i] = 0;
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
	//スピナーとプレイヤー
	{
		for (size_t i = 0; i < numH; i++)
		{

			for (size_t j = 0; j < 3; j++)
			{
				r1_ = player->r;
				x2_ = hammer[i]->posX[j];
				y2_ = hammer[i]->posY[j];
				r2_ = hammer[i]->r;
				if (CheckCircle(x1_, y1_, r1_, x2_, y2_, r2_))
				{
					player->OnCollision();
				}
			}
		}
	}
}