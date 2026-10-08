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
	player_->SetStage(stage_.get());
	enemies_.push_back(std::make_unique<Enemy>());
	for(auto& e : enemies_)
	{
		e->Initialize();
	}
	stage_->SetPlayer(player_.get());
	for(auto& enemy : enemies_)
	{
		stage_->AddEnemy(enemy.get());
	}
}

void PlayScene::Update()
{
	
	player_->Update();
	for (auto& e : enemies_) {
		e->Update();
	}
	if (Input::IsKeyDown(KEY_INPUT_R)) {
		RequestChangeScene(SceneState::Result);
	}
	stage_->Update();
}

void PlayScene::Draw()
{
	
	player_->Draw();
	for (auto& e : enemies_) {
		e->Draw();
	}
	DrawString(WIN_WIDTH / 2, WIN_HEIGHT / 2, "PLAY SCENE", GetColor(255, 255, 0));
	DrawString(WIN_WIDTH / 2, WIN_HEIGHT / 2 + 40, "PUSH R TO RESULT", GetColor(255, 255, 255));
	stage_->Draw();
}

Player* PlayScene::FindPlayer() const
{
	return player_.get();
}
const std::vector<std::unique_ptr<Enemy>>& PlayScene::FindEnemies() const
{
	return enemies_;
}