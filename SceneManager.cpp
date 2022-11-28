#include "SceneManager.h"
#include "DxLib.h"

// �ŐV�̃L�[�{�[�h���p
char keys[256] = { 0 };

// 1���[�v(�t���[��)�O�̃L�[�{�[�h���
char oldkeys[256] = { 0 };

void SceneManager::ChangeScene(int& sceneNo)
{
	GetHitKeyStateAll(keys);
	switch (sceneNo)
	{
	case 0: // TitleScene
		DrawBox(0, 0, 600, 400, GetColor(255, 50, 50), true);
		if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0)
		{
			// ���̃V�[����
			sceneNo = 1;
		}
		break;

	case 1: // NewGameScene
		DrawBox(0, 0, 600, 400, GetColor(50, 255, 50), true);
		if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0)
		{
			// ���̃V�[����
			sceneNo = 2;
		}
		break;

	case 2: // GamePlayScene
		DrawBox(0, 0, 600, 400, GetColor(50, 50, 255), true);
		if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0)
		{
			// ���̃V�[����
			sceneNo = 3;
		}
		break;

	case 3: // GameClearScene
		DrawBox(0, 0, 600, 400, GetColor(50, 50, 50), true);
		if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0)
		{
			// �ŏ��̃V�[����
			sceneNo = 0;
		}
		break;
	}

	int Cr = GetColor(255, 255, 255);
	DrawFormatString(50, 50, Cr, "SceneNo: %d", sceneNo);
	DrawFormatString(50, 70, Cr, "Press Space to Scene Change");
}

SceneManager* SceneManager::GetInstance()
{
	static SceneManager instance;
	return &instance;
}
