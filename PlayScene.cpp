#include "PlayScene.h"
#include"Player.h"
#include"Enemy.h"
#include"Stage.h"
PlayScene::PlayScene()
{
}

PlayScene::~PlayScene()
{
}

void PlayScene::Initialize()
{
	stage_ = std::make_unique<Stage>();
	stage_->Initialize();
	player_ = std::make_unique<Player>();
	player_->Initialize();
	enemies_.push_back(std::make_unique<Enemy>());
	for(auto& e : enemies_)
	{
		e->Initialize();
	}
}

void PlayScene::Update()
{
	stage_->Update();
	player_->Update();
	for (auto& e : enemies_) {
		e->Update();
	}
	if (Input::IsKeyDown(KEY_INPUT_R)) {
		RequestChangeScene(SceneState::Result);
	}
}

void PlayScene::Draw()
{
	stage_->Draw();
	player_->Draw();
	for (auto& e : enemies_) {
		e->Draw();
	}
	DrawString(WIN_WIDTH / 2, WIN_HEIGHT / 2, "PLAY SCENE", GetColor(255, 255, 0));
	DrawString(WIN_WIDTH / 2, WIN_HEIGHT / 2 + 40, "PUSH R TO RESULT", GetColor(255, 255, 255));
}
