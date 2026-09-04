#include "SceneManager.h"
#include"TitleScene.h"
#include"PlayScene.h"
#include"ResultScene.h"
void SceneManager::Initialize()
{
	currentScene_ = std::make_unique<TitleScene>();
}

void SceneManager::Update()
{
	currentScene_->Update();
	if (currentScene_->GetNextScene() != SceneState::None)
	{
		ChangeScene(currentScene_->GetNextScene());
	}
}

void SceneManager::Draw()const
{
	currentScene_->Draw();
}

void SceneManager::Finalize()
{
	currentScene_.reset();
}

void SceneManager::ChangeScene(SceneState nextScene)
{
	switch (nextScene)
	{
	case SceneState::Title:
		currentScene_.reset();
		currentScene_= std::make_unique<TitleScene>();
		break;
	case SceneState::Play:
		currentScene_.reset();
		currentScene_ = std::make_unique<PlayScene>();
		break;
	case SceneState::Result:
		currentScene_.reset();
		currentScene_ = std::make_unique<ResultScene>();
		break;
	case SceneState::None:
		return;
	default:
		break;
	}
	currentScene_->Initialize();
}
