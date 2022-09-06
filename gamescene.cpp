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
			enemy->Initialize(600, 400);
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