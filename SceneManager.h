#pragma once
class SceneManager
{
public:
	/// <summary>
	/// シーンを切り替える関数
	/// </summary>
	/// <param name="sceneNo">次のシーン番号</param>
	void ChangeScene(int& sceneNo);

	// シングルトン
	static SceneManager* GetInstance();

private:
	///// <summary>
	///// シーン名
	///// </summary>
	//enum class Scene
	//{
	//	TitleScene,
	//	NewGameScene,
	//	GamePlayScene,
	//	GameClearScene,
	//};

	//// 最初のシーンを設定
	//Scene scene = Scene::TitleScene;
	int number = 0;
private:
	SceneManager() = default;
	~SceneManager() = default;
	SceneManager(const SceneManager&) = delete;
	const SceneManager& operator = (const SceneManager&) = delete;
};

