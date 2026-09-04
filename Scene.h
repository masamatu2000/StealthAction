#pragma once
#include<Dxlib.h>
#include"globals.h"
#include"Input.h"
enum class SceneState {
	None,
	Title,
	Play,
	Result,
	Max,
};
/// <summary>
/// タイトルシーン、プレイシーン、リザルトシーンの基底クラス
/// </summary>
class Scene
{
public:
	Scene()=default;
	virtual ~Scene()=default;
	virtual void Initialize()=0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	SceneState GetNextScene() const
	{
		return nextScene_;
	}
protected:
	void RequestChangeScene(SceneState nextScene) {
		nextScene_ = nextScene;
	}
private:
	SceneState nextScene_ = SceneState::None;
};

