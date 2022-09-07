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
			enemy->Initialize(400, 600);
			enemy->SetPlayer(player);
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
		enemy->Update();
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
		DrawCircle(370, 640, 20, GetColor(255, 255, 255), true);
		DrawCircle(370, 640, 120, GetColor(255, 255, 255), false);
		break;

		// �������
	case 1:
		DrawFormatString(0, 0, color, " �������");
		break;

		// �Q�[��
	case 2:
		player->Draw();
		enemy->Draw();
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
	//�G�Ƌz�����ޔ͈͂̓����蔻��
	{
		r1_=player->range;
		x2_=enemy->posX;
		y2_=enemy->posY;
		r2_=enemy->r;
		if (CheckCircle(x1_, y1_, r1_, x2_, y2_, r2_))
		{
			enemy->OnCollision();
		}
	}
	//�G�Ǝ��@�̓����蔻��
	{
		r1_ = player->r;
		x2_ = enemy->posX;
		y2_ = enemy->posY;
		r2_ = enemy->r;
		if (CheckCircle(x1_, y1_, r1_, x2_, y2_, r2_))
		{
			player->OnCollision();
		}

	}
}