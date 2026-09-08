#include "PlayScene.h"
#include"Player.h"
PlayScene::PlayScene()
{
}

PlayScene::~PlayScene()
{
}

void PlayScene::Initialize()
{
	player_ = std::make_unique<Player>();
	player_->Initialize();
}

void PlayScene::Update()
{
	player_->Update();
	if (Input::IsKeyDown(KEY_INPUT_R)) {
		RequestChangeScene(SceneState::Result);
	}
}

void PlayScene::Draw()
{
	player_->Draw();
	DrawString(WIN_WIDTH / 2, WIN_HEIGHT / 2, "PLAY SCENE", GetColor(255, 255, 0));
	DrawString(WIN_WIDTH / 2, WIN_HEIGHT / 2 + 40, "PUSH R TO RESULT", GetColor(255, 255, 255));
}
