#include "SceneManager.h"
#include "DxLib.h"

// 最新のキーボード情報用
char keys[256] = { 0 };

// 1ループ(フレーム)前のキーボード情報
char oldkeys[256] = { 0 };

void SceneManager::ChangeScene(int& sceneNo)
{
	// 最新のキーボード情報だったものは1フレーム前のキーボード情報として保存
	for (int i = 0; i < 256; ++i)
	{
		oldkeys[i] = keys[i];
	}

	GetHitKeyStateAll(keys);

	switch (sceneNo)
	{
	case 0: // TitleScene
		DrawBox(0, 0, 600, 400, GetColor(222, 56, 56), true);
		if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0)
		{
			// 次のシーンへ
			sceneNo = 1;
		}
		break;

	case 1: // NewGameScene
		DrawBox(0, 0, 600, 400, GetColor(95, 75, 139), true);
		if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0)
		{
			// 次のシーンへ
			sceneNo = 2;
		}
		break;

	case 2: // GamePlayScene
		DrawBox(0, 0, 600, 400, GetColor(169, 183, 53), true);
		if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0)
		{
			// 次のシーンへ
			sceneNo = 3;
		}
		break;

	case 3: // GameClearScene
		DrawBox(0, 0, 600, 400, GetColor(76, 108, 179), true);
		if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0)
		{
			// 最初のシーンへ
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
