#pragma once
#include <memory>
#include"Scene.h"
/// <summary>
/// タイトルシーン、プレイシーン、リザルトシーンの初期化、更新、描画を行うクラス
/// </summary>
class SceneManager
{
public:
	SceneManager() = default;
	~SceneManager() = default;
	void Initialize();
	void Update();
	void Draw()const;
	void Finalize();
private:
	void ChangeScene(SceneState nextScene);
	std::unique_ptr<Scene> currentScene_;
};

