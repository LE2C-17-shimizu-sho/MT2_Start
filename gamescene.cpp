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
	groundHandle = LoadGraph("./Resources/backGround.png");
}

void GameScene::Update() {

	// �ŐV�̃L�[�{�[�h��񂾂������̂�1�t���[���O�̃L�[�{�[�h���Ƃ��ĕۑ�
	for (int i = 0; i < 256; ++i)
	{
		oldkeys[i] = keys[i];
	}
	// �ŐV�̃L�[�{�[�h�����擾
	GetHitKeyStateAll(keys);
	//---------  ��������Ƀv���O�������L�q  ---------//
	switch (scene)
	{
		// �^�C�g��
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
			}
		}
		break;

		// �������
	case 1:
		if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0)
		{
			scene = 2;
		}
		break;

		// �Q�[��
	case 2:
		CheckAll();
		player->Update(keys, oldkeys);
		
		
		//enemy_[0]->Update();
		
		map->Update();

		if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0)
		{
			scene = 3;
		}
		break;

		// ���U���g(�N���A)
	case 3:
		if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0)
		{
			scene = 0;
		}
		break;

		// ���U���g(�Q�[���I�[�o�[)
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
		// �^�C�g��
	case 0:
		DrawFormatString(0, 0, color, "�^�C�g��");

		break;

		// �������
	case 1:
		DrawFormatString(0, 0, color, " �������");
		break;

		// �Q�[��
	case 2:
		DrawGraph(0 - player->scrollX, 0 - player->scrollY, groundHandle, true);
		player->Draw();
		for (size_t i = 0; i < numE; i++)
		{
			enemy_[i]->Draw();
		}
		for (size_t i = 0; i < numB; i++)
		{
			box[i]->Draw();
		}
		map->Draw();
		DrawFormatString(0, 0, color, "�Q�[��");
		break;

		// ���U���g(�N���A)
	case 3:
		DrawFormatString(0, 0, color, "�N���A");
		break;

		// ���U���g(�Q�[���I�[�o�[)
	case 4:
		DrawFormatString(0, 0, color, "�I�[�o�[");
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
			//�G�Ƌz�����ޔ͈͂̓����蔻��
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
			//�G�Ǝ��@�̓����蔻��
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
			//���Ƌz�����ޔ͈͂̓����蔻��
			{
				r1_ = player->range;
				x2_ = box[i]->posX;
				y2_ = box[i]->posY;
				w_ = box[i]->width;
				h_ = box[i]->higth;
				if (CheckCircleDot4(x1_, y1_, r1_, x2_, y2_,w_,h_))
				{
					DrawFormatString(0, 180, GetColor(255, 255, 255), "hit");
				}
				
			}
			//�G�Ǝ��@�̓����蔻��
			{
				//r1_ = player->r;
				//x2_ = box[i]->posX;
				//y2_ = box[i]->posY;
				//r2_ = box[i]->r;
				//if (CheckCircle(x1_, y1_, r1_, x2_, y2_, r2_))
				//{
				//	player->OnCollision();
				//}

			}
		}
	}
}